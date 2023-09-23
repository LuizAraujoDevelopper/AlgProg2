//Luiz Guilherme 
//Lucas Liz
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void preencherV(int V[], int v[], int n) {
    srand(time(NULL));
    int i;
    for (i = 0; i < n; i++)
        v[i] = V[i];
}

void preencher(int V[], int n) {
    srand(time(NULL));
    int i;
    for (i = 0; i < n; i++)
        V[i] = rand() % 1000000000;
}

void escreva(int l[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", l[i]);
    }
    printf("\n");
}

void merge(int v[], int ini, int meio, int fim) {
    int *vaux = (int *)malloc((fim - ini + 1) * sizeof(int));
    int i, j, k;
    i = ini;
    j = meio + 1;
    k = 0;
    while (i <= meio && j <= fim) {
        if (v[i] > v[j]) {
            vaux[k] = v[i];
            i++;
        } else {
            vaux[k] = v[j];
            j++;
        }
        k++;
    }
    while (i <= meio) {
        vaux[k] = v[i];
        i++;
        k++;
    }
    while (j <= fim) {
        vaux[k] = v[j];
        j++;
        k++;
    }
    for (k = 0; k < (fim - ini + 1); k++) {
        v[ini + k] = vaux[k];
    }
    free(vaux);
}

void mergesort(int v[], int ini, int fim) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;
        mergesort(v, ini, meio);
        mergesort(v, meio + 1, fim);
        merge(v, ini, meio, fim);
    }
}

void insert(int n, int *v) {
    int i = v[n - 1], j = n - 2;
    if (n == 1)
        return;
    insert(n - 1, v);
    for (j; j >= 0 && v[j] < i; j--) {
        v[j + 1] = v[j];
    }
    v[j + 1] = i;
}

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection(int n, int *v, int j) {
    int i;
    int min = j;
    if (j >= n - 1)
        return;
    for (i = j + 1; i < n; i++) {
        if (v[min] < v[i]) {
            min = i;
        }
    }
    troca(&v[min], &v[j]);
    selection(n, v, j + 1);
}

int particiona(int v[], int inicio, int fim) {
    int pivot = v[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        if (v[j] > pivot) {
            i++;
            troca(&v[i], &v[j]);
        }
    }

    troca(&v[i + 1], &v[fim]);
    return (i + 1);
}
void quick_sort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int pivotIndex = particiona(v, inicio, fim);
        quick_sort(v, inicio, pivotIndex - 1);
        quick_sort(v, pivotIndex + 1, fim);
    }
}

int main() {
    clock_t ini, fim;
    double tempoinsert, temposelection, tempomerge, tempoclick;

    int tamanho;
    int entrada, opcaod, opcaoT;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *V = (int *)malloc(tamanho * sizeof(int));
    int *Vaux = (int *)malloc(tamanho * sizeof(int));

    printf("Deseja usar qual Método(1)merge,(2)quick,(3)insert e (4)selection:");
    scanf("%d", &entrada);

    preencher(V, tamanho);

    while (entrada != 5) {

        if (entrada == 1) {
            printf("Digite (1) para imprimir o Vetor com o Merge ou (2) para ver o tempo de execução:");
            scanf("%d", &opcaod);
            if (opcaod == 1) {
                /*MERGE SORT*/
                printf("MERGE SORT\n");
                preencherV(V, Vaux, tamanho);
                mergesort(Vaux, 0, tamanho - 1);
                printf("Vetor Original:");
                escreva(V, tamanho);
                printf("Vetor ordenado:");
                escreva(Vaux, tamanho);
            } else if (opcaod == 2) {
                preencherV(V, Vaux, tamanho);
                ini = clock();
                mergesort(Vaux, 0, tamanho - 1);
                fim = clock();
                // calcula o tempo do Merge
                tempomerge = (double)(fim - ini) / CLOCKS_PER_SEC;
                printf("O tempo de merge sort foi: %lf ms\n", tempomerge);
            }
        } else if (entrada == 2) {
            printf("Digite (1) para imprimir o Vetor com o Quick ou (2) para ver o tempo de execução:");
            scanf("%d", &opcaod);
            if (opcaod == 1) {
                /*QUICK SORT*/
                printf("QUICK SORT\n");
                preencherV(V, Vaux, tamanho);
                quick_sort(Vaux, 0, tamanho - 1);
                printf("Vetor Original:");
                escreva(V, tamanho);
                printf("Vetor ordenado:");
                escreva(Vaux, tamanho);
            } else if (opcaod == 2) {
                preencherV(V, Vaux, tamanho);
                ini = clock();
                quick_sort(Vaux, 0, tamanho - 1);
                fim = clock();
                // calcula o tempo do Quick
                tempoclick = (double)(fim - ini) / CLOCKS_PER_SEC;
                printf("O tempo do quick foi: %lf ms\n", tempoclick);
            }
        } else if (entrada == 3) {
            printf("Digite (1) para imprimir o Vetor com o Insert ou (2) para ver o tempo de execução:");
            scanf("%d", &opcaod);
            if (opcaod == 1) {
                /*INSERT SORT*/
                printf("INSERT SORT\n");
                preencherV(V, Vaux, tamanho);
                insert(tamanho, Vaux);
                printf("Vetor Original:");
                escreva(V, tamanho);
                printf("Vetor ordenado:");
                escreva(Vaux, tamanho);
            } else if (opcaod == 2) {
                preencherV(V, Vaux, tamanho);
                ini = clock();
                insert(tamanho, Vaux);
                fim = clock();
                // calcula o tempo do insert
                tempoinsert = (double)(fim - ini) / CLOCKS_PER_SEC;
                printf("O tempo de insert foi: %lf ms\n", tempoinsert);
            }
        } else if (entrada == 4) {
            printf("Digite (1) para imprimir o Vetor com o Select ou (2) para ver o tempo de execução:");
            scanf("%d", &opcaod);
            if (opcaod == 1) {
                /*SELECTION SORT*/
                printf("SELECTION SORT\n");
                preencherV(V, Vaux, tamanho);
                selection(tamanho, Vaux, 0);
                printf("Vetor Original:");
                escreva(V, tamanho);
                printf("Vetor ordenado:");
                escreva(Vaux, tamanho);
            } else if (opcaod == 2) {
                preencherV(V, Vaux, tamanho);
                ini = clock();
                selection(tamanho, Vaux, 0);
                fim = clock();
                // calcula o tempo do selection
                temposelection = (double)(fim - ini) / CLOCKS_PER_SEC;
                printf("O tempo de selection foi: %lf ms\n", temposelection);
            }
        }

        printf("Digite 5 para sair ou Método a ser usado novamente (1)merge,(2)quick,(3)insert e (4)selection:");
        scanf("%d", &entrada);
    }

    free(V);
    free(Vaux);
    return 0;
}
