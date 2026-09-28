#include <stdio.h>
#include <stdlib.h>

int formula(int N, int k)
{
    if (!N)
    {
        return 1;
    } 

    int cLeft = formula(k - 1, k + 1);

    return N + ((float)1/N * (cLeft + formula(N - k, k + 1)));
}

int main(int argc, char **argv)
{
    int N = atoi(argv[1]);

    printf("C:%d = %d\n", N, formula(N, 1));

    return 0;
}