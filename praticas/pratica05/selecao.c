#include <stdlib.h>


void troca (int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
} 
int linear_search(int v[], int n, int valor){
    for(int i = 0; i < n; i++){
        if(v[i] == valor){
            return i;
        }
    }
    return -1;
}

int particionar_vetor(int v[], int inicio, int fim){
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
    int quick_select(int v[], int inicio, int fim, int k){
        // para a recursividade do particionador 
        if (inicio == fim){
        return v[inicio];
            } 
            int pivo = particionar_vetor(v, inicio, fim);
            if (pivo == k){
            return v[pivo];
            } else if (k < pivo){
        // procura antes do pivo
            return quick_select(v, inicio, pivo - 1, k);
        }else {
            // procura depois do pivo
            return quick_select(v, pivo + 1, fim, k);} 
        
        }