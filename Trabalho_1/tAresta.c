#include <stdio.h>
#include <stdlib.h>

#include "tAresta.h"
#include "tPonto.h"
struct Aresta
{
    double dist; // Distancia entre os pontos.
    int po;      // Ponto origem.
    int pd;      // Ponto destino.
};

tAresta **CriaVetorArestas(int qtdA)
{
    tAresta **vet = malloc(sizeof(tAresta *) * qtdA);
    return vet;
}

tAresta *CriaAresta()
{
    tAresta *a;
    a = (tAresta *)malloc(sizeof(tAresta));
    return a;
}

void PreencheVetArestas(tAresta **VetA, tPonto **VetP, int qtdV, int dim)
{
    int k = 0;
    for (int i = 0; i < qtdV; i++)
    {
        for (int j = i + 1; j < qtdV; j++, k++)
        {
            VetA[k] = CriaAresta();
            VetA[k]->po = i;
            VetA[k]->pd = j;
            VetA[k]->dist = CalculaDistPontos(VetP[VetA[k]->po], VetP[VetA[k]->pd], dim);
        }
    }
}

// Funcao para testar o vetor de arestas, retirar depois
void ImprimirVetorArestas(tAresta **VetA, int qtdA)
{
    for (int i = 0; i < qtdA; i++)
    {
         printf("%d ",(VetA[i]->po));
         printf("%d ",(VetA[i]->pd));
        printf("%.14lf", VetA[i]->dist);
        printf("\n");
    }
}

void LiberaVetArestas(tAresta **VetA, int qtdA)
{
    for (int i = 0; i < qtdA; i++)
    {
        free(VetA[i]);
    }
    free(VetA);
}

void OrdenaVetArestas(tAresta **VetA, int qtdA)
{
    qsort(VetA, qtdA, sizeof(tAresta *), comparaDistancia);
}

int comparaDistancia(const void *item1, const void *item2)
{
    const tAresta *A1 = *(const tAresta **)item1;
    const tAresta *A2 = *(const tAresta **)item2;

    if (A1->dist > A2->dist)
        return 1;

    else if (A1->dist < A2->dist)
        return -1;

    return 0;
}

tAresta **AlgoritmoKruskal(tPonto **p, int qtdV, tAresta **a, int qtdA)
{
    tAresta **result = malloc(sizeof(tAresta *) * qtdV - 1);
    int *vet = malloc(sizeof(int) * qtdV);
    PreencheVetor(vet, qtdV);
    int num = 0;
    for (int i = 0; i < qtdA; i++)
    {
        if (num == qtdV - 1)
        {
            break;
        }

        if (vet[a[i]->po] != vet[a[i]->pd])
        {
            ConfereLigacoes(vet, qtdV, vet[a[i]->po], vet[a[i]->pd]);
            result[num] = a[i];
            num++;
        }
    }

    free(vet);

    return result;
}

void PreencheVetor(int *vet, int qtdV)
{
    for (int i = 0; i < qtdV; i++)
    {
        vet[i] = i;
    }
}

void ConfereLigacoes(int *vet, int qtdV, int po, int pd)
{
    for (int i = 0; i < qtdV; i++)
    {
        if (vet[i] == pd)
        {
            vet[i] = po;
        }
    }
}

