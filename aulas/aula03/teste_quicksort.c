#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "ordenacao.h"
#define TAMANHO 1000

int main (){
    int vetor[TAMANHO];
    for (int i = 0; i < TAMANHO ; i++){
        vetor[i]= rand()%100;
    }
    
    imprimir_vetor(vetor, TAMANHO);
    clock_t inicio = clock();

    quick_sort(vetor, 0, TAMANHO - 1);
    clock_t termino = clock();

    float duracao = (float) (termino - inicio)/ CLOCKS_PER_SEC;
    printf("vetor depois da ordenar\n");


    imprimir_vetor(vetor, TAMANHO);
    printf("vetor depois da ordenar em %f segundos\n", duracao);
    
return 0;
}
