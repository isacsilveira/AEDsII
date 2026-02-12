#include <stdio.h>
#include <stdlib.h>
#include "alocacao.h"

int inserePilha(pilha no){
    int retorno = -1; //variavel de retorno

    if (topo != m){ //se a pilha esta cheia nao pode inserir
        topo++; //atualiza o indice do topo
        p[topo] = no; //insere o no na pilha
        retorno = topo; //retorna posicao inserida
    }
    return retorno; //retorna posicao inserida ou invalida
}

pilha *removePilha(){
    pilha *retorno = NULL; //retorno comeca com null

    if (topo != -1){ //se a pilha nao estiver vazia
        retorno = &p[topo]; //prepara o endereco do no removido
        topo--; //diminui o indice do topo
    }
    return retorno; //retorna posicao removida ou nula
}