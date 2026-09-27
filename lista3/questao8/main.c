#include <stdio.h>
#include <stdlib.h>

int *bottom_up(int N)
{
    int *Cn = malloc((sizeof(int) * N) + 1);

    int incremento = 1;
    int soma = 0;

    Cn[0] = 1;

    while (1)
    {        
        soma = 0;

        for (size_t k = 1; k <= incremento; k++)
        {
            soma += Cn[k - 1] + Cn[incremento - k];
        }

        printf("SOMA = %d\n", soma);

        Cn[incremento] = incremento + (((float)1/incremento) * soma);        

        printf("C:%d = %d\n", incremento, Cn[incremento]);

        if(incremento == N)
        {
            break;
        }

        incremento++;
    }
    
    return Cn;
    
}

int main(int argc, char **argv)
{
    int N = 3;

    int *Cn = bottom_up(N);

    free(Cn);

    return 0;
}