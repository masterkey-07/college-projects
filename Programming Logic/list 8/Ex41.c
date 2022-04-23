#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct Employee
{
    char name[30];
    int rg;
    double salary;
    int age;
    struct Date birthDate;
    char sex;
};

struct Employee readEmployee()
{
    struct Employee employee;

    scanf("%s %d %lf %d %c %d %d %d", &employee.name, &employee.rg, &employee.salary, &employee.age, &employee.sex, &employee.birthDate.day, &employee.birthDate.month, &employee.birthDate.year);

    return employee;
}

int readDouble()
{
    double d;

    scanf("%lf", &d);

    return d;
}

int readInt()
{
    int n;

    scanf("%d", &n);

    return n;
}

void printEmployee(struct Employee employee)
{
    printf("Nome: %s\nRG: %d\nSalário: %lf\nIdade: %d\nSexo: %c\nData de nascimento: %d/%d/%d\n", employee.name, employee.rg, employee.salary, employee.age, employee.sex, employee.birthDate.day, employee.birthDate.month, employee.birthDate.year);
}

int main()
{
    int n = readInt(), i, count = 0;

    struct Employee employees[n];

    for (i = 0; i < n; i++)
        employees[i] = readEmployee();

    double v1, v2, sum = 0;

    v1 = readDouble();

    v2 = readDouble();

    for (i = 0; i < n; i++)
        if (employees[i].salary >= v1 && employees[i].salary <= v2)
        {
            printEmployee(employees[i]);
            sum += employees[i].salary;
            count++;
        }

    printf("Média dos salários: %lf", sum / (double)count);

    return 0;
}
