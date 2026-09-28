#include <stdio.h>
#include <stdlib.h>

int fib_mod(int N, int M)
{
    if (N == 1)
    {
        return 1;
    }

    if (!N)
    {
        return 0;
    }

    int f = fib_mod(N - 1, M) + fib_mod(N - 2, M);

    return f % M;
}

int main(int argc, char **argv)
{
    int N = atoi(argv[1]); 
    int M = atoi(argv[2]);

    printf("%d ", fib_mod(N, M));

    return 0;
}