#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    int valor;
}No;

int insereFila1(No no, No L[], int *f, int *r,int m){
    int retorno = -1;
    int prov = (*r + 1) % m;

    if(prov != *f){
        *r = prov;
        L[*r] = no;
        retorno = *r;

        if(*f == -1){
            *f = 0;
        }
    }
    return retorno;
}

No  *removeFila1(No L[], int *f, int *r, int m){
    No *retorno = NULL;

    if(*f != -1){
        retorno = &L[*f];

        if(*f == *r){
            *f = -1;
            *r = -1;
        }else{
            *f = (*f + 1) % m;
        }
    }
    return retorno;
}

int main(){
    int f = -1;
    int r = -1;
    int m = 5;

    No L[5];

    printf("\nValor de f: %d, Valor de r: %d \n", f, r);

    No no;
    no.chave = 1;
    no.valor = 10;
    printf("\nResultado de insercao: %d",insereFila1(no, L, &f, &r, m));

    no.chave = 2;
    no.valor = 20;
    printf("\nResultado de outra insercao: %d",insereFila1(no, L, &f, &r, m));
   
    no.chave = 3;
    no.valor = 30;
    printf("\nResultado de outra insercao: %d",insereFila1(no, L, &f, &r, m));

    no.chave = 4;
    no.valor = 40;
    printf("\nResultado de outra insercao: %d",insereFila1(no, L, &f, &r, m));

    no.chave = 5;
    no.valor = 50;
    printf("\nResultado de outra insercao: %d",insereFila1(no, L, &f, &r, m));

    printf("\nResultado de outra insercao: %d",insereFila1(no, L, &f, &r, m));
    printf("\nValor de f: %d, Valor de r: %d \n", f, r);

    removeFila1(L, &f, &r, m);
    printf("\nValor de f: %d, Valor de r: %d \n", f, r);

    removeFila1(L, &f, &r, m);
    printf("\nValor de f: %d, Valor de r: %d \n", f, r);

    printf("\nResultado de outra insercao: %d",insereFila1(no, L, &f, &r, m));
    printf("\nValor de f: %d, Valor de r: %d \n", f, r);

    printf("\nResultado de outra insercao: %d",insereFila1(no, L, &f, &r, m));
    printf("\nValor de f: %d, Valor de r: %d \n", f, r);

    printf("\nResultado de outra insercao: %d",insereFila1(no, L, &f, &r, m));
    printf("\nValor de f: %d, Valor de r: %d \n", f, r);
    
    return 0;
}