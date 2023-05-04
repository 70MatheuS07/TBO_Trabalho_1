#ifndef LISTA_H
#define LISTA_H
#include "tPonto.h"

/**
 * @brief Tipo lista simplesmente encacadeada sem sentinela, Contem um ponto e um ponteiro para um proximo ponto.
 * Essa lista sera utilizada para obtermos os grupos no final
 * 
 */
typedef struct lista tLista;
/**
 * @brief Adiciona um elemento nulo na lista
 * 
 * @return tLista* - NULL
 */
tLista *CriaLista();

/**
 * @brief Insere  um elemento no inicio da lista
 * 
 * @param ponto 
 * @param lista 
 * @return tLista* 
 */
tLista *InsereNaLista(char*PontoID, tLista *lista);

/**
 * @brief Libera toda a lista passada por parâmetro
 * 
 * @param lista 
 */
void LiberaLista(tLista *lista);
/**
 * @brief  Imprime no arquivo de saída a lista passada por parâmetro
 * 
 * @param lista 
 * @param fp 
 */
void ImprimeListaPontos(tLista*lista, FILE*fp);
/**
 * @brief Retorna o ID do primeiro ponto da lista passada, essa funcao sera utilizada para ordenar o vetor de listas
 * que representa os grupos
 * 
 * @param lista 
 * @return tPonto* - Primeiro ponto da lista 
 */
char* RetornaPrimeiroPonto(const tLista*lista);

#endif