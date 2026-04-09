#include <stdio.h> 
double fatorial_recursivo(int n){
    if (n<0){
        printf("fatorial não definido para números negativos\n");
        return -1; 
} 
 if (n == 0 || n == 1){
        return 1;
 }  return n * fatorial_recursivo(n - 1);
    }

int main (){
  
        int n ;
        double fatorial= 1;
        printf("digite um numero inteiro:  ");
        scanf("%d", &n);
         // fatorial ultilizando repetição 
        if (n < 0){
            printf("fatorial não definido para números negativos\n");
        } else {for (int i = 1; i <= n ; i++){
            fatorial *= i;}
            
        printf("o fatorial de %d é %e\n", n, fatorial);
        }  // tempo : O(n). o computador faz um esforço que cresce linearmente conforme o numero aumenta (se n é 10, o laço roda 10 vezes) . 
        // complexidade : o(1)(complexidade constante). 

        // fatorial utilizando recursividade 

        double res_recursivo = fatorial_recursivo(n);
        if (res_recursivo != -1){
            printf("fatorial (recursivo) : %e\n", res_recursivo) ;
        }
    // analise : cada vez que a função chama a si mesma, o computador precisa "pausar" a execução atual e guardar o estado dela em uma pilha (stack). 
    // se você chamar fatorial (100),terá 100 estados empilhados na memória ao mesmo tempo. 
    // classificação : O(n) (complexidade linear de espaço). 
        return 0 ; 
 }