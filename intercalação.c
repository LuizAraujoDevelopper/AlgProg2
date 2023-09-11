#include <stdio.h>
void escreva(int l[],int n){
    int i;
    for (i = 0; i < n; i++){
        printf("%d ",l[i]);
        
    }
    printf("\n");
}
// algoritmo que intercala
void merge(int v1[],int tmv1, int v2[],int tmv2, int vetor[]){
    int i = 0,j=0;
    while(i < tmv1 && j < tmv2){
        if(v1[i] < v2[j]){vetor[i+j] = v1[i];i++;}
        else{vetor[i+j] = v2[j];j++;}
        }
        while(i < tmv1){
            vetor[i+j] = v1[i];
            i++;
        }
        while(j < tmv2){
            vetor[i+j] = v2[j];
            j++;  
        }
    }
int main(){
    int V1[8] = {2,10,15,30,40,50,60,90};
    int V2[6] = {1,3,5,55,91,92};
    int V3[14];
    merge(V1,8,V2,6,V3);
    escreva(V3,14);

    return 0;
}
