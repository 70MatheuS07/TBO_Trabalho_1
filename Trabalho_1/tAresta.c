#include "tAresta.h"

#include <stdio.h>
#include <stdlib.h>

struct Aresta
{
  double dist; // Distancia entre os pontos.
  int po;      // Ponto origem.
  int pd;      // Ponto destino.
};

tAresta *CriaVetorArestas(int qtdA)
{
  tAresta *vet = malloc(sizeof(tAresta) * qtdA);
  return vet;
}


char **PreencheVetArestas(tAresta *VetA, tPonto **VetP, int qtdP, int dim)
{
  char **IDPontos = malloc(sizeof(char *) * qtdP);
  int k = 0;
  for (int i = 0; i < qtdP; i++)
  {
    for (int j = i + 1; j < qtdP; j++, k++)
    {
      VetA[k].po = i;
      VetA[k].pd = j;
      VetA[k].dist =
          CalculaDistPontos(VetP[VetA[k].po], VetP[VetA[k].pd], dim);
    }
    IDPontos[i] = malloc(sizeof(char) * 201);
    strcpy(IDPontos[i], GetId(VetP[i]));
    
    LiberaPonto(VetP[i]);
  }

  free(VetP);
  return IDPontos;
}

void LiberaVetArestas(tAresta *VetA)
{
  free(VetA);
}

void OrdenaVetArestas(tAresta *VetA, int qtdA)
{
  qsort(VetA, qtdA, sizeof(tAresta), comparaDistancia);
}

int comparaDistancia(const void*item1, const void *item2)
{
  const tAresta *A1 = (const tAresta*)item1;
  const tAresta *A2 = (const tAresta*)item2;

  if (A1->dist > A2->dist)
    return 1;

  else if (A1->dist < A2->dist)
    return -1;

  return 0;
}

int *AlgoritmoKruskal(int qtdP, tAresta *a, int qtdGrupos)
{

  int *vet = malloc(sizeof(int) * qtdP);
  int *size = malloc(sizeof(int) * qtdP);
  UF_init(vet, qtdP, size);
  int i = 0;
  int U_Validos = qtdP - qtdGrupos;
  while (U_Validos > 0)
  {
    U_Validos -= UF_union(vet, a[i].po, a[i].pd, size);
    i++;
  }

  return vet;
}

tLista **MontaGrupos(int *vet, char **IDpontos, int qtdP)
{
  tLista **grupos = malloc(qtdP * sizeof(tLista *));
  for (int i = 0; i < qtdP; i++)
  {
    grupos[i] = CriaLista();
  }

  int i = qtdP - 1;
  int pos = 0;
  while (i >= 0)
  {
    pos = UF_find(vet, i);
    grupos[pos] = InsereNaLista(IDpontos[i], grupos[pos]);
    i--;
  }
  OrdenaGrupos(grupos, qtdP);
  return grupos;
}

void ImprimeGrupos(tLista **grupos, int qtdP, FILE *fp)
{
  for (int i = 0; i < qtdP; i++)
  {
    ImprimeListaPontos(grupos[i], fp);
    if (grupos[i] != NULL)
    {
      fprintf(fp, "\n");
    }
  }
}

void OrdenaGrupos(tLista **grupos, int qtdP)
{
  qsort(grupos, qtdP, sizeof(tLista *), ComparaGrupos);
}

int ComparaGrupos(const void *item1, const void *item2)
{
  const tLista *A1 = *(const tLista **)item1;
  const tLista *A2 = *(const tLista **)item2;

  if (A1 == NULL)
  {
    return 1;
  }
  else if (A2 == NULL)
  {
    return -1;
  }
  else
  {
    return strcmp(RetornaPrimeiroPonto(A1), RetornaPrimeiroPonto(A2));
  }
}

void LiberaGrupos(tLista **grupos, int qtdp)
{
  for (int i = 0; i < qtdp; i++)
  {
    LiberaLista(grupos[i]);
  }
  free(grupos);
}