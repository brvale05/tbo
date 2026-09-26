#include "../../utils/utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

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
    for (size_t i = 0; i < tam; i++)
    {
        array[i] = rand() % tam;
    }
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    int *array_1 = malloc(sizeof(int) * MAX_SIZE);
    int *array_2 = malloc(sizeof(int) * MAX_SIZE);

    array_init(array_1, MAX_SIZE);
    array_init(array_2, MAX_SIZE);

    qsort(array_1, MAX_SIZE, sizeof(int), compare_int);
    qsort(array_2, MAX_SIZE, sizeof(int), compare_int);

    int i = 0;
    int j = 0;

    while (i < MAX_SIZE && j < MAX_SIZE)
    {
        if (array_1[i] > array_2[j])
        {
            j++;
        }
        else if (array_1[i] < array_2[j])
        {
            i++;
        }
        else
        {
            printf("%d ", array_1[i]);
            i++;
            j++;
        }
    }

    free(array_1);
    free(array_2);

    return 0;
}