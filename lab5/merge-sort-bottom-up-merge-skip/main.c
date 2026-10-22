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

void merge(Item *a, Item *aux, int low, int mid, int high)
{
    for (int k = 0; k <= high; k++)
    {
        aux[k] = a[k];
    }

    int left = low;
    int right = mid + 1;

    for (int k = low; k <= high; k++)
    {
        // Ja processei a metade esquerda
        if (left > mid)
        {
            a[k] = aux[right++];
        }
        // Ja processei a metade direita
        else if (right > high)
        {
            a[k] = aux[left++];
        }
        else if (less(aux[right], aux[left]))
        {
            a[k] = aux[right++];
        }
        else
        {
            a[k] = aux[left++];
        }
    }
}

extern void sort(Item *a, int lo, int hi)
{
    int n = (hi - lo) + 1;

    Item *aux = malloc(sizeof(Item) * n);
    int last_index = n - 1;

    for (int size = 1; size < n; size *= 2)
    {
        for (int lo = 0; lo < n - size; lo += size * 2)
        {            
            int mid = lo + size - 1;
            
            if(a[mid] <= a[mid + 1])
            {
                continue;
            }

            int high = lo + (size * 2) - 1;

            if(high > last_index)
            {
                high = last_index;
            }            

            merge(a, aux, lo, mid, high);
        }
        
    }

    free(aux);
}

int main()
{
    executa_programa(sort);

    return 0;
}