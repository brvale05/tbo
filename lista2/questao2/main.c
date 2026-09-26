#include "../../utils/utils.h"
#include "../../binary-search/binary_search.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 8

#define MIN -MAX_SIZE
#define MAX MAX_SIZE

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
        array[i] = MIN + (rand() % (MAX - MIN + 1));
    }

}

int main(int argc, char **argv)
{
    srand(time(NULL));

    int *array = malloc(sizeof(int) * MAX_SIZE);

    array_init(array, MAX_SIZE);
    qsort(array, MAX_SIZE, sizeof(int), compare_int);

    array_print(array, MAX_SIZE);

    int count = 0;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = i + 1; j < MAX_SIZE; j++)
        {
            for (int k = j + 1; k < MAX_SIZE; k++)
            {
                int key = -(array[i] + array[j] + array[k]);                      

                if (key <= array[k]) // Evita repetição
                    continue;

                if(binary_search(array, MAX_SIZE, key) != -1)
                {
                    count++;
                }
            }
        }
    }

    free(array);

    printf("%d ", count);

    return 0;
}