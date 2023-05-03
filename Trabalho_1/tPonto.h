#ifndef TPONTO_H
#define TPONTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Tipo ponto, contem o identificado do ponto, uma string, e um vetor com suas coordenadas
 * 
 */
typedef struct Ponto tPonto;

/**
 * @brief Le o identificador e as coordenadas do arquivo passado pelo parametro, aloca e retorna o ponto
 * 
 * @param f Arquivo de entrada
 * @param dimensao 
 * @return tPonto* 
 */
tPonto *LehPontoArquivo(FILE *f, int dimensao);


/**
 * @brief Imprime o ID do ponto, utilizado na impressão dos grupos no final do programa
 * 
 * @param p Ponto
 * @param fp Arquivo de saida
 */
void ImprimeIDPonto(tPonto *p, FILE*fp);

/**
 * @brief Utiliza a formula da distancia euclidiana para calcular a distancia entre dois pontos
 * 
 * @param p1 Ponto 1
 * @param p2 Ponto 2
 * @param dimensao 
 * @return double - Distancia
 */
double CalculaDistPontos(tPonto *p1, tPonto *p2, int dimensao);

/**
 * @brief Libera o vetor de pontos, juntamnete com todos os pontos armazenados
 * 
 * @param p Ponto
 * @param qtdP Quantidade de pontos
 */
void LiberaVetPontos(tPonto **p, int qtdP);

/**
 * @brief Libera um ponto
 * 
 * @param p Ponto
 */
void LiberaPonto(tPonto *p);

/**
 * @brief Funcao que ordena o vetor de pontos
 * 
 * @param p 
 * @param qtdP 
 */
void OrdenaVetPontos(tPonto **p, int qtdP);

/**
 * @brief Compara os IDs de dois pontos com strcmp, fucao de comparacao para o qsort
 * 
 * @param item1 
 * @param item2 
 * @return int 
 */
int ComparaNomes(const void *item1, const void *item2);

/**
 * @brief Funcao que retorna o ID do ponto
 * 
 * @param p Ponto
 * @return char* 
 */
char* GetId (tPonto*ponto);

#endif