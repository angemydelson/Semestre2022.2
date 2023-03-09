#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>

void criarHeap(int vetor[],int n, int i){
    int maior,troque,ladoEsquerda, ladoDireita;

    maior = i;
    ladoEsquerda = 2 * i + 1;
    ladoDireita = 2 * i + 2;

    if (ladoEsquerda < n && vetor[ladoEsquerda] > vetor[maior]){
        maior = ladoEsquerda;
    }

    if ( ladoDireita < n && vetor[ladoDireita] > vetor[maior]){
        maior = ladoDireita;
    }

    if(maior != i){
        troque = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = troque;
        criarHeap(vetor, n, maior);
    }

}

void heapSort(int vetor[], int n){
    int aux;
    for(int i = n /2 - 1; i >= 0; i--){
        criarHeap(vetor, n, i);
    }

    for(int k = n - 1; k >= 0; k--){
        aux = vetor[0];
        vetor[0] = vetor[k];
        vetor[k] = aux;
        criarHeap(vetor, k, 0);
    }
}

void printVetor(int vetor[],int n){
    for (int i=0; i<n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}




int main(){
    int n;
    printf("Digite a quantidade de números\n");
    scanf("%d",&n);
    int vetor[n];

    srand(time(0));
    int k = 0;
    while (k < n)
        vetor[k++] = rand() % 100;

    printVetor(vetor,n);
    heapSort(vetor, n);
    printVetor(vetor,n);

}
