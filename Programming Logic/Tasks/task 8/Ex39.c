#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mesa[8][8], i, j, pecasPodemComer[12][2], pecasPodemMover[12][2], pecasImoveis[12][2];
    int contador1 = 0, contador2 = 0, contador3 = 0, k;

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
            if (i == 8)
            {
                pecasImoveis[contador1][0] = i;
                pecasImoveis[contador1][1] = j;
                contador1++;
            }
            else if (j == 0 || j == 7)
            {
                if (j == 0)
                    k = 1;
                else
                    k = -1;

                if (mesa[i + 1][j + k] == 0)
                {
                    pecasPodemMover[contador2][0] = i;
                    pecasPodemMover[contador2][1] = j;
                    contador2++;
                }
                else if (mesa[i + 1][j + k] == 1 && mesa[i + 2][j + (2 * k)] == 0)
                {
                    pecasPodemComer[contador3][0] = i;
                    pecasPodemComer[contador3][1] = j;
                    contador3++;
                }
                else
                {
                    pecasImoveis[contador1][0] = i;
                    pecasImoveis[contador1][1] = j;
                    contador1++;
                }
            }
            else if (1 == 1)
            {
                if (mesa[i + 1][j + 1] == 0)
                {
                    pecasPodemMover[contador2][0] = i;
                    pecasPodemMover[contador2][1] = j;
                    contador2++;
                }
                else if (mesa[i + 1][j + k] == 1 && mesa[i + 2][j + (2 * k)] == 0)
                {
                    pecasPodemComer[contador3][0] = i;
                    pecasPodemComer[contador3][1] = j;
                    contador3++;
                }
                else
                {
                    pecasImoveis[contador1][0] = i;
                    pecasImoveis[contador1][1] = j;
                    contador1++;
                }
            }
        }
    }

    return 0;
}
