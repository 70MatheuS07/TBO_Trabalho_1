#include "Arquivo.h"
#include "tAresta.h"
#include "tPonto.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
  char *arq_entrada = strdup(argv[1]);
  int k = atoi(argv[2]);

  int dimensao = RetornaDimensaoPonto(arq_entrada);

  int qtdPontos = ContaLinhasArquivoBuffer(arq_entrada);

  tPonto **pontos = malloc(sizeof(tPonto *) * qtdPontos);
  tPonto *p;

  FILE *f = fopen(arq_entrada, "r");
  free(arq_entrada);

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
  fclose(f);

  OrdenaVetPontos(pontos, qtdPontos);

  int qtdArestas = (qtdPontos * (qtdPontos - 1)) / 2;

  tAresta *arestas = CriaVetorArestas(qtdArestas);

  char **VetIDs = PreencheVetArestas(arestas, pontos, qtdPontos, dimensao);

  OrdenaVetArestas(arestas, qtdArestas);

  // Algoritmo de agrupamento
  int *vet = AlgoritmoKruskal(qtdPontos, arestas, k);

  LiberaVetArestas(arestas);

  char *arq_saida = strdup(argv[3]);
  FILE *fp = fopen(arq_saida, "w");
  free(arq_saida);

  tLista **grupos = MontaGrupos(vet, VetIDs, qtdPontos);

  free(vet);
  free(VetIDs);

  ImprimeGrupos(grupos, qtdPontos, fp);

  fclose(fp);
  LiberaGrupos(grupos, qtdPontos);

  return 0;
}