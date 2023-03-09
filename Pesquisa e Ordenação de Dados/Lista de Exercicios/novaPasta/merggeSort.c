#include<stdio.h>
#include<stdlib.h>
void printF(int vetor[], int n){
     for(int i = 0; i <= n-1; i++){
        printf("%d", vetor[i]);
    }
}


void intercalar (int vetor[], int inicio, int meio, int fim, int n){
    int auxiliar[fim - inicio+1];

    int i = inicio;
    int j = meio + 1;
    int k = 0;

    while(i <= meio && j <= fim){
        if(vetor[i] <= vetor[j]){
            auxiliar[k] = vetor[i];
            i++;
        }else{
            auxiliar[k] = vetor[j];
            j++;
        }
        k++;
    }

    while (i <= meio){
        auxiliar[k] = vetor[j];
        k++;
        j++;
    }
    for(k = inicio; k <= fim; k++){
        vetor[k] = auxiliar[k-inicio];
    }
    
}

void mergeSort(int vetor[], int inicio, int fim, int n){
    int meio;
    if (inicio < fim){
        meio = (inicio + fim)/2;
        mergeSort (vetor, inicio, meio, n);
        mergeSort (vetor, meio+1, fim, n);
        intercalar(vetor, inicio, meio, fim, n);
    }
}

int main(){
    int n, inicio, fim;
    int vetor[n];
    printf("Digite o valor da n\n");
    scanf("%d", &n);
    printf("Digite o valor do inicio\n");
    scanf("%d", &inicio);
    printf("Digite o valor do fim\n");
    scanf("%d", &fim);

    for(int i = inicio; i <= n-1; i++){
        printf("Digite os valores\n");
        scanf("%d", &vetor[i]);
    }

    printF(vetor, n);
    mergeSort(vetor,inicio,fim, n);
    printF(vetor, n);

}