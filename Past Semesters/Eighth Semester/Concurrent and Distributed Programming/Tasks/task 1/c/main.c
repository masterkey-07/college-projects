#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>

// Structure to represent each character and its count in the linked list
typedef struct CountNode
{
    int count;
    char character;
    struct CountNode *next;
} CountNode;

// Function to create a new node for the linked list
CountNode *create_node(char character, int count)
{
    CountNode *new_node = (CountNode *)malloc(sizeof(CountNode));

    new_node->character = character;
    new_node->count = count;
    new_node->next = NULL;

    return new_node;
}

// Function to append a node to the end of the linked list
void append_node(CountNode **head, char character, int count)
{
    CountNode *new_node = create_node(character, count);

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    CountNode *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->character == new_node->character)
    {
        temp->count += new_node->count;

        free(new_node);

        return;
    }

    temp->next = new_node;
}

// Function to compress the input using RLE and store results in a linked list
void compress_rle(const char *input, CountNode **output_list, int length, int num_threads)
{
    int chunk_size = length / num_threads;
    int i;

    // Array to store the partial outputs (linked lists) from each thread
    CountNode *partial_outputs[num_threads];

#pragma omp parallel for num_threads(num_threads)
    for (i = 0; i < num_threads; i++)
    {
        partial_outputs[i] = NULL; // Initialize each partial output linked list
        int start = i * chunk_size;
        int end = (i == num_threads - 1) ? length : (i + 1) * chunk_size; // Handle last chunk differently
        int k = start;

        while (k < end)
        {
            char current_char = input[k];
            int count = 1;

            // Compress the sequence in the current chunk
            while (k < end - 1 && input[k] == input[k + 1])
            {
                count++;
                k++;
            }

            // Append the current sequence to the thread's output linked list
            append_node(&partial_outputs[i], current_char, count);
            k++;
        }
    }

    // Merge the partial output lists into a single linked list
    for (i = 0; i < num_threads; i++)
    {
        CountNode *current = partial_outputs[i];

        while (current != NULL)
        {
            append_node(output_list, current->character, current->count);
            current = current->next;
        }
    }
}

// Function to print the RLE compression result stored in a linked list
void print_rle(CountNode *head)
{
    CountNode *current = head;
    while (current != NULL)
    {
        printf("%c%d", current->character, current->count);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory of the linked list
void free_rle_list(CountNode *head)
{
    CountNode *current = head;
    while (current != NULL)
    {
        CountNode *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    // File reading part
    const char *filename = "input.txt";
    FILE *file = fopen(filename, "rb"); // Open file for reading in binary mode
    if (file == NULL)
    {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    // Determine file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory to read the file
    char *input = malloc(file_size + 1);
    if (input == NULL)
    {
        perror("Failed to allocate memory");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Read the file into the buffer
    fread(input, 1, file_size, file);
    input[file_size] = '\0'; // Null-terminate the string
    fclose(file);

    // Set the number of threads for parallel processing
    int num_threads = 4; // You can adjust this based on your machine

    // Initialize the head of the linked list for output
    CountNode *output_list = NULL;

    // Perform the RLE compression
    compress_rle(input, &output_list, file_size, num_threads);

    // Output the compressed result
    print_rle(output_list);

    // Free allocated memory
    free(input);
    free_rle_list(output_list);

    return 0;
}