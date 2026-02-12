#include <stdio.h>
#include <stdlib.h>
#include "alocacao.h"

int busca1(int x){
    int i = 0; //Variavel de controle do loop
    int busca = -1; //Variavel de retorno -1 caso nao encontre, caso encontre retorna posicao

    while(i < n){ //Loop para percorrer o vetor
        if(L[i].chave == x){ //Quando encontrar a chave no vetor 
            busca = i; //Salva o valor na variavel busca e encerra o odigo
            break;
        }else{
            i++; //Continua a conferir posicoes futuras
        }
    }
    return busca; //Retorna variavel que armazena posicao do vetor
}

int busca2(int x){
    int i = 0; //Variavel de controle do loop
    L1[n].chave = x; //Armazena a chave que queremos no final do vetor

    while(L1[i].chave != x){ //Percorro todo o vetor enquanto a chave que procuro for diferente da chave atual
        i++; //Incrementa 1 no contador
    }

    if(i != n){ //Ao percorrer o vetor conferimos se a posicao encontrada e diferente da ultima posicao do vetor
        return i; //Caso seja encontramos a chave no vetor e retornamos a posicao
    }else{
        return -1; //Caso nao seja, a chave nao se encontra no vetor e retornamos -1
    }
}
