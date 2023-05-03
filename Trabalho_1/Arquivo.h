#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 4096 // Tamanho do bloco em bytes
/**
 * @brief funcao que retorna a dimensao dos pontos do arquivo, para isso, le-se o primeiro ponto é contada
 * a quantidade de suas coordenadas 
 * 
 * 
 * @param s Nome do arquivo
 * @return int - Dimensao
 */
int RetornaDimensaoPonto(char *s);
/**
 * @brief Conta quantas linhas possuem o arquivo, lendo ponto por ponto, desse modo, no final
 * temos a quantidae de pontos
 * 
 * @param arq_entrada Arquivo de entrada
* @return int - Quantidade de pontos
 */
int ContaLinhasArquivoBuffer(char *arq_entrada);

#endif