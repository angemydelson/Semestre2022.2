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

void selectionSort( int vetor[], int n){
    int troco;
    printVetor(vetor,n);

    for (int i=n-1; i > 1; i--){
        for (int j = 0; j<n-1; j++){
            if (vetor[j]>vetor[j+1]){
                troco = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = troco;


            }
        }
        
    }

    printVetor(vetor,n);

}

int main(){
    int n;
    printf("Digite a quantidade de números\n");
    scanf("%d", &n);
    int vetor[n]; 
    srand(time(0));
    int k = 0;
    while (k < n)
        vetor[k++] = rand() % 100;

    selectionSort(vetor,n);
    
    return 0;
}