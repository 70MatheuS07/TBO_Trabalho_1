#include "UF.h"

void UF_init(int *vet, int size)
{
  for (int i = 0; i < size; i++)
  {
    vet[i] = i;
  }
}

int UF_find(int *vet, int i)
{

  while (vet[i] != i)
  {
    i = vet[i];
  }
  return i;
}

int UF_union(int *vet, int p, int q)
{
  int i = UF_find(vet, p);
  int j = UF_find(vet, q);

  if (i == j)
  {
    return 0;
  }

  vet[i] = j;
  return 1;
}