#include "../item.h"

extern void sort(Item *a, int lo, int hi)
{
    for (int i = 0; i < hi / 2; i++)
    {
        int swapped = 0;

        // First phase: the lightest bubble ascends to the right
        for (int j = i; j < hi - 1 - i; j++)
        {
            if (less(a[j], a[j + 1]))
            {
                exch(a[j], a[j + 1]);
                swapped = 1;
            }
        }

        // Second phase: the heaviest bubble descends to the left
        for (int j = hi - 2 - i; j > lo; j--)
        {
            if (less(a[j - 1], a[j]))
            {
                exch(a[j], a[j - 1]);
                swapped = 1;
            }
        }

        if(!swapped)
        {
            break;
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