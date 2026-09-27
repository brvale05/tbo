#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 12

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

    // X = 0

    // 1, 2, 4, 5, 0

    // 12 elementos
    int array[MAX_SIZE] = {1, 3, 4, 5, 6, 7, 8, 20, 18, 17, 15, 13};

    array_print(array, MAX_SIZE);

    int low = 0;
    int high = MAX_SIZE - 1;

    int x = 13;

    int encontrado = 0;

    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        int left = array[mid - 1];
        int mid_num = array[mid];
        int right = array[mid + 1];
        
        if(left > mid_num && x > mid_num)
        {
            // VOU PARA ESQUERDA
            high = mid - 1;      
            continue;      
        }

        if(left < mid_num && x > mid_num)
        {
            // VOU PARA DIREITA
            low = mid + 1;
            continue;
        }


        
    }
    
    printf("%d \n", encontrado);

    return 0;
}