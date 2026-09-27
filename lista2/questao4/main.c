#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000000

void array_print(int *array, int tam)
{
    for (size_t i = 0; i < tam; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

void array_init(int *array, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    { 
        array[i] = rand() % tam;
    }

}

int menor = 0;
int maior = 0;

int main(int argc, char **argv)
{
    srand(time(NULL));

    int *array = malloc(sizeof(int) * MAX_SIZE);

    array_init(array, MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        int num = array[i];

        if(!i)
        {
            maior = num;
            menor = num;
        } else if(num < menor)
        {
            menor = num;
        }

        if(num > maior)
        {
            maior = num;
        }
    }

    printf("%d - %d = %d", maior, menor, abs(maior - menor));

    free(array);

    return 0;
}