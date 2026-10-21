#ifndef ITEM_H
#define ITEM_H

#define N 100000

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void sort(Item *a, int lo, int hi);

void executa_programa(void (*sort_fp)(Item*, int, int))
{
    Item *array = malloc(sizeof(Item) * N);

    int num;
    int i = 0;

    while (scanf("%d", &num) == 1)
    {
        array[i] = num;
        i++;
    }
    
    sort_fp(array, 0, N - 1);

    for (size_t i = 0; i < N; i++)
    {
        printf("%d\n", array[i]);
    }
    

    free(array);
}

#endif