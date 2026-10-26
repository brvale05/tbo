#ifndef ITEM_H
#define ITEM_H

#define N 200

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B)  \
    {               \
        Item t = A; \
        A = B;      \
        B = t;      \
    }
#define compexch(A, B) \
    if (less(B, A))    \
    exch(A, B)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void sort(Item *a, int lo, int hi);

void imprime_array(Item *array)
{
    for (size_t i = 0; i < N; i++)
    {
        printf("%d\n", array[i]);
    }
}

void executa_programa(void (*sort_fp)(Item *, int, int))
{
    Item *array = malloc(sizeof(Item) * N);

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % N;
    }

    sort_fp(array, 0, N - 1);

    imprime_array(array);

    free(array);
}

#endif