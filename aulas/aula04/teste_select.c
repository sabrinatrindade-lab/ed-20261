#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "selecao.h"

#define TAMANHO 10

int main (){
   
     int *vetor = (int *) malloc(TAMANHO * sizeof(int)); 

for ( int i = 0; i < TAMANHO ; i++){
      vetor[i]= rand()%100 ; // Gerar números aleatórios entre 0
       printf("%i, ", vetor[i]);
}  
 printf("\n");
//printf("primeiro = %i, ultimo= %i\n", vetor[0], vetor[TAMANHO-1]);

 int valor ;
printf("entre com um numero para buscar : ");
scanf("%i", &valor);
clock_t inicio = clock();
 int achou = quick_select(vetor,0, TAMANHO-1, valor);
clock_t  termino = clock();

float duracao = (float)(termino - inicio) / CLOCKS_PER_SEC;
printf(" A busca pelo valor %i resultou em %i\n", valor, achou);
printf("levou %f segundos para ser executada\n", duracao);


return 0;

}