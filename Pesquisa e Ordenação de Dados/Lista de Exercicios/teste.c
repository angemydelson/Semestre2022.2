#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printVetor(int *vetor,int n){
    for (int i=0; i<n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(){
    int *aux;
    aux = malloc ((10)* sizeof(int));
    int k = 0;
    while (k < 10)
        aux[k++] = rand() % 100;
    
    printVetor(aux,10);
    return 0;
}