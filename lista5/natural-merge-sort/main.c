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

    while (1)
    {
        int i = 0;
        int merges_por_iteracao = 0;

        while(i < n)
        {
            int start = i;

            int mid = start;
            while(mid < n - 1 && !less(a[mid + 1], a[mid]))
            {
                mid++;
            }

            // There is no second subvector
            if(mid == n - 1)
            {
                break;
            }

            int end = mid + 1;
            while(end < n - 1 && !less(a[end + 1], a[end]))            
            {
                end++;
            }

            merge(a, aux, start, mid, end);
            merges_por_iteracao++;

            i = end + 1;
        }

        if(!merges_por_iteracao)
        {
            break;
        }
    }

    free(aux);
}

int main()
{
    executa_programa(sort);

    return 0;
}