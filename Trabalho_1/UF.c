#include "UF.h"

void UF_init(int *vet, int size, int *sz)
{
  for (int i = 0; i < size; i++)
  {
    vet[i] = i;
    sz[i] = 1;
  }
}

int UF_find(int *vet, int i)
{
  while (vet[i] != i)
  {
    vet[i] = vet[vet[i]];
    i = vet[i];
  }
  return i;
}

int UF_union(int *vet, int p, int q, int *size)
{
  int i = UF_find(vet, p);
  int j = UF_find(vet, q);

  if (i == j)
  {
    return 0;
  }

  if (size[i] < size[j])
  {
    vet[i] = j;
    size[j] += size[i];
  }
  else
  {
    vet[j] = i;
    size[i] += size[j];
  }

  return 1;
}