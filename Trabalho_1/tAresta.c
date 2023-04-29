#include "tAresta.h"
#include "UF.h"
#include "tPonto.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

struct Aresta {
  double dist; // Distancia entre os pontos.
  int po;      // Ponto origem.
  int pd;      // Ponto destino.
};

struct Grupo{
  int raiz;
  tLista*lista;
};

tAresta **CriaVetorArestas(int qtdA) {
  tAresta **vet = malloc(sizeof(tAresta *) * qtdA);
  return vet;
}

tAresta *CriaAresta() {
  tAresta *a;
  a = (tAresta *)malloc(sizeof(tAresta));
  return a;
}

void PreencheVetArestas(tAresta **VetA, tPonto **VetP, int qtdP, int dim) {
  int k = 0;
  for (int i = 0; i < qtdP; i++) {
    for (int j = i + 1; j < qtdP; j++, k++) {
      VetA[k] = CriaAresta();
      VetA[k]->po = i;
      VetA[k]->pd = j;
      VetA[k]->dist =
          CalculaDistPontos(VetP[VetA[k]->po], VetP[VetA[k]->pd], dim);
    }
  }
}

// Funcao para testar o vetor de arestas, retirar depois
void ImprimirVetorArestas(tAresta **VetA, int qtdA) {
  for (int i = 0; i < qtdA; i++) {
    printf("%d ", (VetA[i]->po));
    printf("%d ", (VetA[i]->pd));
    printf("%.14lf", VetA[i]->dist);
    printf("\n");
  }
}

void LiberaVetArestas(tAresta **VetA, int qtdA) {
  for (int i = 0; i < qtdA; i++) {
    free(VetA[i]);
  }
  free(VetA);
}

void OrdenaVetArestas(tAresta **VetA, int qtdA) {
  qsort(VetA, qtdA, sizeof(tAresta *), comparaDistancia);
}

int comparaDistancia(const void *item1, const void *item2) {
  const tAresta *A1 = *(const tAresta **)item1;
  const tAresta *A2 = *(const tAresta **)item2;

  if (A1->dist > A2->dist)
    return 1;

  else if (A1->dist < A2->dist)
    return -1;

  return 0;
}

int *AlgoritmoKruskal(int qtdP, tAresta **a, int qtdGrupos) {

  int *vet = malloc(sizeof(int) * qtdP);
  UF_init(vet,qtdP);
  int i = 0;
  int U_Validos=qtdP-qtdGrupos;
    while(U_Validos>0){
      U_Validos-=UF_union(vet, a[i]->po, a[i]->pd);
      i++;
    }
      
  return vet;
}

void MontaGrupos(int *vet,tPonto**pontos,int qtdP, int qtdGrupos){
  tGrupo*grupos=malloc(qtdGrupos * sizeof(tGrupo));
  int i=0;
  while(i<qtdP){
    
  }
}