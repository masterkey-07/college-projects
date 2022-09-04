#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mesa[8][8], i, j, k, peca1, peca2, peca3, peca4;
    int pecasMovem[12][2], pecasComem[12][2], pecasParadas[12][2];
    int contador1 = 0, contador2 = 0, contador3 = 0;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            scanf("%d", &mesa[i][j]);
        }
    }

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (mesa[i][j] == -1)
            {
                peca1 = mesa[i + 1][j + 1];
                peca2 = mesa[i + 2][j + 2];
                peca3 = mesa[i + 1][j - 1];
                peca4 = mesa[i + 2][j - 2];

                if (i == 7)
                {
                    pecasParadas[contador1][0] = i;
                    pecasParadas[contador1][1] = j;
                    contador1++;
                }
                else if (i == 6)
                {
                    if (peca1 == 0 || peca3 == 0)
                    {
                        pecasMovem[contador2][0] = i;
                        pecasMovem[contador2][1] = j;
                        contador2++;
                    }
                }
                else if (j == 7)
                {
                    if (peca3 == 1 && peca4 == 1)
                    {
                        pecasParadas[contador1][0] = i;
                        pecasParadas[contador1][1] = j;
                        contador1++;
                    }
                    else if (peca3 == 1 && peca4 == 0)
                    {
                        pecasComem[contador3][0] = i;
                        pecasComem[contador3][1] = j;
                        contador3++;
                    }
                    if (peca3 == 0 && peca4 == 1)
                    {
                        pecasMovem[contador2][0] = i;
                        pecasMovem[contador2][1] = j;
                        contador2++;
                    }
                }
                else if (j == 0)
                {
                    if (peca1 == 1 && peca2 == 1)
                    {
                        pecasParadas[contador1][0] = i;
                        pecasParadas[contador1][1] = j;
                        contador1++;
                    }
                    else if (peca1 == 1 && peca2 == 0)
                    {
                        pecasComem[contador3][0] = i;
                        pecasComem[contador3][1] = j;
                        contador3++;
                    }
                    if (peca1 == 0 && peca2 == 1)
                    {
                        pecasMovem[contador2][0] = i;
                        pecasMovem[contador2][1] = j;
                        contador2++;
                    }
                }
                else if (j + 1 == 7)
                {
                    if (peca3 == 1 && peca4 == 1 && peca1 == 1)
                    {
                        pecasParadas[contador1][0] = i;
                        pecasParadas[contador1][1] = j;
                        contador1++;
                    }
                    else if (peca3 == 1 && peca4 == 0)
                    {
                        pecasComem[contador3][0] = i;
                        pecasComem[contador3][1] = j;
                        contador3++;
                    }
                    if ((peca3 == 0) || peca1 == 0)
                    {
                        pecasMovem[contador2][0] = i;
                        pecasMovem[contador2][1] = j;
                        contador2++;
                    }
                }
                else if (j - 1 == 0)
                {

                    if (peca1 == 1 && peca2 == 1 && peca3 == 1)
                    {
                        pecasParadas[contador1][0] = i;
                        pecasParadas[contador1][1] = j;
                        contador1++;
                    }
                    else if (peca1 == 1 && peca2 == 0)
                    {
                        pecasComem[contador3][0] = i;
                        pecasComem[contador3][1] = j;
                        contador3++;
                    }
                    if ((peca1 == 0) || peca3 == 0)
                    {
                        pecasMovem[contador2][0] = i;
                        pecasMovem[contador2][1] = j;
                        contador2++;
                    }
                }
                else
                {
                    if (peca3 == 1 && peca2 == 1 && peca1 == 1 && peca4 == 1)
                    {
                        pecasParadas[contador1][0] = i;
                        pecasParadas[contador1][1] = j;
                        contador1++;
                    }
                    else if ((peca1 == 1 && peca2 == 0) || (peca3 == 1 && peca4 == 0))
                    {
                        pecasComem[contador3][0] = i;
                        pecasComem[contador3][1] = j;
                        contador3++;
                    }
                    if ((peca1 == 0) || (peca3 == 0))
                    {
                        pecasMovem[contador2][0] = i;
                        pecasMovem[contador2][1] = j;
                        contador2++;
                    }
                }
            }
        }
    }

    printf("Podem tomar peças brancas:");

    for (i = 0; i < contador3; i++)
    {
        if (i == contador3 - 1)
            printf(" (%d,%d)\n", pecasComem[i][0], pecasComem[i][1]);
        else
            printf(" (%d,%d),", pecasComem[i][0], pecasComem[i][1]);
    }

    printf("Podem mover-se sem tomar peças:");
    for (i = 0; i < contador2; i++)
    {
        if (i == contador2 - 1)
            printf(" (%d,%d)\n", pecasMovem[i][0], pecasMovem[i][1]);
        else
            printf(" (%d,%d),", pecasMovem[i][0], pecasMovem[i][1]);
    }

    printf("Não podem se mover:");
    for (i = 0; i < contador1; i++)
    {
        if (i == contador1 - 1)
            printf(" (%d,%d)\n", pecasParadas[i][0], pecasParadas[i][1]);
        else
            printf(" (%d,%d),", pecasParadas[i][0], pecasParadas[i][1]);
    }

    return 0;
}
