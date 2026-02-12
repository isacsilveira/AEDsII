#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int chave;
    int valor;
    struct lista *prox;
}no;
//teste
void buscaLista(no *ptlista, int x, no **ant, no **pont){ //procedimento para apontar os ponteiros para posicao de insercao e remocao corretamente
    no *ptr = ptlista->prox; //ponteiro que que fica a frente no loop
    *ant = ptlista; //ponteiro que marca elemento anterior ao buscado na lista
    *pont = NULL; //ponteiro de "retorno" que diz se encontramos ou nao o elemento
 
    while(ptr != NULL){ //enquanto o item que eu procuro nao for nulo procuro para frente
        if(ptr->chave < x){ //enquanto a chave atual da lista for menor que o que procuro ando para frente
            *ant = ptr; //ant anda pra frente
            ptr = ptr->prox; //ptr anda pra frente
        }else if(ptr->chave == x){ //se eu encontrar o x retorno ele
            *pont = ptr; //ponto olha para o valor buscado
            ptr = NULL; //ptr recebe null para sair do loop
        }else{
            ptr = NULL; //se eu nao encontrar x apos minha chave ja ser maior que meu x saio do loop
        }
    }
}

int insereLista(no *ptlista, no *inserido){
    int retorno = -1; //variavel de retorno
    no *ant; no *pont; //ponteiros auxiliares
    buscaLista(ptlista, inserido->chave, &ant, &pont); //busca coloca os ponteiros corretamente na lista

    if(pont == NULL){ //se pont for NULL nao achei a chave e posso inserir ela
        inserido->prox = ant->prox; //o no aponta para o proximo elemento corretamente
        ant->prox = inserido; //o anterior aponta para o elemento atual 
        retorno = 0; //retorna 0 pois a insercao foi um sucesso
    }
    return retorno; //retorna para main
}

no *removeLista(no *ptlista, int x){
    no *retorno = NULL; //variavel de retorno
    no *ant; no *pont; //ponteiros auxiliares
    buscaLista(ptlista, x, &ant, &pont); //funcao de busca coloca os ponteiros corretamente na lista

    if(pont != NULL){ //se pont nao for nulo eu posso remover algo da lista
        ant->prox = pont->prox; //elemento anterior pula um elemento e aponta para frente
        retorno = pont; //guardo o endereço do elemento a ser removido
    }

    return retorno; //retorna null ou o endereco do elemento
}

void imprimeLista(no *ptlista){
    no *aux = ptlista->prox; //ponteiro auxiliar para percorrer a lista

    while(aux != NULL){ //enquanto eu olhar para um endereço valido eu imprimo ele
        printf("\nChave: %d", aux->chave); //imprime a chave do no atual
        aux = aux->prox; //aponto para o proximo
    }
}

void liberaLista(no *ptlista){
    no *aux = ptlista->prox; //ponteiro auxiliar acessa o primeiro elemento da lista

    while(aux != NULL){ //enquanto meu auxiliar olhar para um elemento valido
       no *aux2 = aux->prox; //um segundo ponteiro auxiliar olha para o proximo elemento valido
        free(aux); //limpo o primeiro elemento da memoria
        aux = aux2; //aux aponta para o atual primeiro elemento apontado por aux2
        printf("\nLimpou no"); //mensagem de debug
    }
    free(ptlista); //limpo o ptlista da memoria
    printf("\n\nLimpou ptlista"); //mensagem de debug
}

no *alocaNo(int x){
    no *novoNo = (no *) malloc(sizeof(no)); //crio um novo no 

    if(novoNo == NULL){ //testo o se o novoNo foi alocado corretamente
        printf("\nErro ao alocar memoria\n"); //mensagem de debug
        return NULL; //retorna null indicando erro de alocacao
    }

    novoNo->chave = x; //coloca meu x na chave do no
    novoNo->prox = NULL; //proximo elemento desse no deve ser nulo para caso ele seja o ultimo elemento da lista

    return novoNo; //retorno o endereco do novoNo
}

int main(){
    no *ptlista = malloc(sizeof(no)); //Cria o no cabeca    
    ptlista->prox = NULL; //lista vazia o primeiro lemento e NULL   

    no *testeDeRemocao = removeLista(ptlista, 2); //teste de remocao sem nada na lista
    if(testeDeRemocao == NULL){
        printf("\nErro na primeira remocao\n"); //mensagem de debug
    }

    free(testeDeRemocao); //limpa o espaco por seguranca
 
    no *no1 = alocaNo(5); //Aloca varios nos para inserir na lista
    no *no2 = alocaNo(10);
    no *no3 = alocaNo(15);
    no *no4 = alocaNo(20);
    no *no5 = alocaNo(30);

    printf("\nResultado de insercao de 5:%d",insereLista(ptlista, no1)); //insercoes e retorno das chamadas de insercao
    printf("\nResultado de insercao de 10:%d",insereLista(ptlista, no2));
    printf("\nResultado de insercao de 15:%d",insereLista(ptlista, no3));
    printf("\nResultado de insercao de 20:%d",insereLista(ptlista, no4));
    printf("\nResultado de insercao de 30:%d\n",insereLista(ptlista, no5));

    imprimeLista(ptlista); //imprime a lista para ver se inseriu corretamente

    printf("\n--------------------\n");

    no *testeRemove = removeLista(ptlista, 5); //remover um item presente na lista
    no *testeRemove2 = removeLista(ptlista, 22); //remover um item que nao esta na lista
    if(testeRemove2 == NULL){ //se a remocao do item que nao esta na lista falhar retorna null
        printf("Remove NULL\n");
    }

    free(testeRemove); //limpa o no de teste de remocao
    free(testeRemove2); //limpa o no de teste de remocao

    imprimeLista(ptlista); //imprime a lista para ver se foi apagado o elemento correto

    no *no6 = alocaNo(25); //novo elemento criado
    printf("\n\nResultado de insere lista:%d\n",insereLista(ptlista, no6)); //insere +1 elemento
    
    imprimeLista(ptlista); //imprime a list atualizada

    no *no7 = alocaNo(15); //novo elemento criado
    printf("\n\nResultado de insere lista:%d\n",insereLista(ptlista, no7)); //tenta inserir na lista um elemento ja existente na lista

    liberaLista(ptlista); //funcao para remover a lista da memoria

    return 0;
}
