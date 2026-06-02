#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H

#include <stdbool.h>

// Definição do tipo Lista (Ponteiro para a struct que será definida no .c)
typedef struct lista_t* Lista;

// Protótipos das funções solicitadas
Lista lista_criar();
void lista_destruir(Lista l);

bool lista_inserir(Lista l, int valor);
bool lista_remover(Lista l, int valor);
bool lista_buscar(Lista l, int valor);

void lista_exibir(Lista l);
bool lista_esta_vazia(Lista l);

#endif

