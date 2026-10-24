#include "../item.h"
void merge3(Item *a, Item *aux, int lo, int mid1, int mid2, int hi)
{
    for (int k = lo; k <= hi; k++)
    {
        aux[k] = a[k];
    }

    int i = lo;       
    int j = mid1 + 1; 
    int k = mid2 + 1; 

    for (int l = lo; l <= hi; l++)
    {
        if (i > mid1)
        {
            if (j > mid2)
            {
                a[l] = aux[k++];
            } 
            else if (k > hi)
            {
                a[l] = aux[j++];
            }
            else if (less(aux[j], aux[k]))
            {
                a[l] = aux[j++];
            } 
            else
            {
                a[l] = aux[k++];
            }
        }
        else if (j > mid2)
        {
            if (k > hi)
            {
                a[l] = aux[i++];
            } 
            else if (less(aux[i], aux[k]))
            {
                a[l] = aux[i++];
            } 
            else
            {
                a[l] = aux[k++];
            }
        }
        else if (k > hi)
        {
            if (less(aux[i], aux[j]))
            {
                a[l] = aux[i++];
            }
            else
            {
                a[l] = aux[j++];
            }
        }
        else
        {
            if (less(aux[i], aux[j]))
            {
                if (less(aux[i], aux[k]))
                {
                    a[l] = aux[i++];
                }
                else
                {
                    a[l] = aux[k++];
                }
            }
            else
            {
                if (less(aux[j], aux[k]))
                {
                    a[l] = aux[j++];
                }
                else
                {
                    a[l] = aux[k++];
                }
            }
        }
    }
}
void merge_sort(Item *a, Item *aux, int lo, int hi)
{
    if (hi <= lo)
    {
        return;
    }
    
    int mid1 = lo + ((hi - lo) / 3);
    int mid2 = lo + 2 * ((hi - lo) / 3) + 1;
    
    if (mid2 > hi)
    {
        mid2 = hi;
    }
    
    merge_sort(a, aux, lo, mid1);
    merge_sort(a, aux, mid1 + 1, mid2);
    merge_sort(a, aux, mid2 + 1, hi);
    
    merge3(a, aux, lo, mid1, mid2, hi);
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