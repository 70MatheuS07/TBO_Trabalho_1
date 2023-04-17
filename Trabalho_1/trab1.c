#include "Arquivo.h"
#include "tPonto.h"
#include "tAresta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char *arq_entrada = strdup(argv[1]);
  int k = atoi(argv[2]);
  char *arq_saida = strdup(argv[3]);

  int dimensao = RetornaDimensaoPonto(arq_entrada);
  printf("Dimensao: %d\n", dimensao);

  int qtd_linhas = ContaLinhasArquivoBuffer(arq_entrada);
  printf("Quantidade linhas: %d\n", qtd_linhas);

  tPonto **pontos = malloc(sizeof(tPonto *) * qtd_linhas);
  tPonto *p;

  tAresta **arestas=CriaVetorArestas(qtd_linhas);

  FILE *f = fopen(arq_entrada, "r");

  int i = 0;

  while (i<qtd_linhas)
  {
    p = LehPontoArquivo(f, dimensao);

    if (p == NULL)
    {
      break;
    }

    pontos[i] = p;

    ImprimePonto(pontos[i], dimensao);

    i++;
  }

  PreencheVetArestas(arestas,pontos, qtd_linhas, dimensao);
  ImprimirVetorArestas(arestas, qtd_linhas);
  fclose(f);
  free(arq_entrada);
  free(arq_saida);

  return 0;
}