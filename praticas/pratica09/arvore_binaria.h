#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H
#include <stdbool.h>

typedef struct arvore_t Arvore;

Arvore* arvore_criar ();
void arvore_inserir( Arvore *a, int valor);
bool arvore_esta_vazia (Arvore *a);
void arvore_destruir (Arvore *a);
void arvore_exibir_pre_ordem (Arvore *a);
void arvore_exibir_em_ordem (Arvore *a);
void arvore_exibir_pos_ordem (Arvore *a);


#endif // ARVORE_BINARIA_H 