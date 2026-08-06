#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

// Definindo o tipo Pilha como um ponteiro para a struct interna que ficará no .c
typedef struct pilha_t* Pilha;

// Protótipos das funções exigidas
Pilha pilha_criar();
void pilha_empilhar(Pilha p, int valor);
int pilha_desempilhar(Pilha p);
int pilha_topo(Pilha p);
bool pilha_esta_vazia(Pilha p);
void pilha_exibir(Pilha p);
void pilha_destruir(Pilha p);

#endif 