#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B)
#define swap(A, B) int t = A; A = B; B = t;
#define cmp_swap(A, B) if(less(A, B)){swap(A, B)}

int separa(int* v, int l, int r){
    if(l >= r) return r;
    int p = v[r];
    int i = l - 1, j = r;
  
    for(;;){
        while(p > v[++i]);
        while(p < v[--j]) if(j == l) break;

        if(i >= j) break;
        swap(v[i], v[j]);
    }

    swap(v[r], v[i]);
    return i;

}

void quicksort(int* v, int l, int r){
    if(l >= r) return;
 
    swap(v[r - 1], v[(l + r)/2]); //v[r - 1] = meio
    //jogar o menor dos 3 em left
    cmp_swap(v[r], v[l]);  // se meio < left, meio vai pra left
    cmp_swap(v[r - 1], v[l]); //se right < (left ou meio), right vai pra left
    //jogar o maior em right
    cmp_swap(v[r], v[r - 1]);


    int pivo = separa(v, l + 1, r - 1);
    quicksort(v, l, pivo - 1);
    quicksort(v, pivo + 1, r);

}

int busca_bin(int* v, int l, int r, int e){
    if(r < l) return -1;
    int meio = (l + r)/2;

    if(v[meio] < e) busca_bin(v, meio + 1, r, e);
    else if(v[meio] > e) busca_bin(v, l, meio - 1, e);
    else return meio;

}

int main(){
    int n;
    scanf("%d", &n);
    int* v = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    quicksort(v, 0, n - 1);

    int num, res;
    while(scanf("%d", &num)!= EOF){
        res = busca_bin(v, 0, n - 1, num);
        if(res != -1) printf("sim\n");
        else printf("nao\n");
    }

    return 0;
}