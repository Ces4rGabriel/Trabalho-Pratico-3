#include "buscabinaria.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//inicia um dicionário
void TDicionario_Inicia(TDicionario *t, int malhas){
    t->n = 0;
    t->cont = 0;
    t->max = malhas;
    t->v = (TRegistro*) malloc(t->max * sizeof(TRegistro));
}

int TDicionario_find(TDicionario *t, TChave x){
    return TDicionario_Binaria(t, x, 0, t->n-1);
}

int CheckPos(TDicionario *t, int pos, TChave x){
    if(t->v[pos].Chave == x) return pos;
    else return -1;
}


int TDicionario_Binaria(TDicionario *t, TChave x, int esq, int dir){
    t->cont++;
    int meio = floor((esq + dir)/2);
    if(t->v[meio].Chave != x && esq == dir) return -1;
    else if(x > t->v[meio].Chave) return TDicionario_Binaria(t, x, meio+1, dir);
    else if(x < t->v[meio].Chave) return TDicionario_Binaria(t, x, esq, meio-1);
    else return meio;
}

void lerMalhas(int m, TDicionario *dicionario, int *pos, int *alvo) {

    for(int i = 0; i < m; i++){
        scanf("%d", &dicionario->v[i].Chave);
        dicionario->n++;
    }
    scanf("%d %d", pos, alvo);

}

void exibeResultado(int posDesejada, int posEncontrada) {

    if(posDesejada != posEncontrada){
        int resto = posDesejada % 10;

        if(posEncontrada == -1 && resto == 1 ){
            printf("Disparo incorreto: Malha sem o porta aviões %d\n", posDesejada);
        }else if(posEncontrada == -1 && resto == 2){
            printf("Disparo incorreto: Malha sem o encouraçado %d\n", posDesejada);
        }else if(posEncontrada == -1 && resto == 3){
            printf("Disparo incorreto: Malha sem o cruzador %d\n", posDesejada);
        }else if(posEncontrada == -1 && resto == 4){
            printf("Disparo incorreto: Malha sem a fragata %d\n", posDesejada);
        }else if(posEncontrada == -1 && resto == 5){
            printf("Disparo incorreto: Malha sem o submarino %d\n", posDesejada);
        }

    } else if (posDesejada == posEncontrada) {
         int resto = posEncontrada % 10;

        if(resto == 1) {
            printf("Disparo certeiro: O porta aviões %d afundou\n", posEncontrada);
        }else if (resto == 2) {
            printf("Disparo certeiro: O encouraçado %d afundou\n", posEncontrada);
        }else if (resto == 3) {
            printf("Disparo certeiro: O cruzador %d afundou\n", posEncontrada);
        }else if (resto == 4) {
            printf("Disparo certeiro: A fragata %d afundou\n", posEncontrada);
        }else if (resto == 5) {
            printf("Disparo certeiro: O submarino %d afundou\n", posEncontrada);
        }
    }
}

void Results(int alvo, int achou){
    int resto = alvo % 10;
    if (achou == 1){
        switch (resto)
        {
        case 1:
            printf("Disparo certeiro: O porta aviões %d afundou\n", alvo);
            break;
        case 2:
            printf("Disparo certeiro: O encouraçado %d afundou\n", alvo);
            break;
        case 3:
            printf("Disparo certeiro: O cruzador %d afundou\n", alvo);
            break;
        case 4:
            printf("Disparo certeiro: A fragata %d afundou\n", alvo);
            break;
        case 5:
            printf("Disparo certeiro: O submarino %d afundou\n", alvo);
            break;
        }
    }
    // deve passar o número de iteraçoes

}