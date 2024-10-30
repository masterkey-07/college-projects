using System;
using System.IO;
using System.Text;
using System.Threading;

class CountNode(char character, int count)
{
    public int Count { get; set; } = count;
    public char Character { get; set; } = character;
    public CountNode? Next { get; set; } = null;
}

class Program
{
    // Method to append a node to the end of the linked list
    private static void AppendNode(ref CountNode? head, char character, int count)
    {
        if (head == null)
        {
            head = new CountNode(character, count);
            return;
        }

        CountNode temp = head;

        while (temp.Next != null)
            temp = temp.Next;

        if (temp.Character == character)
        {
            temp.Count += count;
            return;
        }

        temp.Next = new CountNode(character, count);
    }

    // Method to compress a segment of the input and append to a linked list
    private static void CompressSegment(char[] input, CountNode?[] partialOutputs, int start, int end, int threadIndex)
    {
        CountNode? head = null;
        int index = start;

        while (index < end)
        {

            char currentChar = input[index];
            int count = 1;

            while (index < end - 1 && input[index] == input[index + 1])
            {
                count++;
                index++;
            }

            AppendNode(ref head, currentChar, count);

            index++;
        }

        partialOutputs[threadIndex] = head;
    }

    // Main compression method
    public static CountNode? CompressRLE(char[] input, int numThreads)
    {
        int length = input.Length;

        int chunkSize = length / numThreads;

        CountNode[] partialOutputs = new CountNode[numThreads];

        Thread[] threads = new Thread[numThreads];

        // Create and start threads for parallel compression
        for (int i = 0; i < numThreads; i++)
        {
            int start = i * chunkSize;

            int end = (i == numThreads - 1) ? length : (i + 1) * chunkSize; // Handle last chunk differently

            int threadIndex = i;

            threads[i] = new Thread(() => CompressSegment(input, partialOutputs, start, end, threadIndex));

            threads[i].Start();
        }

        // Wait for all threads to complete
        foreach (var thread in threads)
        {
            thread.Join();
        }

        // Merge partial outputs
        CountNode? outputList = null;

        foreach (var partial in partialOutputs)
        {
            CountNode? current = partial;

            while (current != null)
            {

                AppendNode(ref outputList, current.Character, current.Count);

                current = current.Next;

            }
        }

        return outputList;
    }

    // Method to print the RLE result stored in a linked list
    public static void PrintRLE(CountNode head)
    {
        CountNode? current = head;
        while (current != null)
        {
            Console.Write($"{current.Character}{current.Count}");
            current = current.Next;
        }
        Console.WriteLine();
    }

    // Method to free the linked list
    public static void FreeRLEList(ref CountNode? head)
    {
        head = null;
    }

    public static void Main(string[] args)
    {
        // File reading
        string filename = "input.txt";

        if (!File.Exists(filename))
        {
            Console.WriteLine("File not found");
            return;
        }

        string inputContent = File.ReadAllText(filename);

        char[] input = inputContent.ToCharArray();

        // Set number of threads
        int numThreads = 4;

        // Compress the input using RLE
        CountNode? outputList = CompressRLE(input, numThreads);

        if (outputList != null)
            // Print compressed output
            PrintRLE(outputList);

        // Free memory
        FreeRLEList(ref outputList);
    }
}
