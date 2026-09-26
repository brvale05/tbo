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

// UF_find com path compression precisamos atribuir o id de cada node examinado à raiz
int UF_find(int *id, int i)
{
    int raiz = 0;
    int j = i;

    while (i != id[i])
    {
        i = id[i];
    }
    
    raiz = i;

    while (j != id[j])
    {        
        int aux = j;
        j = id[j];  
        id[aux] = raiz;
    }
    
    return raiz;
}

int UF_connected(int *id, int p, int q)
{
    int p_id = UF_find(id, p);
    int q_id = UF_find(id, q);

    return p_id == q_id;
}

// UF_union pendura a raiz de p na raiz de q
void UF_union(int *id, int p, int q, int tam)
{
    int p_id = UF_find(id, p);
    int q_id = UF_find(id, q);

    id[p_id] = q_id;
    
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