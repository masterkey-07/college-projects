#include <stdio.h>
#include <string.h>

struct Adress
{
    char street[30];
    char city[30];
    char state[30];
    int cep;
};

struct Date
{
    int day;
    int month;
    int year;
};

struct Student
{
    char name[30];
    struct Date date;
    struct Adress adress;
    int rg;
    int ra;
    double cr;
};

int main()
{
    int option;

    while (1 == 1)
    {
        struct Student students[100];
        int count = 0;

        scanf("%d", &option);

        if (option == 1)
        {
            scanf("%s", &students[i].name);

            count++;
        }
        else if (option == 2)
        {
        }
        else if (option == 3)
        {
        }
        else if (option == 4)
        {
        }
        else if (option == 5)
        {
        }
        else
            return 0;
    }

    return 0;
}
