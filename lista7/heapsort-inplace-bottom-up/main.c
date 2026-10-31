#include "PQ.h"

extern void sort(Item *a, int lo, int hi)
{
    int N = hi - lo + 1;

    for(int i = N/2; i > 0; i--)
    {
        fix_down(a, N , i);
    }

    while (N > 1)
    {        
        exch(a[1], a[N]);        
        fix_down(a, --N, 1);        
    }
    
}

int main()
{
    executa_programa(sort);

    return 0;
}