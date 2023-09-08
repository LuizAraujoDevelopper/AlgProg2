#include <stdio.h>
//troca de valores
void troca(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;

}
//ordenação por recursão
void selection(int n,int v[n]){
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
//coloca os elementos do vetor
void preencher(int n,int v[n]){
    int i;
    for(i = 0; i < n;i++){
    scanf("%d",&v[i]);
  }

}
//printa os elementos
void escreva(int l[]){
    int i;
    for (i = 0; i < 5; i++){
        printf("%d ",l[i]);
        
    }
    printf("\n");
}
int main(void){
  int v[5];
  int n = 5;
  printf("escreva os elementos\n");
  preencher(n,v);
  printf("os elementos\n");
  escreva(v);
  selection(n,v);
  printf("os novos elementos\n");
  escreva(v);
  
  return 0;
}
