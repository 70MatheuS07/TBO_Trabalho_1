#ifndef TPONTO_H
#define TPONTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ponto tPonto;

tPonto *LehPontoArquivo(FILE *f, int dimensao);

void ImprimePonto(tPonto *p, int dimensao);

#endif