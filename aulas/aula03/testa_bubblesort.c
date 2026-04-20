#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "ordenacao.h"
#define TAMANHO 10000

int main (){
    int vetor[TAMANHO];
    for (int i = 0; i < TAMANHO ; i++){
        vetor[i]= rand();
    }
    
    imprimir_vetor(vetor, TAMANHO);
    clock_t inicio = clock();
    bubble_sort(vetor, TAMANHO);
    clock_t termino = clock();

    float duracao = (float) (termino - inicio)/ CLOCKS_PER_SEC;
    
    printf("vetor depois da ordenar\n");
      printf("vetor depois da ordenar em %f segundos\n", duracao);
    imprimir_vetor(vetor, TAMANHO);
return 0;
}