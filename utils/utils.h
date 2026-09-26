#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Compara dois valores inteiros.
 *
 * Esta função de comparação foi escrita com a assinatura exigida 
 * pelas funções da biblioteca padrão do C, como qsort().
 *
 * @param a Ponteiro constante para o primeiro número inteiro.
 * @param b Ponteiro constante para o segundo número inteiro.
 * @return 1 se o valor apontado por 'a' for maior que o de 'b', 
 *        -1 se o valor apontado por 'a' for menor que o de 'b', 
 *         0 se os valores forem iguais.
 */
int compare_int(const void *a, const void *b)
{
    int valA = *(const int *)a;
    int valB = *(const int *)b;

    if (valA > valB)
        return 1;
    if (valA < valB)
        return -1;
    return 0;    
}

#endif