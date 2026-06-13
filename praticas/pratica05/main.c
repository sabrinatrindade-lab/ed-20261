#include  <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAMANHO 100

int main (){
   
int *vetor = (int *) malloc(TAMANHO * sizeof(int)); 
srand(time(NULL)); // Inicializa a semente para geração de números aleatórios

for ( int i = 0; i < TAMANHO ; i++){
      vetor[i]= rand()%100 ; // Gerar números aleatórios entre 0
       printf("%i, ", vetor[i]);
}  
    printf("\n"); 

    int valor = vetor[0];

    int pos = linear_search(vetor, TAMANHO, valor);
    printf(" valor %d encontrado na posicao %d\n", valor, pos);


    clock_t inicio = clock();
    int k_pos = 25;
    int resultado_valor = quick_select(vetor,0, TAMANHO-1, k_pos); 
clock_t  termino = clock();

float duracao = (float)(termino - inicio) / CLOCKS_PER_SEC;
printf(" 0 elemento na posicao %d (ordenado) é :  %d\n", k_pos, resultado_valor);
printf("levou %f segundos para ser executada\n", duracao);
free(vetor); // Libera a memória alocada para o vetor 

return 0;
}

