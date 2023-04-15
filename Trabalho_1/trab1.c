#include "Arquivo.h"
#include "tPonto.h"
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

  FILE *f = fopen(arq_entrada, "r");

  int i = 0;

  while (1)
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

  fclose(f);
  free(arq_entrada);
  free(arq_saida);

  return 0;
}