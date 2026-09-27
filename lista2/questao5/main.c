#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 8

void array_print(int *array, int tam)
{
    for (size_t i = 0; i < tam; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    int array[MAX_SIZE] = {15, 9, 20, 19, 18, 5, 8, 10};

    array_print(array, MAX_SIZE);

    int low = 0;
    int high = MAX_SIZE - 1;

    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        // Verifica se o vizinho da esquerda é menor
        if(mid > 0 && array[mid] > array[mid - 1])
        {
            high = mid - 1;
        }        
        // Verifica se o vizinho da direita é menor
        else if(mid < MAX_SIZE - 1 && array[mid] > array[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            printf("%d, %d, %d", array[mid - 1], array[mid], array[mid + 1]);
            break;
        }
    }

    return 0;
}