#include "../item.h"

int partition(Item *a, int lo, int hi)
{
    int i = lo;
    int j = hi + 1;

    Item pivot = a[lo];

    while (1)
    {
        while (less(a[++i], pivot))
            ;

        while (less(pivot, a[--j]))
            ;

        if (i >= j)
            break;

        exch(a[i], a[j]);
    }

    exch(a[lo], a[j]);

    return j;
}

void quicksort(Item *a, int lo, int hi)
{
    if (hi <= lo)
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
    int max = lo;

    // 1. Encontra o índice do maior elemento no vetor inteiro
    for (int i = lo + 1; i <= hi; i++)
    {
        if (less(a[max], a[i]))
        {
            max = i;
        }
    }

    exch(a[max], a[hi]);

    quicksort(a, lo, hi);
}

int main()
{
    executa_programa(sort);
    return 0;
}