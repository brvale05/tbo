#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double log_fatorial(double N)
{
    if (N == (double)1)
    {
        return log(N);
    }

    return log(N) + log_fatorial(N - 1);
}

int main(int argc, char **argv)
{
    double N;

    printf("DIGITE N:\n");
    scanf("%lf", &N);

    printf("%lf\n", log_fatorial(N));

    return 0;
}