#ifndef PQ_H
#define PQ_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../item.h"

// Creates an empty priority queue that holds at most `capacity` items.
// The internal heap uses positions 1 through `capacity`; position 0 is unused.
void PQ_init(int capacity);

// Releases the storage allocated by PQ_init.
void PQ_destroy(void);

void PQ_insert(Item v); // Inserts an item in the priority queue.

// Removes and returns the largest item.
Item PQ_delmax(); // Dual op delmin also possible.

Item PQ_max();    // Returns the largest item. Dual: min.

bool PQ_empty();  // Tests if the queue is empty.

void fix_up(Item *a, int k);

void fix_down(Item *a, int sz, int k);

void imprime_array(Item *array);

void executa_programa(void (*sort_fp)(Item *, int, int));

#endif
