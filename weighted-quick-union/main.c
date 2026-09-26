#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void UF_init(int *id, int *sz, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        id[i] = i;
        sz[i] = 1;
    }
}

// UF_find no quick union tem que encontrar a raiz da componente conexa.
int UF_find(int *id, int i)
{
    while (i != id[i])
    {
        i = id[i];
    }

    return i;
}

int UF_connected(int *id, int p, int q)
{
    int p_id = UF_find(id, p);
    int q_id = UF_find(id, q);

    return p_id == q_id;
}

// UF_union pendura a menor arvore sobre a maior
void UF_union(int *id, int *sz, int p, int q, int tam)
{
    int p_id = UF_find(id, p);
    int q_id = UF_find(id, q);

    // Se a raiz eh igual nao ha motivos para alterar o tamanho de cada arvore
    if (p_id == q_id)
        return;

    if (sz[p_id] <= sz[q_id])
    {
        id[p_id] = q_id;
        sz[q_id] += sz[p_id];
    }
    else
    {
        id[q_id] = p_id;
        sz[p_id] += sz[q_id];
    }
}

int main(int argc, char **argv)
{
    int *id = malloc(sizeof(int) * MAX_SIZE);
    int *sz = malloc(sizeof(int) * MAX_SIZE);

    UF_init(id, sz, MAX_SIZE);

    int p, q;

    while (scanf("%d %d", &p, &q) == 2)
    {
        if (!UF_connected(id, p, q))
        {
            UF_union(id, sz, p, q, MAX_SIZE);
            printf("%d %d\n", p, q);
        }
        else
        {
            printf("\n");
        }
    }

    free(id);
    free(sz);
}