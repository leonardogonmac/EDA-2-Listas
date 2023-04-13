#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){
    celula* h1 = l1->prox;
    celula* h2 = l2->prox;
    celula* h3 = l3;
    while(h1 != NULL && h2 != NULL){
        if(h1->dado <= h2->dado){
            h3->prox = h1;
            h3 = h3->prox;
            h1 = h1->prox;
        }
        else{
            h3->prox = h2;
            h3 = h3->prox;
            h2 = h2->prox;
        }
    }

    while(h1 != NULL){
        h3->prox = h1;
        h3 = h3->prox;
        h1 = h1->prox;
    }

    while(h2 != NULL){
        h3->prox = h2;
        h3 = h3->prox;
        h2 = h2->prox;
    }

    h3->prox = NULL;

}