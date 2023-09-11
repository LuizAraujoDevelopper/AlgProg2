#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define tamanho 50000
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
void mergesort(long v[],int ini,int fim){
    int meio,i,j,k;
    long vaux[tamanho];
    if(ini < fim){
        meio = (ini+fim)/2;
        mergesort(v,ini,meio);
        mergesort(v,meio+1,fim);
        //intercalar
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
void selection(int n,long v[]){
  int i;
  int min = 0;
  if(n == 1)
  return;
  for(i = 1;i < n;i++){
    if(v[min] > v[i]){
      troca(&v[min], &v[i]);
      min = i;
      }
    }
    selection(n-1,v);
    
}
int main(){
    clock_t ini, fim;
    double tempo;
    long V[tamanho];
    char entrada[10];
    printf("Digite Qual:\n");
    scanf("%s",&entrada);
/*
ORDENAÇÃO POR DIVIDIR E CONSQUISTAR
*/
    if(strcmp(entrada,"Merge") == 0){
        preencher(V,tamanho);
        // marca o começo antes de entrar na função ini = clock();
        ini = clock();
        mergesort(V,0,tamanho-1);
        // marca o fim depois de sair na função
        fim = clock();
        tempo =(double)(fim-ini)/CLOCKS_PER_SEC;
        printf("Tempo por Merge foi %f:\n",tempo);
    } 
/*
ORDENAÇÃO POR iNSERÇÃO
*/
   else if(strcmp(entrada,"Insert") == 0){
        preencher(V,tamanho);
        // marca o começo antes de entrar na função ini = clock();
        ini = clock();
        insert(tamanho,V);
        // marca o fim depois de sair na função
        fim = clock();
        tempo =(double)(fim-ini)/CLOCKS_PER_SEC;
        printf("Tempo  por Insertion foi %f:\n",tempo);
    }
/*
ORDENAÇÃO POR SELEÇAÕ
*/
    else if(strcmp(entrada,"Selection") == 0){
        preencher(V,tamanho);
        // marca o começo antes de entrar na função ini = clock();
        ini = clock();
        selection(tamanho,V);
        // marca o fim depois de sair na função
        fim = clock();
        tempo =(double)(fim-ini)/CLOCKS_PER_SEC;
        printf("Tempo  por Selection foi %f:\n",tempo);
    }

 return 0;
};
