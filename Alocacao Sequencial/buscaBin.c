#include <stdio.h>
#include <stdlib.h>
#include "alocacao.h"

int buscaBin(int x){
    int inf = 0, sup = n-1, busca = -1, meio; //variaveis de controle

    while(inf <= sup){ //se o limite inferior for menor ou igual posso procurar
        meio = (inf+sup)/2; //encontro o meio do vetor

        if(L[meio].chave == x){ //se encontrar o item retorno ele
            busca = meio;
            break;
        }else if(L[meio].chave < x){ //se o item for menor procuro no limite superior
            inf = meio + 1;
        }else{
            sup = meio -1; //se o item for menor procuro no limite inferior
        }
    }
    return busca; //retorno o resultado 
}