#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "tPonto.h"



struct lista
{
    tPonto*ponto;
    tLista *prox;
};

tLista *CriaLista()
{
    return NULL;
}
tLista *InsereNaLista(tPonto*ponto, tLista *lista)
{
    tLista *nova = malloc(sizeof(tLista));
    nova->ponto = ponto;
    nova->prox = lista;
    return nova;
}
tLista *RetiraDaLista(tPonto*ponto, tLista *lista)
{
    tLista *p = lista;
    tLista *ant = NULL;

    while (p != NULL && p->ponto!=ponto)
    {
        ant = p;
        p = p->prox;
    }
    if (p == NULL)
    {
        return lista;
    }

    if (lista == p)
    {
        lista = p->prox;
        LiberaLista(p);
        return lista;
    }
    ant->prox = p->prox;
    LiberaLista(p);
    return lista;
}
void LiberaLista(tLista *lista)
{
    free(lista);
    lista=NULL;
}

void LiberaRestoLista(tLista *lista)
{
    tLista *p = lista;
    while (p != NULL)
    {
        liberalista(p);
        p=p->prox;
    }
    free(lista);
}