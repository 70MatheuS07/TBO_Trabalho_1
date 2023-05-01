#ifndef TARESTA_H
#define TARESTA_H

#include "tAresta.h"
#include "UF.h"
#include "tPonto.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aresta tAresta;
tAresta **CriaVetorArestas(int qtdA);

tAresta *CriaAresta();

void PreencheVetArestas(tAresta **VetA, tPonto **VetP, int qtdV, int dim);

void ImprimirVetorArestas(tAresta **VetA, int qtdV);

void OrdenaVetArestas(tAresta **VetA, int qtdA);

int comparaDistancia(const void *item1, const void *item2);

void LiberaVetArestas(tAresta **VetA, int qtdA);

int *AlgoritmoKruskal( int qtdP, tAresta **a, int qtdGrupos);

tLista** MontaGrupos(int *vet,tPonto**pontos,int qtdP);

void ImprimeGrupos(tLista**grupos, int qtdP);

void OrdenaGrupos(tLista**grupos, int qtdP);

int ComparaGrupos(const void *item1, const void *item2);
#endif