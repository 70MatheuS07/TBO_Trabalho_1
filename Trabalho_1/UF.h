#ifndef UF_H
#define UF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Inicia o vetor do union-find com inteiros iguais ao seu indice
 * 
 * @param vet
 * @param size 
 */
void UF_init(int *vet, int size);

/**
 * @brief Encontra a raiz do elemento informado
 * 
 * @param vet 
 * @param i posicao do elemento
 * @return int 
 */
int UF_find(int *vet, int i);

/**
 * @brief Faz a conexão de dois elementos, mudando a raiz do primeiro para a raiz do degundo
 * 
 * @param vet 
 * @param p 
 * @param q 
 * @return int 
 */
int UF_union(int *vet, int p, int q);

#endif