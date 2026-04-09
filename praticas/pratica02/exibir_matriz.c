#include <stdio.h>
#include <time.h>

int main(){
    int matriz[10][10] ;
    clock_t  t ; 


   
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            matriz[i][j]= i + j ;
        }  }

        // com laços aninhados 
        t = clock();
        for ( int i = 0; i <10; i++){
            for (int j = 0; j < 10; j++){
                int temp = matriz[i][j];
            }
        }
        t = clock() - t ;
        double tempo_aninhado = ((double)t) / CLOCKS_PER_SEC ;

        // laço unico 
        t = clock();
        int *ptr = &matriz[0][0];
        for ( int k = 0; k< 100; k++){
            int temp = *ptr; 
        }
        t = clock() - t ;
        double tempo_unico = ((double)t) / CLOCKS_PER_SEC ;

        printf("tempo gasto (laços aninhados) : %f segundos\n", tempo_aninhado);
        printf("tempo gasto (laço unico) : %f segundos\n", tempo_unico);
//complexidade : o(n^2) para os laços aninhados, pois o numero de operações cresce com o quadrado do tamanho da matriz (10x10 = 100 elementos).
//complexidade : o(n) para o laço unico, pois o numero de operações cresce linearmente com o numero total de elementos (100 elementos).

    return 0;
}