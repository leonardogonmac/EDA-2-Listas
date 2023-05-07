#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int num;
    char letra;

}no;

int hash(int chave){
    return chave % 30000000;
}


int main(){
    int num, menor = 30000000, maior = -1;;
    char letra;
    no* v = malloc(sizeof(no)*30000000);

    for(int i = 0; i < 30000000; i++){
        v[i].num = -1;
    }

    while(scanf("%d %c", &num, &letra) != EOF){
        if(hash(num) < menor){
            menor = hash(num);
        }
        if(hash(num) > maior){
            maior = hash(num);
        }

        if(v[hash(num)].num == -1){
            v[hash(num)].num = num;
            v[hash(num)].letra = letra;
        }
        else{
            continue;
        }
    }

    for(int i = menor; i <= maior; i++){
        if(v[i].num != 0){
            printf("%c", v[i].letra);
        }
    }
    printf("\n");

    return 0;
}