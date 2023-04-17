#include <stdio.h>
#include <stdlib.h>

#include "tAresta.h"
#include "tPonto.h"
struct Aresta
{
    double dist;    // Distancia entre os pontos.
    tPonto *po;     // Ponto origem.
    tPonto *pd;     // Ponto destino.
};

tAresta** CriaVetorArestas(int qtdV){
    int tamVet=(qtdV*(qtdV-1))/2;
    tAresta**vet=malloc(sizeof(tAresta*)*tamVet);
}

tAresta* CriaAresta(){
    tAresta *a;
    a = (tAresta *)malloc(sizeof(tAresta));
    return a;

}

void PreencheVetArestas(tAresta**VetA, tPonto**VetP, int qtdV, int dim){
    int k=0;
    for(int i=0; i<qtdV; i++){
        for(int j=i+1; j<qtdV; j++, k++){
            VetA[k]=CriaAresta();
            VetA[k]->po=VetP[i];
            VetA[k]->pd=VetP[j];
            VetA[k]->dist=CalculaDistPontos(VetA[k]->po,VetA[k]->pd, dim);
        }
    }
}

//Funcao para testar o vetor de arestas, retirar depois
void ImprimirVetorArestas(tAresta**VetA, int qtdV){
    int tam=(qtdV*(qtdV-1))/2;
    printf("\n\n");
    for(int i=0; i<tam; i++){
        ImprimeIDPonto(VetA[i]->po);
        ImprimeIDPonto(VetA[i]->pd);
        printf("%.14lf", VetA[i]->dist);
        printf("\n\n");
    }
}

void LiberaVetArestas(tAresta**VetA, int qtdV){
    int tam=(qtdV*(qtdV-1))/2;
    for(int i=0; i<tam; i++){
        free(VetA[i]);
    }
    free(VetA);
}