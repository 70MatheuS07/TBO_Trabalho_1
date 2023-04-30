#include "UF.h"

void UF_init(int *vet, int *qtd, int size) {
  for (int i = 0; i < size; i++) {
    vet[i] = i;
    qtd[i] = 1;
  }
}

int UF_find(int *vet, int i) {
  if (vet[i] == i) {
    return i;
  }
  return vet[i];
}

void UF_union(int *vet, int *qtd, int p, int q) {
  int i = UF_find(vet, p);
  int j = UF_find(vet, q);
  if (i == j)
    return;

  if (qtd[i] < qtd[j]) {
    vet[i] = j;
    qtd[j] = qtd[i];
  } else {
    vet[j] = i;
    qtd[i] = qtd[j];
  }
}