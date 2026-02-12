#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
    int valor;
    int chave;
    struct lista *prox;
}no;


void busca_enc(int x, no **ant, no **pont, no *ptlista){
    *ant = ptlista; *pont = NULL; no *ptr = ptlista->prox;

    while (ptr != NULL){
        
        if (ptr->chave < x){
            *ant = ptr;
            ptr = ptr->prox;
        
        }else if (ptr->chave == x){
            *pont = ptr;
            ptr = NULL;
       
        }else{
            ptr = NULL;
        }              
    }
}


int insere_enc(no *no_insere, no *ptlista){
    int inserir = -1;
    no *ant;  no *pont;
    
    busca_enc(no_insere->chave, &ant, &pont, ptlista);

    if (pont == NULL){
        no_insere->prox = ant->prox;
        ant->prox = no_insere;
        inserir = 0;        
    }
    
    return inserir;
}





int main() {
    return 0;
}

