#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Struct interna para cada nó da pilha
typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;

// Struct interna que controla a pilha (guarda o ponteiro para o topo)
typedef struct pilha_t {
    no_t* topo;
} pilha_t;

// Cria e inicializa a pilha
Pilha pilha_criar() {
    Pilha p = (Pilha)malloc(sizeof(pilha_t));
    if (p != NULL) {
        p->topo = NULL; // Pilha começa vazia
    }
    return p;
}

// Verifica se está vazia
bool pilha_esta_vazia(Pilha p) {
    if (p == NULL || p->topo == NULL) {
        return true;
    }
    return false;
}

// Push: Insere no topo
void pilha_empilhar(Pilha p, int valor) {
    if (p == NULL) return;

    no_t* novo_no = (no_t*)malloc(sizeof(no_t));
    if (novo_no != NULL) {
        novo_no->valor = valor;
        novo_no->proximo = p->topo; // O novo nó aponta para o antigo topo
        p->topo = novo_no;          // O topo agora é o novo nó
    }
}

// Pop: Remove e retorna o elemento do topo
int pilha_desempilhar(Pilha p) {
    if (pilha_esta_vazia(p)) {
        printf("Aviso: Pilha vazia! Não há o que desempilhar.\n");
        return -1; // Retorna um valor de erro
    }

    no_t* no_aux = p->topo;     // Guarda o nó do topo
    int valor = no_aux->valor;  // Guarda o valor para retornar
    p->topo = no_aux->proximo;  // O topo avança para o próximo nó
    free(no_aux);               // Libera a memória do nó removido

    return valor;
}

// Retorna o valor do topo sem remover
int pilha_topo(Pilha p) {
    if (pilha_esta_vazia(p)) {
        printf("Aviso: Pilha vazia! Não há topo.\n");
        return -1;
    }
    return p->topo->valor;
}

// Exibe a pilha do topo até a base
void pilha_exibir(Pilha p) {
    if (pilha_esta_vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    no_t* atual = p->topo;
    printf("Topo -> ");
    while (atual != NULL) {
        printf("[%d] ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

// Libera toda a memória alocada
void pilha_destruir(Pilha p) {
    if (p == NULL) return;

    // Desempilha todo mundo para liberar os nós
    while (!pilha_esta_vazia(p)) {
        pilha_desempilhar(p);
    }
    free(p); // Por fim, libera a estrutura da pilha
}