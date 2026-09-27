#include "../../utils/utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

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
int nums[2];

// 2 0 4 3 5 1 5 9 5 8 

int main(int argc, char **argv)
{
    srand(time(NULL));

    int *array = malloc(sizeof(int) * MAX_SIZE);

    array_init(array, MAX_SIZE);
    array_print(array, MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = i + 1; j < MAX_SIZE; j++)
        {
            int diff = abs(array[i] - array[j]);            

            if(!i)
            {
                menor = diff;
            }
            else if(diff < menor)
            {
                menor = diff;
                nums[0] = array[i];
                nums[1] = array[j];
            }
        }
        
    }

    printf("%d - %d = %d", nums[0], nums[1], menor);
    free(array);

    return 0;
}