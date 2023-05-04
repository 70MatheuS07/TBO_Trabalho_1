#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct lista
{
    char *PontoID;
    tLista *prox;
};

tLista *CriaLista()
{
    return NULL;
}
tLista *InsereNaLista(char *PontoID, tLista *lista)
{
    tLista *nova = malloc(sizeof(tLista));
    nova->PontoID = PontoID;
    nova->prox = lista;
    return nova;
}

void LiberaLista(tLista *lista)
{
    tLista *p = lista;
    tLista *aux;
    while (p != NULL)
    {
        aux = p->prox;
        free(p->PontoID);
        free(p);
        p = aux;
    }
}

void ImprimeListaPontos(tLista *lista, FILE *fp)
{
    tLista *p = lista;
    while (p != NULL)
    {
        fprintf(fp, "%s", p->PontoID);
        if (p->prox != NULL)
        {
            fprintf(fp, ",");
        }
        p = p->prox;
    }
}

char *RetornaPrimeiroPonto(const tLista *lista)
{
    return lista->PontoID;
}