#include "tPonto.h"

struct Ponto
{
  char *id;  // Identificador.
  double *m; // Valores das coordenadas (x, y, z, etc).
};

tPonto *LehPontoArquivo(FILE *f, int dimensao)
{
  if (f == NULL)
  {
    return NULL;
  }
  
  tPonto *p = malloc(sizeof(tPonto));
  p->m = malloc(sizeof(double) * dimensao);

  char *id = malloc(sizeof(char) * 201);

  fscanf(f, "%[^,],", id);
  printf("%s\n", id);
  double num;
  char c = 'x';

  for (int i = 0; c != '\n'; i++)
  {
    fscanf(f, "%lf%c", &num, &c);
    p->m[i] = num;
    printf("%.14lf%c", p->m[i], c);
  }

  return p;
}

void ImprimePonto(tPonto *p, int dimensao)
{
  printf("%s", p->id);

  for (int i = 0; i < dimensao; i++)
  {
    printf(",%.14lf\n", p->m[i]);
  }
}