#ifndef TARESTA_H
#define TARESTA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tPonto.h"

typedef struct Aresta tAresta;

tAresta **CriaVetorArestas(int qtdA);

tAresta *CriaAresta();

void PreencheVetArestas(tAresta **VetA, tPonto **VetP, int qtdV, int dim);

void ImprimirVetorArestas(tAresta **VetA, int qtdV);

void OrdenaVetArestas(tAresta **VetA, int qtdA);

int comparaDistancia(const void *item1, const void *item2);

void LiberaVetArestas(tAresta **VetA, int qtdA);

tAresta **AlgoritmoKruskal(tAresta **a, int qtdA);

#endif