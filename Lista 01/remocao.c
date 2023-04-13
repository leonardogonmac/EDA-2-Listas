#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois (celula *p){
    if(p->prox == NULL) return 0;
    
    celula* lixo = p->prox;
    int n_lixo = lixo->dado;
    p->prox = lixo->prox;
    return n_lixo;
}

void remove_elemento (celula *le, int x){
    celula* h = le;

    while(h->prox != NULL && h->prox->dado != x) h = h->prox;
    if(h->prox == NULL) return;

    celula* lixo = h->prox;
    h->prox = lixo->prox;
}

void remove_todos_elementos (celula *le, int x){
    celula* h = le;
    for(;;){
        while(h->prox != NULL && h->prox->dado != x) h = h->prox;
        if(h->prox == NULL) break;

        celula* lixo = h->prox;
        h->prox = lixo->prox;
    }

}

/*int main(void){
    celula le;
    celula c1, c2, c3, c4;

    c1.dado = 1;
    c2.dado = 2;
    c3.dado = 1;
    c4.dado = 4;

    le.prox = &c1;
    c1.prox = &c2;
    c2.prox = &c3;
    c3.prox = &c4;
    c4.prox = NULL;

    remove_todos_elementos(&le, 1);
    imprime(&le);
    return 0;

}*/