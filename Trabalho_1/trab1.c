#include "Arquivo.h"
#include "tAresta.h"
#include "tPonto.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

  char *arq_entrada = strdup(argv[1]);
  int k = atoi(argv[2]);
  char *arq_saida = strdup(argv[3]);

  int dimensao = RetornaDimensaoPonto(arq_entrada);

  int qtdPontos = ContaLinhasArquivoBuffer(arq_entrada);

  tPonto **pontos = malloc(sizeof(tPonto *) * qtdPontos);
  tPonto *p;

  FILE *f = fopen(arq_entrada, "r");

  int i = 0;

  while (i < qtdPontos)
  {
    p = LehPontoArquivo(f, dimensao);

    if (p == NULL)
    {
      break;
    }

    pontos[i] = p;

    i++;
  }

  OrdenaVetPontos(pontos, qtdPontos);

  int qtdArestas = (qtdPontos * (qtdPontos - 1)) / 2;

  tAresta *arestas = CriaVetorArestas(qtdArestas);
  char **VetIDs;
  VetIDs = PreencheVetArestas(arestas, pontos, qtdPontos, dimensao);
  OrdenaVetArestas(arestas, qtdArestas);

  // Algoritmo de agrupamento
  int *vet = AlgoritmoKruskal(qtdPontos, arestas, k);
  LiberaVetArestas(arestas);

  FILE *fp = fopen(arq_saida, "w");
  tLista **grupos = MontaGrupos(vet, VetIDs, qtdPontos);
  ImprimeGrupos(grupos, qtdPontos, fp);

  fclose(f);
  fclose(fp);
  free(arq_entrada);
  free(arq_saida);
  free(vet);
  free(VetIDs);
  LiberaGrupos(grupos, qtdPontos);
  return 0;
}