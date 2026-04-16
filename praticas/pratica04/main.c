#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "ordenacao.h"
#define TAMANHO 100

void copiar_vetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
} 
int main(){
    int vetor[TAMANHO];
    srand(time(NULL)); // Inicializa a semente para números aleatórios
    for (int i = 0; i < TAMANHO ; i++){
        vetor[i]= rand()%100; 
    }
    
    int vetor_bubble[TAMANHO];
    int vetor_quick[TAMANHO];
    int vetor_selection[TAMANHO];

    copiar_vetor(vetor, vetor_bubble, TAMANHO);
    copiar_vetor(vetor, vetor_quick, TAMANHO);
    copiar_vetor(vetor, vetor_selection, TAMANHO);

    printf("Vetor original:\n");
    imprimir_vetor(vetor, TAMANHO);

    clock_t inicio = clock();
    bubble_sort(vetor_bubble, TAMANHO);
    clock_t termino = clock();
    float duracao_bubble = (float) (termino - inicio) / CLOCKS_PER_SEC;
    
    printf("Vetor ordenado com Bubble Sort:\n");
    imprimir_vetor(vetor_bubble, TAMANHO);
    printf("Tempo de execução do Bubble Sort: %f segundos\n", duracao_bubble);

    inicio = clock();
    quick_sort(vetor_quick, 0, TAMANHO - 1);
    termino = clock();
    float duracao_quick = (float) (termino - inicio) / CLOCKS_PER_SEC;
    
    printf("Vetor ordenado com Quick Sort:\n");
    imprimir_vetor(vetor_quick, TAMANHO);
    printf("Tempo de execução do Quick Sort: %f segundos\n", duracao_quick);

    inicio = clock();
    selection_sort(vetor_selection, TAMANHO);
    termino = clock();
    float duracao_selection = (float) (termino - inicio) / CLOCKS_PER_SEC;
    
    printf("Vetor ordenado com Selection Sort:\n");
    imprimir_vetor(vetor_selection, TAMANHO);
    printf("Tempo de execução do Selection Sort: %f segundos\n", duracao_selection);
   
    return 0;
}