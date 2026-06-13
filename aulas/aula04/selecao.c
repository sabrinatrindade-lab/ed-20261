#include <stdlib.h>


int busca_sequencial(int v[], int n ,int valor){
    for(int i = 0; i < n; i++){ // 0(n)
        if(v[i] == valor){
            return i;  
        }
    }
    return -1;
} 
void troca (int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}
int parcionar_vetor(int v[], int inicio, int fim){
     int pivo = v[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++){
        if (v[j] <= pivo){
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[fim]);
    return i + 1;
}
 int quick_select(int v[], int inicio, int fim, int valor){
    // para a recursividade do particionador 
    if (inicio == fim){
      return inicio;
        } 
        int pivo = parcionar_vetor(v, inicio, fim);
        if (v[pivo] == valor){
        return pivo;
        } else if (v[pivo] < valor){
      // procura antes do pivo
        return quick_select(v, inicio, pivo - 1, valor);
     }else {
        // procura depois do pivo
        return quick_select(v, pivo + 1, fim, valor);} 
      
        return + i;
    }
  
    
    