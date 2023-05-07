#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define new_pos(POS, J) (POS + J*J + 23*J) % 101

typedef struct cell{
    char* key;
    int empty;
}cell;

int hash(char* key){
    int num = 0;
    int mult = 1;
    while(*key != '\0'){
        num += (int) (*key)*mult;
        mult++;
        key = key + 1;
    }
    num = num*19;

    num =  num % 101;
    return num;

}

int colision(cell* tab, char* key, int pos){
    for(int j = 1; j <= 19; j++){
        int new_pos = new_pos(pos, j);
        if(tab[new_pos].empty == 0){
            tab[new_pos].key = key;
            tab[new_pos].empty = 1;
            return 1;
        }
    }
    return 0;

}

int insert_key(cell* tab, char* key){
    for(int i = 0; i < 101; i++){
        if(tab[i].empty == 0) continue;
        if(strcmp(tab[i].key, key) == 0){
            return 0;
        }
    }
    
    int pos = hash(key);
    if(tab[pos].empty == 0){
        tab[pos].key = key;
        tab[pos].empty = 1;
        return 1;
    }
    return colision(tab, key, pos);

}

int del_key(cell* tab, char* key){
    for(int i = 0; i < 101; i++){
        if(tab[i].empty == 0) continue;
        if(strcmp(tab[i].key, key) == 0){
            free(tab[i].key);
            tab[i].empty = 0;
            return 1;
        }
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        cell* tab = malloc(sizeof(cell)*101);
        for(int i = 0; i < 101; i++){
            tab[i].empty = 0;
        }
        int m;
        scanf("%d", &m);
        int amount = 0;
        for(int j = 0; j < m; j++){
            char op[30];
            scanf(" %s", op);
            
            char* aux = op + 4;
            char* key = malloc(sizeof(char)*15);
            int k = 0;
            while(*aux != '\0'){
                key[k++] = *aux;
                aux = aux + 1;
            }
            
            if(op[0] == 'A'){
                amount += insert_key(tab, key);
            }
            else{
                amount -= del_key(tab, key);
            }
        }
        printf("%d\n", amount);
        for(int i = 0; i < 101; i++){
            if(tab[i].empty != 0) printf("%d:%s\n", i, tab[i].key);
        }
        free(tab);

    }

    return 0;
}