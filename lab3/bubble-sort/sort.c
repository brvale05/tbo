#include "../item.h"

extern void sort(Item *a, int lo, int hi)
{
    for (int i = lo; i < hi; i++)
    {
        for(int j = i + 1; j < hi; j++)
        {
            compexch(a[i], a[j]);
        }
    }
    
}

int main()
{
    Item *array = malloc(sizeof(Item) * N);

    srand(time(NULL));

    for (size_t i = 0; i < N; i++)
    {
        array[i] = rand() % 20;
    }

    sort(array, 0, N);

    for (size_t i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}