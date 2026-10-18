#include "../item.h"

extern void sort(Item *a, int lo, int hi)
{
    int h = 1;
    while (h < (hi - lo) / 9)
    {
        h = 3 * h + 1;
    }

    int j;

    while (h > 0)
    {
        for (int i = lo + h; i < hi; i++)
        {

            Item suposto_menor_valor = a[i];

            for (j = i; j >= lo + h && less(suposto_menor_valor, a[j - h]); j = j - h)
            {
                a[j] = a[j - h]; // Troca o maior valor pelo menor, que seria o suposto_menor_valor
            }
            
            a[j] = suposto_menor_valor; // O valor mais a esquerda recebe o suposto_menor_valor, que nesse caso seria realmente o menor valor

        }
        
        h = h / 3;

    }
    
}

int main()
{
    Item *array = malloc(sizeof(Item) * N);

    srand(time(NULL));

    for (size_t i = 0; i < N; i++)
    {
        array[i] = rand() % 20;
    }

    sort(array, 0, N);

    for (size_t i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}