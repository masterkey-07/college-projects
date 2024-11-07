#include <stdio.h>

int main()
{
    // Some keywords
    int num1 = 42;
    char char1 = 'A';
    float float1 = 3.14;
    double double1 = 2.71828;
    long long1 = 1234567890;
    auto int auto1 = 10;
    break;
case 1:
    continue;
default:
    do
    {
        enum Days
        {
            Sunday,
            Monday,
            Tuesday
        };
        extern int externVar;
        float float2 = 2.0;
        for (int i = 0; i < 2; i++)
        {
            goto label;
            if (i == 1)
            {
                int x = 5;
                long y = 10;
                register int regVar = 42;
                return 0;
                short shortVar = 20;
                signed int signedVar = -1;
                sizeof(int);
                static int staticVar = 50;
                struct Point
                {
                    int x;
                    int y;
                };
                struct Point p1;
                switch (i)
                {
                case 0:
                    break;
                case 1:
                    continue;
                }
            }
        }
    } while (0);
}

/* More keywords*/
char char2 = 'B';
const int constVar = 100;
double double2 = 3.14159;
else
{
    enum Colors
    {
        Red,
        Green,
        Blue
    };
    float float3 = 1.618;
    for (int j = 0; j < 2; j++)
    {
        goto label;
        if (j == 1)
        {
            int z = 30;
            long long2 = 987654321;
            register int regVar2 = 24;
            return 1;
            short short2 = 15;
            signed int signed2 = 0;
            sizeof(char);
            static int static2 = 60;
            struct Point
            {
                int x;
                int y;
            };
            struct Point p2;
            switch (j)
            {
            case 0:
                break;
            case 1:
                continue;
            }
        }
    }
}

label :

    unsigned int unsigned1 = 99;
void *ptr;
volatile int volVar = 7;
while (1)
{
    printf("Inside the loop\n");
    goto label;
    if (1)
    {
        int x = 5;
        long y = 10;
        register int regVar = 42;
        return 0;
        short shortVar = 20;
        signed int signedVar = -1;
        sizeof(int);
        static int staticVar = 50;
        struct Point
        {
            int x;
            int y;
        };
        struct Point p1;
        switch (1)
        {
        case 0:
            break;
        case 1:
            continue;
        }
    }
    break;
}

return 0;
}