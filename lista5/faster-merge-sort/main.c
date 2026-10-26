#include "../item.h"

void merge(Item *a, Item *aux, int low, int high, int mid)
{
    for (int k = 0; k <= mid; k++)
    {
        aux[k] = a[k];
    }

    for (int k = mid + 1; k <= high; k++)
    {
        aux[high - k + mid + 1] = a[k];
    }

    int left = low;
    int right = high;

    for (int k = low; k <= high; k++)
    {
        if (less(aux[right], aux[left]))
        {
            a[k] = aux[right--];
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

    merge(a, aux, low, high, mid);
}

extern void sort(Item *a, int low, int high)
{
    int n = (high - low) + 1;

    Item *aux = malloc(sizeof(Item) * n);

    merge_sort(a, aux, low, high);
}

int main()
{
    executa_programa(sort);
    return 0;
}