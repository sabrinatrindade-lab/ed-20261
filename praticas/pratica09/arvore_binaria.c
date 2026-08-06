#include "arvore_binaria.h"
#include <stdlib.h>
#include <stdio.h> 

typedef struct no_t {
    int valor;
    struct no_t *esq;
    struct no_t *dir;
} No;
typedef struct arvore_t {
    No *raiz;
} Arvore;

Arvore* arvore_criar () {
    Arvore *a = (Arvore*) malloc(sizeof(Arvore));
    a->raiz = NULL;
    return a;
}
bool arvore_esta_vazia (Arvore *a) {
    return a->raiz == NULL;
}
static No* inserir_recursivo(No *raiz, int valor) {
    if (raiz == NULL) {
        No *novo = (No*) malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    if (valor < raiz->valor) {
        raiz->esq = inserir_recursivo(raiz->esq, valor);
    } else {
        raiz->dir = inserir_recursivo(raiz->dir, valor);
    }
    return raiz;
}
void arvore_inserir( Arvore  *a, int valor) {
    a->raiz = inserir_recursivo(a->raiz, valor);
}
static void pre_ordem(No *n) {
    if (n != NULL) {
        printf("%d  ", n->valor);
        pre_ordem(n->esq);
        pre_ordem(n->dir);
    }
}
void arvore_exibir_pre_ordem(Arvore *a) {
    pre_ordem(a->raiz);
    printf("\n");
}
static void em_ordem(No *n) {
    if (n != NULL) {
        em_ordem(n->esq);
        printf("%d  ", n->valor);
        em_ordem(n->dir);
    }
}
void arvore_exibir_em_ordem(Arvore *a) {
    em_ordem(a->raiz);
    printf("\n");
}
static void pos_ordem(No *n) {
    if (n != NULL) {
        pos_ordem(n->esq);
        pos_ordem(n->dir);
        printf("%d  ", n->valor);
    }
}
void arvore_exibir_pos_ordem(Arvore *a) {
    pos_ordem(a->raiz);
    printf("\n");
}
static void destruir_recursivo(No *n) {
    if (n != NULL) {
        destruir_recursivo(n->esq);
        destruir_recursivo(n->dir);
        free(n);
    }
}
void arvore_destruir (Arvore *a) {
    destruir_recursivo(a->raiz);
    free(a);
}