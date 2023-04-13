#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio (celula *le, int x){
    celula* novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
}

void insere_antes (celula *le, int x, int y){
    celula* novo = malloc(sizeof(celula));
    novo->dado = x;
    
    celula* h = le;
    while(h->prox != NULL && h->prox->dado != y) h = h->prox;
    novo->prox = h->prox;
    h->prox = novo;

}