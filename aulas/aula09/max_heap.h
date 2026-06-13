#ifndef MAX_HEAP_H
#define MAX_HEAP_H

typedef struct {
    int* dados;
    int tamanho;
    int capacidade;
} MaxHeap;

MaxHeap* criar(int capacidade);
void destruir(MaxHeap* raiz);
void inserir(MaxHeap* raiz, int valor);
int remover(MaxHeap* raiz);


#endif // MAX_HEAP_H