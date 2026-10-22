#include <stdio.h>
#include <stdlib.h>

#include "../item.h"

#define CUTOFF 10

void insertion_sort(Item *a, int low, int high)
{
    for (int i = 0; i <= high; i++)
    {
        for (int j = i; j > low; j--)
        {
            compexch(a[j - 1], a[j]);
        }
        
    }
    
}

int partition(Item *a, int low, int high)
{
    int i = low;
    int j = high + 1;

    Item pivot = a[low];

    while (1)
    {
        while (less(a[++i], pivot))
            if (i >= high)
                break;

        while (less(pivot, a[--j]))
            if (j <= low)
                break;

        // SE CRUZARAM
        if (i >= j)
            break;

        exch(a[i], a[j]);
    }

    exch(a[low], a[j]);

    return j;
}

void quicksort(Item *array, int lo, int hi)
{
    if(hi <= lo + CUTOFF + 1)
    {
        insertion_sort(array, lo, hi);
        return;
    }

    int mid = partition(array, lo, hi);

    // LEFT
    quicksort(array, lo, mid - 1);

    // RIGHT
    quicksort(array, mid + 1, hi);
}

extern void sort(Item *a, int lo, int hi)
{
    quicksort(a, lo, hi);
}

int main()
{
    executa_programa(sort);
}