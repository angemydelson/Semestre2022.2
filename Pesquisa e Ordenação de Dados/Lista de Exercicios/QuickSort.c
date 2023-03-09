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

int particiona( int vetor[], int inicio, int fim){
    int posPivo = fim;
    int k = inicio, troque;
    for(int i=inicio; i<fim; i++ ){
        if(vetor[i] <= vetor[posPivo]){
            troque = vetor[i];
            vetor[i] = vetor[k];
            vetor[k] = troque;
            k++;

        }
    }

    if (vetor[k] > vetor[posPivo]){
        troque = vetor[k];
        vetor[k] = vetor[posPivo];
        vetor[posPivo] = troque;
    }
    return posPivo;
    
}

void quickSort( int vetor[], int inicio, int fim){
    int posPivo;
    if (inicio < fim){
        posPivo = particiona( vetor, inicio, fim);
        quickSort(vetor, inicio, posPivo-1);
        quickSort(vetor, posPivo+1, fim);
    }

}



int main(){
    int inicio = 0, fim;
    printf("Digite a quantidade de números\n");
    scanf("%d", &fim);
    // fim -= 1;
    int vetor[fim]; 
    srand(time(0));
    int k = 0;
    while (k < fim)
        vetor[k++] = rand() % 100;
    

    printVetor(vetor, fim);
    quickSort(vetor,inicio, fim-1);
    printVetor(vetor, fim);
    
    return 0;
}