#include "PQ.h"

void sort(Item *a, int lo, int hi)
{
    int n = hi - lo + 1;
    PQ_init(n);

    for (int i = 0; i < n; i++)
    {       
        PQ_insert(a[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        a[i] = PQ_delmax();
    }

    PQ_destroy();
}

int main()
{
    executa_programa(sort);

    return 0;
}
