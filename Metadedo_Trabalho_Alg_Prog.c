#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define tamanho 40000
void preencher(long V[],int n){
    srand(time(NULL));
    int i;
    long x;
    for(i = 0;i < n;i++)
        V[i] = rand();
}
void escreva(long l[],int n){
    int i;
    for (i = 0; i < n; i++){
        printf("%ld ",l[i]);
        
    }
    printf("\n");
}
/*
ORDENAÇÃO POR DIVIDIR E CONQUISTAR
*/
void merge(long v[],int ini, int meio, int fim){
    long vaux[fim];
    int i,j,k;
        i = ini;
        j = meio+1;
        k = ini;
        while(i <= meio && j <= fim){
            if(v[i] < v[j]) {
                vaux[k] = v[i];
                i++;
            } else {
                vaux[k] = v[j];
                j++;
            }
            k++;
        }
        while(i <= meio){
            vaux[k] = v[i];
            i++;
            k++;
        }
        while(j <= fim){
            vaux[k] = v[j];
            j++; 
            k++; 
        }
        for(k = ini; k <= fim;k++){
            v[k] = vaux[k];
        }
    }
void mergesort(long v[],int ini,int fim){
    int meio;
    if(ini < fim){
        meio = (ini+fim)/2;
        mergesort(v,ini,meio);
        mergesort(v,meio+1,fim);
        merge(v,ini,meio,fim);
    }
    
}
        
/*
ORDENAÇÃO POR iNSERÇÃO


*/
void insert(int n, long v[]){
  int i = v[n-1],j = n-2;
  if(n == 1)
  return;
  insert(n-1,v);
  for(j;j >= 0 && v[j] > i;j--) {
        v[j + 1] = v[j];
        
    }
    v[j+1] = i;

}
void troca(long *a,long *b){
    int temp = *a;
    *a = *b;
    *b = temp;

}
/*
ORDENAÇÃO POR SELEÇÃO


*/
void selection(int n, long v[], int j) {
    int i;
    int min =j; 
    if (j >= n - 1)
        return;
    for (i = j + 1; i < n; i++) {
        if (v[min] > v[i]) {
            min = i; 
        }
    }
    troca(&v[min], &v[j]); 
    selection(n, v, j + 1); 
}
int main(){
    clock_t ini, fim;
    double tempo;
    long V[tamanho];
    //section
    preencher(V,tamanho);
    ini = clock();
    selection(tamanho,V,0);
    fim = clock();
    tempo = (double)(fim-ini) * 1000 / CLOCKS_PER_SEC;
        printf("o tempo de selection foi:%lf\n",tempo);

    //insert
    preencher(V,tamanho);

    ini = clock();
    insert(tamanho,V);
    fim = clock();

    tempo = (double)(fim-ini) * 1000 / CLOCKS_PER_SEC;
    printf("o tempo de insert foi:%lf\n",tempo);
    //merge
    preencher(V,tamanho);

    ini = clock();
    mergesort(V,0,tamanho-1);
    fim = clock();
  
    tempo = (double)(fim-ini) * 1000/ CLOCKS_PER_SEC;
    printf("o tempo de merge foi:%lf\n",tempo);
    return 0;
}
