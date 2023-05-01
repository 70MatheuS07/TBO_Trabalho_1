#ifndef LISTA_H
#define LISTA_H
#include "tPonto.h"
typedef struct lista tLista;

tLista *CriaLista();

tLista *InsereNaLista(tPonto*ponto, tLista *lista);

void LiberaLista(tLista *lista);

void ImprimeListaPontos(tLista*lista, FILE*fp);

tPonto* RetornaPrimeiroPonto(const tLista*lista);

#endif