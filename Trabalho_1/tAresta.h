#ifndef TARESTA_H
#define TARESTA_H

#include "tPonto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aresta tAresta;
typedef struct Grupo tGrupo;
tAresta **CriaVetorArestas(int qtdA);

tAresta *CriaAresta();

void PreencheVetArestas(tAresta **VetA, tPonto **VetP, int qtdV, int dim);

void ImprimirVetorArestas(tAresta **VetA, int qtdV);

void OrdenaVetArestas(tAresta **VetA, int qtdA);

int comparaDistancia(const void *item1, const void *item2);

void LiberaVetArestas(tAresta **VetA, int qtdA);

int *AlgoritmoKruskal( int qtdP, tAresta **a, int qtdGrupos);

#endif