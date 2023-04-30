#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 4096 // Tamanho do bloco em bytes

int RetornaDimensaoPonto(char *s);

int ContaLinhasArquivoBuffer(char *arq_entrada);

#endif