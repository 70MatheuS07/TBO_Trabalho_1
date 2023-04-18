#ifndef TPONTO_H
#define TPONTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ponto tPonto;

tPonto *LehPontoArquivo(FILE *f, int dimensao);

void ImprimePonto(tPonto *p, int dimensao);

void ImprimeIDPonto(tPonto *p);

double CalculaDistPontos(tPonto *p1, tPonto *p2, int dimensao);

double CalculaDistPontos(tPonto *p1, tPonto *p2, int dimensao);

void LiberaVetPontos(tPonto **p, int qtdP);

void LiberaPonto(tPonto *p);

#endif