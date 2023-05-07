#include <stdio.h>
#include <stdlib.h>

int busca_linear(int *v){
    int maior_qtde = v[0];
    int maior_nota = 0;
    for(int i = 1; i < 1001; i++){
        if(v[i] >= maior_qtde){ 
            maior_qtde = v[i];
            maior_nota = i;
        }
    }

    return maior_nota;
}

int main(){
    int n;
    scanf("%d", &n);

    int* v = calloc(1001, sizeof(int));
    for(int i = 0; i < n; i++){
        int nota;
        scanf("%d", &nota);
        v[nota]++;
    }

    int maior_nota = busca_linear(v);
    printf("%d\n", maior_nota);

    return 0;
}