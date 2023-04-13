#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca (celula *le, int x){
    while(le != NULL && le->dado != x) le = le->prox;
    return le;
}

celula *busca_rec (celula *le, int x){
    if(le == NULL) return le;
    if(le->dado == x) return le;
    return busca_rec(le->prox, x);
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

    celula *res = busca_rec(&le, 5);
    printf("%d\n", res->dado);
    return 0;

}*/