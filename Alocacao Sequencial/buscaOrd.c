#include <stdio.h>
#include <stdlib.h>
#include "alocacao.h"

int buscaOrd(int x){
    int i = 0; //indice inicial
    L1[n].chave = x; //guardo o valor no fim do vetor

    while(L[i].chave < x){ //enquanto o valor for menor percorro ovetor
        i++;
    }

    if(i == n || L[i].chave != x){ //se a chave é a ultima do vetor a posicao que encontrei for diferente do x retorna -1
        return -1;
    }else{
        return i; //retorna posicao encontrada caso ela seja valida
    }
}