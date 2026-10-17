#ifndef ITEM_H
#define ITEM_H

#define N 20

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void sort(Item *a, int lo, int hi);

#endif