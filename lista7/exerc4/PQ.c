#include "PQ.h"

static Item *pq;
static int N;

void PQ_init(int capacity)
{
    pq = malloc(sizeof(Item) * (capacity + 1));
    N = 0;
}

void PQ_destroy(void)
{
    free(pq);
    pq = NULL;
    N = 0;
}

void PQ_insert(Item v)
{
    N++;
    pq[N] = v;
    fix_up(pq, N);
}

Item PQ_delmax()
{
    Item max = pq[1];
    exch(pq[1], pq[N]);
    N--;
    fix_down(pq, N, 1);
    return max;
}

Item PQ_max()
{
    return pq[1];
}

bool PQ_empty()
{
    if(!N)
    {
        return true;
    }

    return false;
}

void fix_up(Item *a, int k)
{
    while(k > 1 && less(a[k/2], a[k]))
    {
        exch(a[k], a[k/2]);

        k = k/2;
    }
}

void fix_down(Item *a, int sz, int k)
{

    a[sz + 1] = -1; //sentinela

    while(2*k <= sz)
    {
        int filho = 2*k;

        while (less(a[filho], a[filho + 1]))
        {
            filho++;
        }

        if(!less(a[k], a[filho]))
        {
            break;
        }
        
        exch(a[filho], a[k]);

        k = filho;
    }
}

void imprime_array(Item *array)
{
    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        printf("%d\n", array[i]);
    }
}

void executa_programa(void (*sort_fp)(Item *, int, int))
{
    Item *array = malloc(sizeof(Item) * MAX_SIZE);

    srand(time(NULL));

    for (int i = 0; i < MAX_SIZE; i++)
    {
        array[i] = rand() % MAX_SIZE;
    }

    sort_fp(array, 0, MAX_SIZE - 1);

    imprime_array(array);

    free(array);
}
