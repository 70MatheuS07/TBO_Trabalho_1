#ifndef TARESTA_H
#define TARESTA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tPonto.h"

typedef struct Aresta tAresta;

tAresta** CriaVetorArestas(int qtdV);

tAresta*CriaAresta();

void PreencheVetArestas(tAresta**VetA, tPonto**VetP, int qtdV, int dim);

void ImprimirVetorArestas(tAresta**VetA, int qtdV);

void OrdenaVetArestas(tAresta**VetA, int qtdV);

int comparaDistancia(const void*item1, const void*item2);

#endif