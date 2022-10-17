#include <stdlib.h>
#include <stdio.h>
#include "buscabinaria.h"

int main(){
    int c, m, posDesejada, alvo, posEncontrada = -1;
    TDicionario dicionario;

    scanf("%d %d", &c, &m);

    TDicionario_Inicia(&dicionario);
    printf("Dicionario inicializado\n");

    for (int i = 0; i < c; i++){
        lerMalhas(m, &dicionario, &posDesejada, &alvo);
        printf("chequei malhas\n");
        posEncontrada = TDicionario_find(&dicionario, alvo);
        printf("encontrei\n");
        exibeResultado(posDesejada, posEncontrada);
    }


    return 0;
}