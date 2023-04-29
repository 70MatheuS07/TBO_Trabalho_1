#ifndef LISTA_H
#define LISTA_H
#include "tPonto.h"
typedef struct lista tLista;

tLista *InsereNaLista(tPonto*ponto, tLista *lista);
tLista *RetiraDaLista(tPonto*ponto, tLista *lista);
void LiberaLista(tLista *lista);
void LiberaRestoLista(tLista *lista);


#endif