#include "Arquivo.h"

int RetornaDimensaoPonto(char *s)
{
  FILE *f = fopen(s, "r");

  char *id = malloc(sizeof(char) * 201);
  double num;
  int i = 0;
  char c = '\0';

  fscanf(f, "%[^,],", id);
  // printf("%s\n", id);

  while (c != '\n')
  {
    fscanf(f, "%lf%c", &num, &c);
    // printf("%.14lf\n", num);
    i++;
  }

  free(id);
  fclose(f);

  return i;
}

int ContaLinhasArquivoBuffer(char *arq_entrada)
{
  FILE *f;
  char buffer[BLOCK_SIZE];
  int i = 0;

  f = fopen(arq_entrada, "r");

  while (fgets(buffer, BLOCK_SIZE, f) != NULL)
  {
    char *pos = strchr(buffer, '\n');
    while (pos != NULL)
    {
      i++;
      pos = strchr(pos + 1, '\n');
    }
  }

  fclose(f);
  return i;
}