#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

// Definição do tipo Fila como ponteiro para a estrutura oculta
typedef struct fila_t* Fila;


Fila fila_criar();
void fila_enfileirar(Fila f, int valor);
int fila_desenfileirar(Fila f);
int fila_inicio(Fila f);
bool fila_esta_vazia(Fila f);
void fila_exibir(Fila f); // Ajustado para seguir o padrão do TDA Fila
void fila_destruir(Fila f);

#endif 