#include <stdio.h>

int euclides(int N, int M)
{
    while (1)
    {
        if(N > M)
        {
            N = N % M;
        }
        else
        {
            M = M % N;
        }

        if(!N)
        {
            return M;
        }
        else if(!M)
        {
            return N;
        }
    }
    
}

int main(int argc, char **argv)
{
    int N = 252;
    int M = 105;

    printf("%d \n", euclides(N, M));

    return 0;
}