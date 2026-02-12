#include <stdio.h>
#include <stdlib.h>
#include "alocacao.h"

int insere(No no){
    if (m < n2){
        if (busca2(no.chave) == -1){ //se a chave nao esta na lista pode inserir
            L1[m] = no; //insere o elemento na lista
            m++; //aumenta o tamanho atual da lista
            return m; //retorna o tamanho atual da lista
        }else{
            return -1; //retorna -1 caso o elemento ja exista na lista 
        }
    }else{
        return -2; //retorna -2 caso a lista esteja cheia
    }
}

No *removeLista(int x){
    No *retorno = NULL; //variavel de retorno começa em null
    
    if(m != 0){
        int indice = busca2(x); //variavel que guarda o indice do item a ser removido

        if(indice != -1){ //se o indice for valido remove
            retorno = &L[indice]; //salva o endereço do endereço a ser removido da lista

            for(int i = indice; i < m; i++){ //loop para corrigir os valores dentro da lista
                L[i] = L[i+1]; //salva o proxio valor da lista no valor atual
            }

            m--; //diminui o tamanho atual da lista
        }
    }
    return retorno; //retorna o endereço do item removido
}