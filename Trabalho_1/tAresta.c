#include <stdio.h>
#include <stdlib.h>

#include "tAresta.h"
#include "tPonto.h"
struct Aresta
{
    double dist; // Distancia entre os pontos.
    tPonto *po;  // Ponto origem.
    tPonto *pd;  // Ponto destino.
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
            VetA[k]->po = VetP[i];
            VetA[k]->pd = VetP[j];
            VetA[k]->dist = CalculaDistPontos(VetA[k]->po, VetA[k]->pd, dim);
        }
    }
}

// Funcao para testar o vetor de arestas, retirar depois
void ImprimirVetorArestas(tAresta **VetA, int qtdA)
{
    for (int i = 0; i < qtdA; i++)
    {
        // ImprimeIDPonto(VetA[i]->po);
        // ImprimeIDPonto(VetA[i]->pd);
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

tAresta **AlgoritmoKruskal(tAresta **a, int qtdA)
{
    for (int i = 0; i < qtdA; i++)
    {
        
    }
}