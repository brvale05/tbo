#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void UF_init(int *id, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        id[i] = i;
    }    
}

int UF_find(int *id, int i)
{
    return id[i];
}

int UF_connected(int *id, int p, int q)
{
    return id[p] == id[q];
}

int UF_union(int *id, int p, int q, int tam)
{
    int p_id = UF_find(id, p);
    int q_id = UF_find(id, q);

    for (size_t i = 0; i < tam; i++)
    {
        if(id[i] == p_id)
        {
            id[i] = q_id;
        }
    }
    
}

int main(int argc, char **argv)
{
    int *id = malloc(sizeof(int) * MAX_SIZE);

    UF_init(id, MAX_SIZE);

    int p, q;

    while (scanf("%d %d", &p, &q) == 2)
    {
        if(!UF_connected(id, p, q))
        {
            UF_union(id, p, q, MAX_SIZE);
            printf("%d %d\n", p, q);
        }
        else
        {
            printf("\n");
        }
    }

    free(id);
    
}