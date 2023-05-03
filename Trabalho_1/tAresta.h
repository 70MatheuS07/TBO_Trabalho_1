#ifndef TARESTA_H
#define TARESTA_H

#include "tAresta.h"
#include "UF.h"
#include "tPonto.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Tipo Aresta, possui um ponto de origem e um de destino do tipo inteiro para que para obter
 * um acesso direto aos pontos
 * 
 */
typedef struct Aresta tAresta;

/**
 * @brief Cria-se um vetor de arestas, alocando um ponteiro duplo para aresta com o tamanho(numero de vertices-1),
 * que é exatamente o número de arestas
 * 
 * @param qtdA quantidade de arestas 
 * @return tAresta** 
 */
tAresta **CriaVetorArestas(int qtdA);

/**
 * @brief Aloca-se uma aresta para inserir no vetor
 * 
 * @return tAresta* 
 */
tAresta *CriaAresta();


/**
 * @brief Funcao que preenche o vetor de arestas com todas as combinacoes de dois pontos possiveis e suas respectivas distancias
 * 
 * @param VetA Vetor de arestas
 * @param VetP vetor de pontos
 * @param qtdV quantidade de pontos
 * @param dim dimensão dos pontos
 */
void PreencheVetArestas(tAresta **VetA, tPonto **VetP, int qtdV, int dim);



/**
 * @brief Ordena o vetor de arestas com qsort
 * 
 * @param VetA Vetor de arestas
 * @param qtdA quantidade de arestas
 */
void OrdenaVetArestas(tAresta **VetA, int qtdA);


/**
 * @brief Compara as distancias  do tipo aresta para utilizar no qsort do OrdenaArestas
 * 
 * @param item1 
 * @param item2 
 * @return int 1,-1 ou 0
 */
int comparaDistancia(const void *item1, const void *item2);

/**
 * @brief Libera Todo o vetor de arestas
 * 
 * @param VetA Vetor de arestas
 * @param qtdA quabntidade de arestas
 */
void LiberaVetArestas(tAresta **VetA, int qtdA);

/**
 * @brief Executa o algoritimo de Kruskal com quick union em um vetor de inteiros representando os pontos 
 * 
 * @param qtdP Quantitade de pontos
 * @param a vetor de arestas
 * @param qtdGrupos 
 * @return int* - vetor de inteiros pós quick union
 */
int *AlgoritmoKruskal( int qtdP, tAresta **a, int qtdGrupos);

/**
 * @brief Monta os grupos, que sao representados por listas, a partir do vetor de inteiros resultante
 *  do quick union da funcao AlgoritmoKruskal
 * 
 * @param vet vetor de inteiros
 * @param pontos Vetor de pontos
 * @param qtdP quantidade de pontos
 * @return tLista** Grupos formados
 */
tLista** MontaGrupos(int *vet,tPonto**pontos,int qtdP);

/**
 * @brief Imprime os grupos de maneira ordenanda
 * 
 * @param grupos 
 * @param qtdP Quantidade de pontos
 * @param fp Arquivo de saída
 */
void ImprimeGrupos(tLista**grupos, int qtdP, FILE*fp);

/**
 * @brief Funcao que ordena os grupos de acordo com o primeiro elemento de cada lista para
 * que se possa imprimir de maneira ordenada
 * 
 * @param grupos 
 * @param qtdP Quntidade de pontos
 */
void OrdenaGrupos(tLista**grupos, int qtdP);

/**
 * @brief Compara os primeiros elementos de cada lista
 * 
 * @param item1 
 * @param item2 
 * @return int 
 */
int ComparaGrupos(const void *item1, const void *item2);

/**
 * @brief Libera todos os ponteiros para lista e a estrutura que os armazena, do tipo tLista**
 * 
 * @param grupos 
 * @param qtdp Quantidade de pontos
 */
void LiberaGrupos(tLista **grupos, int qtdp);
#endif