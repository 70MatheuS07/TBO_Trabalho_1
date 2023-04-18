#include "tPonto.h"
#include <math.h>
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
  p->id = id;

  //printf("%s\n", id);
  double num;
  char c = 'x';
  p->id=id;
  for (int i = 0; c != '\n'; i++)
  {
    fscanf(f, "%lf%c", &num, &c);
    p->m[i] = num;
    //printf("%.14lf%c", p->m[i], c);
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

void ImprimeIDPonto(tPonto *p){
  printf("%s ", p->id);
}

double CalculaDistPontos(tPonto*p1, tPonto*p2,int dimensao){
    double dist = 0;
    for(int i = 0; i < dimensao;i++){
      dist+=pow((p1->m[i] - p2->m[i]),2);
    }
    dist=sqrt(dist);
    return dist;
}