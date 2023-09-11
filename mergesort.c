#include <stdio.h>
#define tamanho 14

void escreva(int l[],int n){
    int i;
    for (i = 0; i < n; i++){
        printf("%d ",l[i]);
        
    }
    printf("\n");
}

void mergesort(int v[],int ini,int fim){
    int meio,i,j,k;
    int vaux[tamanho];
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
int main(){
    int V[tamanho] = {13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    printf("vetor old:\n");
    escreva(V,tamanho);
    mergesort(V,0,tamanho-1);
    printf("vetor new:\n");
    escreva(V,tamanho);
 return 0;
};
