#include "../item.h"

#define CUTOFF 10

void insertion_sort(Item *a, int lo, int hi)
{
    for(int i = lo; i <= hi; i++)
    {
        for(int j = i; j > lo; j--)
        {
            compexch(a[j - 1], a[j]);
        }
    }
}

int partition(Item *a, int lo, int hi)
{
    int i = lo;
    int j = hi + 1;

    Item pivot = a[lo];

    while (1)
    {
        while (less(a[++i], pivot))
        {
            if(i >= hi)
            {
                break;
            }
        }            

        while (less(pivot, a[--j]))
        {
            if(j <= lo)
            {
                break;
            }
        }            

        if (i >= j)
            break;

        exch(a[i], a[j]);
    }

    exch(a[lo], a[j]);

    return j;
}

void quicksort(Item *a, int lo, int hi)
{
    if (hi - lo + 1 <= CUTOFF)
    {
        return;
    }

    int pivot = partition(a, lo, hi);

    // LEFT
    quicksort(a, lo, pivot - 1);

    // RIGHT
    quicksort(a, pivot + 1, hi);
}

extern void sort(Item *a, int lo, int hi)
{
    quicksort(a, lo, hi);

    insertion_sort(a, lo, hi);
}

int main()
{
    executa_programa(sort);
    return 0;
}