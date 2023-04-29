#ifndef UF_H
#define UF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void UF_init(int *vet, int size);

int UF_find(int *vet, int i);

int UF_union(int *vet, int p, int q);

#endif