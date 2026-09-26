#include "binary_search.h"

int binary_search(int *array, int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        if (key < array[mid])
        {
            high = mid - 1;
        }
        else if(key > array[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
        
    }

    return -1;
    
}