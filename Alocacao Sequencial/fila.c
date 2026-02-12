#include <stdio.h>
#include <stdlib.h>
#include "alocacao.h"

int insereFila(fila no){
    int retorno = -2; //retorna -2 se a fila está cheia

    int prov = (r + 1) % (m+1); //Calcula o valor da insercao na fila circular (m+1 pois uso uma variavel global para todos os codigos, situação comum m vale o tamanho total do vetor ex: L[6] m = 6)

    if(prov != f){ //se o proximo valor de insercao nao for o primeiro item a fila nao esta cheio e pode inserir
        r = prov; //retaguarda a ponta pro ultimo item
        fi[r] = no; //insere o no na fila
        retorno = r; //variavel retorna a posicao inserida

        if(f == -1){ //se o primeiro item foi inserido na fila f aponta para 0 (primeira posicao valida)
            f = 0; //frente aponta para 0
        }
    }
    return retorno; //variavel de retorno retorna
}

fila *removeFila(){
    fila *retorno = NULL; //retorna null se nao poder remover

    if(f != -1){ //se a fila nao estiver vazia remove
        retorno = &fi[f]; //retorna o endereço do item a ser removido
        if(f == r){ //se existir um unico tem na fila frente e retaguarda aponta para -1
            f = -1;
            r = -1;
        }else{
            f = (f+1) % (m+1); //caso haja mais itens na lista a apos a remocao, frente tem que apontar pro proximo item da fila
        }
    }
    return retorno; //retorna nulo ou o endereco do no removido
}