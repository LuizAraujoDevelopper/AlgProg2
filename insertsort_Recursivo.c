#include <stdio.h>
void preencher(int n,int v[n]){
    int i;
    for(i = 0; i < n;i++){
    scanf("%d",&v[i]);
  }

}
void escreva(int l[]){
    int i;
    for (i = 0; i < 5; i++){
        printf("%d ",l[i]);
        
    }
    printf("\n");
}
void insert(int n, int v[]){
  int i = v[n-1],j = n-2;
  if(n == 1)
  return;
  insert(n-1,v);
  for(j;j >= 0 && v[j] > i;j--) {
        v[j + 1] = v[j];
        
    }
    v[j+1] = i;

}

int main(void){
    int v[5];
    int n = 5;
    printf("escreva os elementos\n");
    preencher(n,v);
    printf("os elementos\n");
    escreva(v);
    insert(n,v);
    printf("os novos elementos\n");
    escreva(v);
  
  
  
  
  return 0;
  
}
