#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"



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


void LiberaLista(tLista *lista)
{
    tLista *p = lista;
    while (p != NULL)
    {
        free(p);
        p=p->prox;
    }
    free(lista);
}

void ImprimeListaPontos(tLista*lista){
    tLista*p=lista;
    while(p!=NULL){
        ImprimeIDPonto(p->ponto);
        if(p->prox!=NULL){
            printf(",");
        }
        p=p->prox;
    }
}

tPonto* RetornaPrimeiroPonto(const tLista*lista){
    return lista->ponto;
}