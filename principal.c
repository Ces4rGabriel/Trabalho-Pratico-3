#include <stdlib.h>
#include <stdio.h>
#include "buscabinaria.h"

int main(){
    int casos, malhas, posDesejada, alvo, aux, posEncontrada = -1;
    TDicionario dicionario;

    scanf("%d %d", &casos, &malhas);

    TDicionario_Inicia(&dicionario, malhas);
    printf("Dicionario inicializado\n");

    for (int i = 0; i < casos; i++){
        lerMalhas(malhas, &dicionario, &posDesejada, &alvo);
        //printf("chequei malhas\n");
        aux = CheckPos(&dicionario, posDesejada, alvo); //checa se o jogador acertou o alvo
            if(aux >= 0){ // se acertou
                    Results(alvo, 1);
                continue;
            }else{ // se errou
                posEncontrada = TDicionario_find(&dicionario, alvo); // retornando a posição do alvo
                printf("%d", dicionario.cont);
                exibeResultado(alvo, posEncontrada);
            }
        //se não acertou procura o alvo
        //posEncontrada = TDicionario_find(&dicionario, alvo, posDesejada, aux);
        //printf("encontrei\n");
        //exibeResultado(posDesejada, posEncontrada);
    }


    return 0;
}