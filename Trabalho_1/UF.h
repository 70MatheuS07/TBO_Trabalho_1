#ifndef UF_H
#define UF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void UF_init(int *vet, int *qtd, int size);

int UF_find(int *vet, int i);

void UF_union(int *vet, int *qtd, int p, int q);

#endif