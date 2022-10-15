#include "buscabinaria.h"
#include <stdlib.h>
#include <stdio.h>

//inicia um dicionário
void TDicionario_Inicia(TDicionario *t){
    t->n = 0;
    t->max = 10;
    t->v = (TRegistro*) malloc(t->max * sizeof(TRegistro));
}

int TDicionario_find(TDicionario *t, TChave x){
    return TDicionario_Binaria(t, x, 0, t->n-1);
}
int TDicionario_Binaria(TDicionario *t, TChave x, int esq, int dir){
    int meio = (esq + dir)/2;
    if(t->v[meio].Chave != x && esq == dir) return -1;
    else if(x > t->v[meio].Chave) return TDicionario_Binaria(t, x, meio+1, dir);
    else if(x < t->v[meio].Chave) return TDicionario_Binaria(t, x, esq, meio-1);
    else return meio;
}