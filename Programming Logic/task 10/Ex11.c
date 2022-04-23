#include <stdio.h>

int getNotes(int *note, int noteType)
{
    int result = *note / noteType;

    *note %= noteType;

    return result;
}

int main()
{
    int note;

    scanf("%d", &note);

    printf("%d ",  getNotes(&note, 100));

    printf("%d ",  getNotes(&note, 50));

    printf("%d ",  getNotes(&note, 20));
    
    printf("%d ",  getNotes(&note, 10));
    
    printf("%d ",  getNotes(&note, 5));
    
    printf("%d ",  getNotes(&note, 2));
    
    printf("%d",  getNotes(&note, 1));

    return 0;
}
