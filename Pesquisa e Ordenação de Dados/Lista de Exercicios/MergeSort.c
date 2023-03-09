#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printVetor(int vetor[],int n){
    for (int i=0; i<n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
void printVetore(int *vetor,int n){
    for (int i=0; i<n; i++){
        printf("i=%d ", vetor[i]);
    }
    printf("\n");
}

void intercala(int vetor[], int inicio, int meio, int fim){
    int *aux;
    aux = malloc ((fim-inicio+1)* sizeof(int));
    int i = inicio;
    int j = meio + 1;
    int k = 0;
   
    while(i<=meio && j<= fim){
        if(vetor[i] <= vetor[j]){
            aux[k] = vetor[i];
            i++;
        } else {
            aux[k] = vetor[j];
            j++;
        }
        k++;
    }
    
    while (i<= meio){
        aux[k] = vetor[i];
        k++;
        i++;
    }

    while (j<=fim){
        aux[k] = vetor[j];
        k++;
        j++;
    }

    for(k=inicio; k<=fim; k++){
        vetor[k] = aux[k-inicio];
    }
    

    free(aux);
    
    
}

void mergeSort( int vetor[], int inicio, int fim){
    int meio;
    if(inicio<fim){
        meio = (inicio+fim)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        intercala(vetor, inicio, meio, fim);
        // printf("meio: %d\n", meio);

    }
    // return vetor;

}


int main(){
    int inicio, fim, n;
    inicio = 0;
    printf("Digite a quantidade de numeros\n");
    scanf("%d", &fim);
    fim -= 1;
    // inicio = 0
    n = fim-inicio+1;
    int vetor[fim-inicio+1]; 
    srand(time(0));
    int k = 0;
    while (k < n)
        vetor[k++] = rand() % 100;

    printVetor(vetor,n);
    mergeSort(vetor,inicio, fim);
    printVetor(vetor,n);

    // int inicio = 0, fim, n;
    // printf("Digite a quantidade de números\n");
    // scanf("%d", &fim);
    // int vetor[fim]; 
    // srand(time(0));
    // int k = 0;
    // while (k < fim)
    //     vetor[k++] = rand() % 100;

    // printVetor(vetor,fim);
    // mergeSort(vetor,inicio, fim);
    // printVetor(vetor,fim);
    
    return 0;
}