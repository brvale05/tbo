#include <stdio.h>
#include <stdlib.h>

#include "../item.h"
#include "stack.h"

Stack *s;

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
    push2(s, lo, hi);

    while (!is_empty(s))
    {
        lo = pop(s);
        hi = pop(s);

        if(hi <= lo)
        {
            continue;
        }

        int pivot = partition(array, lo, hi);

        // If left side is bigger than right side, push the larger one first
        if(pivot - lo > hi - pivot)
        {
            push2(s, lo, pivot - 1);
            push2(s, pivot + 1, hi);
        }
        else
        {
            push2(s, pivot + 1, hi);
            push2(s, lo, pivot - 1);            
        }
    }
    
}

extern void sort(Item *a, int lo, int hi)
{
    s = init();
    quicksort(a, lo, hi);
}

int main()
{
    executa_programa(sort);
}