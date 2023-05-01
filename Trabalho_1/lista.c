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
    tLista*aux;
    while (p != NULL)
    {
        aux=p->prox;
        free(p);
        p=aux;
    }
}

void ImprimeListaPontos(tLista*lista, FILE*fp){
    tLista*p=lista;
    while(p!=NULL){
        ImprimeIDPonto(p->ponto, fp);
        if(p->prox!=NULL){
            fprintf(fp,",");
        }
        p=p->prox;
    }
}

tPonto* RetornaPrimeiroPonto(const tLista*lista){
    return lista->ponto;
}