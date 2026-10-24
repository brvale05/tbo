#include "../item.h"

void merge(Item *a, Item *aux, int low, int high, int mid)
{
    for(int k = 0; k <= high; k++)
    {
        aux[k] = a[k];        
    }

    int left = low;
    int right = mid + 1;

    for(int k = low; k <= high; k++)
    {
        if(left > mid)
        {
            a[k] = aux[right++];            
        } 
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

void merge_sort_top_down(Item *a, Item *aux, int low, int high)
{
    if(high <= low)
    {
        return;
    }

    int mid = low + (high - low) / 2;

    // LEFT
    merge_sort_top_down(a, aux, low, mid);

    // RIGHT
    merge_sort_top_down(a, aux, mid + 1, high);

    merge(a, aux, low, high, mid);
}

void merge_sort_bottom_up(Item *a, int low, int high)
{
    int n = (high - low) + 1;

    Item *aux = malloc(sizeof(Item) * n);

    int last_index = n - 1;

    for(int sz = 1; sz < n; sz *= 2)
    {
        for(int lo = 0; lo < n - sz; lo += sz * 2)
        {
            // Final do bloco da esquerda
            int mid = lo + sz - 1;

            // Final do bloco da direita            
            int hi = lo + (sz * 2) - 1;

            if (hi > last_index)
            {
                hi = last_index;
            }

            merge(a, aux, lo, hi, mid);
        }
    }
}

extern void sort(Item *a, int low, int high)
{
    merge_sort_bottom_up(a, low, high);
}

extern void sort_bottom_up(Item *a, int low, int high)
{
    int n = (high - low) + 1;

    Item *aux = malloc(sizeof(Item) * n);

    merge_sort_top_down(a, aux, low, high);
}

int main()
{
    executa_programa(sort);        
    executa_programa(sort_bottom_up);        

    return 0;
}