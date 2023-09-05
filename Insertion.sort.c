# AlgProg2
#include <stdio.h>
//troca os elementos menor
void troca(int *a,int *b){
    int temp =*a;
    *a = *b ;
    *b = temp;

}
// ordenar por seleção
void selection(int n,int v[]){
    int i,j,min;
    for(i = 0;i < n-1;i++){
        min = i;
        for(j = i+1 ; j < n;j++){
        if(v[min] >v[j] ){
            min = j;
            troca(&v[i],&v[min]);
        }
       } 
    }    

}
//printar os termos do vetor
void escreva(int l[] ){
    int i;
    for (i = 0; i < 5; i++){
        printf("%d ",l[i]);
        
    }
    printf("\n");
}
//colocar os termos do vetor
void preencher(int l[] ){
    int i;
    for (i = 0; i < 5; i++){
        scanf("%d\n",&l[i]);
        
    }
}
int main(){
    //se quiser uma lista maior altera o tamanho no lugar do "5"
    int l[5];
    printf("Preenchar os 5 elementos\n");
    preencher(l);
    printf("os 5 elementos\n");
    escreva(l);
    selection(5,l);
    printf("os novos 5 elementos\n");
    escreva(l);
    return 0;
}
