#include "../item.h"

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
        else if(right > high)
        {
            a[k] = aux[left++];            
        }
        else if(less(aux[right], aux[left]))
        {
            a[k] = aux[right++];            
        }
        else
        {
            a[k] = aux[left++];            
        }
        
    }
}

void merge_sort(Item *a, Item *aux, int low, int high)
{
    if (high <= low)
    {
        return;
    }

    int mid = low + (high - low) / 2;

    // LEFT
    merge_sort(a, aux, low, mid);

    // RIGHT
    merge_sort(a, aux, mid + 1, high);

    merge(a, aux, low, mid, high);
}

extern void sort(Item *a, int lo, int hi)
{
    int n = (hi - lo) + 1;

    Item *aux = malloc(sizeof(Item) * n);

    merge_sort(a, aux, lo, hi);
}

int main()
{
    executa_programa(sort);

    return 0;
}