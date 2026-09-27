#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#define MAX_SIZE 20

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
        array[i] = rand() % 1000;
    }

}

int find_max(int *array, int maior, int index, int size)
{
    if(index >= size)
    {        
        return maior;
    }

    if(array[index] > maior)
    {
        maior = array[index];
    }

    return find_max(array, maior, index + 1, size);
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    int *array = malloc(sizeof(int) * MAX_SIZE);

    array_init(array, MAX_SIZE);
    array_print(array, MAX_SIZE);

    int maior = find_max(array, array[0], 0, MAX_SIZE);

    printf("%d ", maior);

    return 0;
}