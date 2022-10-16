#include <stdlib.h>
#include <stdio.h>
#include "buscabinaria.h"

int main(){
    int c, m, posDesejada, alvo, posEncontrada;
    TDicionario dicionario;

    scanf("%d %d", &c, &m);

    TDicionario_Inicia(&dicionario);
    printf("chego aqu2i\n");

    for (int i = 0; i < c; i++){
        lerMalhas(m, &dicionario, &posDesejada, &alvo);
        printf("chego aqui\n");
        posEncontrada = TDicionario_find(&dicionario, alvo);
        printf("chego aqui3\n");

        if(posEncontrada != posDesejada){
            printf("Nao foi a posição! desejada: %d encontrada: %d \n", posDesejada, posEncontrada);
        }else if(posDesejada == posEncontrada){
            printf("Achou! desejada: %d encontrada: %d \n", posDesejada, posEncontrada);
        }

    }


    return 0;
}