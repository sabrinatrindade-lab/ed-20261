#include <stdio.h> 

int main (){
int vetor[100];
int n = 100;
int busca ;
int encontrado = 0 ; // variavel para indicar se o numero foi encontrado ou não.

for (int i = 0; i < n; i++){
    vetor[i] = i + 1; 
}

printf( "digite um numero inteiro para buscar de (1 a 100) : ");
scanf("%d", &busca);

for (int i = 0; i < n ; i++){
    if (vetor [i] == busca){
        printf("numero encontrado na posição %d\n", i);
        encontrado = 1 ;
        break;
    }  } 
    if (!encontrado){
        printf("numero não encontado \n");
    }
 return 0 ; 
// o melhor caso é quando o numero buscado é o primeiro do vetor,pois o algoritmo faz apenas uma unica comparação e já entra no if, executa o break e termina.
// complexidade : o(1) constante.
// o pior caso é quando o numero buscado é o ultimo do vetor ou não está presente, pois o algoritmo precisa percorrer todo o vetor para encontrar o numero ou concluir que ele não está presente.
// complexidade : o(n) linear.                 
}
