#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista_linear.h"

// Struct interna para o nó (conforme solicitado: anterior, valor, proximo)
struct no_t {
    int valor;
    struct no_t* anterior;
    struct no_t* proximo;
};

// Struct interna para a lista (conforme solicitado: primeiro e ultimo)
struct lista_t {
    struct no_t* primeiro;
    struct no_t* ultimo;
};

// Função para criar a lista
Lista lista_criar() {
    Lista l = (Lista) malloc(sizeof(struct lista_t));
    if (l != NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

// Verifica se está vazia
bool lista_esta_vazia(Lista l) {
    return (l == NULL || l->primeiro == NULL);
}

// Inserção (Exemplo de inserção no final da lista)
bool lista_inserir(Lista l, int valor) {
    struct no_t* novo = (struct no_t*) malloc(sizeof(struct no_t));
    if (novo == NULL) return false;

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = l->ultimo; // O anterior do novo é o antigo último

    if (lista_esta_vazia(l)) {
        l->primeiro = novo;
    } else {
        l->ultimo->proximo = novo;
    }
    
    l->ultimo = novo;
    return true;
}

// Exibição dos elementos
void lista_exibir(Lista l) {
    if (lista_esta_vazia(l)) {
        printf("Lista vazia!\n");
        return;
    }
    struct no_t* atual = l->primeiro;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}
bool lista_buscar(Lista l, int valor) {
    if (lista_esta_vazia(l)) return false;
    struct no_t* atual = l->primeiro;
    while (atual != NULL) {
        if (atual->valor == valor) return true;
        atual = atual->proximo;
    }
    return false;
}
bool lista_remover(Lista l, int valor) {
    if (lista_esta_vazia(l)) return false;

    struct no_t* atual = l->primeiro;

    // 1. Procurar o nó que contém o valor
    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }

    // Se não encontrou o valor, retorna false
    if (atual == NULL) return false;

    // 2. Ajustar os ponteiros dos vizinhos
    if (atual->anterior != NULL) {
        // Se não for o primeiro, o próximo do anterior aponta para o próximo do atual
        atual->anterior->proximo = atual->proximo;
    } else {
        // Se for o primeiro, atualiza o início da lista
        l->primeiro = atual->proximo;
    }

    if (atual->proximo != NULL) {
        // Se não for o último, o anterior do próximo aponta para o anterior do atual
        atual->proximo->anterior = atual->anterior;
    } else {
        // Se for o último, atualiza o fim da lista
        l->ultimo = atual->anterior;
    }

     free(atual);
    return true;
}
void lista_destruir(Lista l) {
    if (l != NULL) {
        struct no_t* atual = l->primeiro;
        while (atual != NULL) {
            struct no_t* prox = atual->proximo;
            free(atual); // Apaga o nó
            atual = prox;
        }
        free(l); // Apaga a estrutura da lista
    }
} 