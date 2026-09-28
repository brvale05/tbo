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

        Cn[incremento] = incremento + (((float)1/incremento) * soma);        

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
    int N = atoi(argv[1]);

    int *Cn = bottom_up(N);

    printf("C:%d = %d\n", N, Cn[N]);

    free(Cn);

    return 0;
}