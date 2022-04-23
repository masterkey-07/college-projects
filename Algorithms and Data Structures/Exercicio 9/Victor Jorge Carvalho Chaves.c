/*
Nome: Victor Jorge Carvalho Chaves
RA: 156.174
Turma: NB
*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura do estudante para armazenar os dados do aluno
typedef struct Student
{
    int ra;
    char *name;
    double averageGrade;
} TStudent;

typedef TStudent *PStudent;

// Estrutura da arvore binária
typedef struct Node
{
    PStudent student;
    struct Node *leftTree;
    struct Node *rightTree;

} TTree;

typedef TTree *PTree;

// Alocar memoria da arvore binaria
PTree allocateTreeMemory()
{
    return (PTree)malloc(sizeof(TTree));
}

// Alocar memoria da estrutura estudante
PTree allocateStudentMemory()
{
    return (PStudent)malloc(sizeof(TStudent));
}

// Insere uma nova arvore na arvore binaria junto com os dados do aluno
PTree insertTree(PTree tree, PStudent student)
{
    PTree newTree;

    PStudent otherStudent;

    // Retorna uma arvore sem filhos se não houver uma arvore existente
    if (tree == NULL)
    {
        newTree = allocateTreeMemory();
        newTree->student = student;
        newTree->leftTree = NULL;
        newTree->rightTree = NULL;
        return newTree;
    }

    // Retorna uma arvore com novo filho se houver uma arvore existente
    else
    {
        otherStudent = tree->student;

        if (student->ra < otherStudent->ra)
            tree->leftTree = insertTree(tree->leftTree, student);
        else
            tree->rightTree = insertTree(tree->rightTree, student);
    }

    return tree;
}

// Procura na arvore binaria o aluno pelo ra dele
PTree findStudentByRA(PTree tree, int ra)
{
    PStudent student;

    if (tree == NULL)
        return NULL;

    student = tree->student;

    // Entra numa recursividade até encontrar o aluno
    if (student->ra < ra)
        return findStudentByRA(tree->rightTree, ra);
    else if (student->ra > ra)
        return findStudentByRA(tree->leftTree, ra);
    else
        return tree->student;
}

// Pede para o usuario digitar os dados do aluno e retornar uma estrutura
PStudent readStudent(PTree tree)
{
    PStudent student = allocateStudentMemory(), otherStudent;

    int loop = 0;

    double gradeA, gradeB, gradeC;

    student->name = (char *)malloc(sizeof(char) * 50);

    while (loop == 0)
    {
        loop = 1;

        printf("\n Digite o RA do estudante : ");
        scanf("%d", &student->ra);

        otherStudent = findStudentByRA(tree, student->ra);

        if (otherStudent != NULL)
        {
            loop = 0;
            printf("\ndigitou uma ra ja existente, tente novamente.\n");
        }
    }

    printf("\n Digite o nome do estudante : ");
    scanf("%s", student->name);
    printf("\n Digite a nota 1 do estudante : ");
    scanf("%lf", &gradeA);
    printf("\n Digite a nota 2 do estudante : ");
    scanf("%lf", &gradeB);
    printf("\n Digite a nota 3 do estudante : ");
    scanf("%lf", &gradeC);

    student->averageGrade = (gradeA + gradeB + gradeC) / 3.0;

    return student;
}

// Printa a arvore em uma forma horizontal
void printTree(PTree tree, int level)
{
    PStudent student;
    int i;

    // Entra em uma recursividade até printar todos os dados
    if (tree != NULL)
    {
        student = tree->student;

        printTree(tree->leftTree, level + 1);
        for (i = 0; i < level; i++)
            printf("\t");
        printf("%d\n", student->ra);
        printTree(tree->rightTree, level + 1);
    }
}

// Printa a estrutura do estudante
void printStudent(PStudent student)
{
    printf("\nNome: %s\n", student->name);
    printf("RA: %d\n", student->ra);
    printf("Media: %.2f\n", student->averageGrade);
}

//  Printa os alunos com a nota abaixo da media (6.0)
void printLowStudent(PTree tree)
{
    PStudent student;

    // Entra em uma recursividade até printar todos os dados
    if (tree != NULL)
    {
        student = tree->student;

        if (student->averageGrade < 6.0)
            printStudent(student);
        printLowStudent(tree->leftTree);
        printLowStudent(tree->rightTree);
    }
}

//  Printa o menu de opções e lê e retorna a resposta do usuario
int printMenu()
{
    int output;

    printf("\n1) Inserir um aluno na arvore;\n");
    printf("2) Imprimir a arvore atual;\n");
    printf("3) Mostrar os dados dos alunos que foram reprovados;\n");
    printf("4) Excluir da arvore todos os alunos que foram reprovados;\n");
    printf("5) Mostrar todos os alunos com chave menor ou igual a um dado RA;\n");
    printf("6) Iniciar uma nova arvore;\n");
    printf("7) Sair.\n");

    printf("\nDigite a opcao a ser efetuda : ");
    scanf("%d", &output);

    return output;
}

// Libera todo o espaço da arvore binaria
void freeTree(PTree tree)
{
    if (tree != NULL)
    {
        freeTree(tree->leftTree);
        freeTree(tree->rightTree);
        free(tree->student);
        free(tree);
    }
}

// Printa todo os estudantes com o ra igual ou menor que o usuario mandar
void printStudentsByRA(PTree tree, int ra)
{
    PStudent student;
    PTree otherTree;
    if (tree != NULL)
    {
        student = tree->student;

        // Entra em uma recursividade até printar todos os dados
        if (student->ra > ra)
            printStudentsByRA(tree->leftTree, ra);
        else
        {
            printStudent(student);
            printStudentsByRA(tree->leftTree, ra);
            printStudentsByRA(tree->rightTree, ra);
        }
    }
}

// Remove todos os alunos com a media abaixo da nota
PTree removeLowStudent(PTree tree)
{
    PStudent student;

    PTree child, father;

    if (tree == NULL)
        return NULL;

    // Entra em uma recursividade até remover todos os alunos com nota abaixo da media
    tree->leftTree = removeLowStudent(tree->leftTree);
    tree->rightTree = removeLowStudent(tree->rightTree);

    student = tree->student;

    // Se o aluno estiver abaixo da media
    if (student->averageGrade < 6.0)
    {
        // Remova a arvore se ela for uma folha
        if (tree->leftTree == NULL && tree->rightTree == NULL)
        {
            free(tree);
            tree = NULL;
        }
        // Substitua a arvore pelo filho direito
        else if (tree->leftTree == NULL)
        {
            child = tree;
            tree = tree->rightTree;
            free(child);
        }
        // Substitua a arvore pelo filho esquerdo
        else if (tree->rightTree == NULL)
        {
            child = tree;
            tree = tree->leftTree;
            free(child);
        }
        // Entra em um looping para substituir da melhor maneira a arvore a ser removida se ela tiver ambos os filhos
        else
        {
            father = tree;
            child = tree->leftTree;

            while (child->rightTree != NULL)
            {
                father = child;
                child = child->rightTree;
            }

            tree->student = child->student;

            if (father == tree)
                father->leftTree = child->leftTree;
            else
                father->rightTree = child->leftTree;

            free(child);
        }
    }

    return tree;
}

int main()
{
    int answer = 0, ra;
    PStudent student;
    PTree tree = NULL;

    while (answer != 7)
    {
        answer = printMenu();

        if (answer == 1)
        {
            student = readStudent(tree);

            tree = insertTree(tree, student);
        }
        else if (answer == 2)
            printTree(tree, 0);
        else if (answer == 3)
            printLowStudent(tree);
        else if (answer == 4)
        {
            tree = removeLowStudent(tree);
        }
        else if (answer == 5)
        {
            printf("Digite o ra para filtrar os estudantes.");
            scanf("%d", &ra);
            printStudentsByRA(tree, ra);
        }
        else if (answer == 6)
        {
            freeTree(tree);
            tree = NULL;
        }
        else if (answer == 7)
            printf("Fim do programa.");
    }

    return 0;
}
