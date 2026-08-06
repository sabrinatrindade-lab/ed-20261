#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Struct interna para cada nó da fila
typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;

// Struct interna que controla a fila com ponteiros para o início e o fim
typedef struct fila_t {
    no_t* inicio;
    no_t* fim;
} fila_t;

// Cria e inicializa a fila
Fila fila_criar() {
    Fila f = (Fila)malloc(sizeof(fila_t));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

// Verifica se a fila está vazia
bool fila_esta_vazia(Fila f) {
    if (f == NULL || f->inicio == NULL) {
        return true;
    }
    return false;
}

// Enfileirar (Enqueue): Insere sempre no FIM da fila
void fila_enfileirar(Fila f, int valor) {
    if (f == NULL) return;

    no_t* novo_no = (no_t*)malloc(sizeof(no_t));
    if (novo_no == NULL) return;

    novo_no->valor = valor;
    novo_no->proximo = NULL; // Como ele será o último, não aponta para ninguém

    if (fila_esta_vazia(f)) {
        // Se a fila estava vazia, o novo nó é tanto o início quanto o fim
        f->inicio = novo_no;
    } else {
        // Se já tinha gente, o antigo fim aponta para o novo nó
        f->fim->proximo = novo_no;
    }
    
    // Atualiza o ponteiro do fim para o novo nó
    f->fim = novo_no;
}

// Desenfileirar (Dequeue): Remove e retorna o elemento do INÍCIO da fila
int fila_desenfileirar(Fila f) {
    if (fila_esta_vazia(f)) {
        printf("Aviso: Fila vazia! Não há o que desenfileirar.\n");
        return -1;
    }

    no_t* no_aux = f->inicio;      // Guarda o nó que vai sair (o primeiro)
    int valor = no_aux->valor;     // Guarda o valor para retornar

    f->inicio = f->inicio->proximo; // O início avança para o próximo nó

    // Se a fila ficou vazia após a remoção, o fim também precisa virar NULL
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(no_aux); // Libera a memória do nó que saiu
    return valor;
}

// Retorna o valor do primeiro elemento sem remover
int fila_inicio(Fila f) {
    if (fila_esta_vazia(f)) {
        printf("Aviso: Fila vazia! Não há elemento no início.\n");
        return -1;
    }
    return f->inicio->valor;
}

// Exibe a fila do início até o fim
void fila_exibir(Fila f) {
    if (fila_esta_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    no_t* atual = f->inicio;
    printf("Inicio -> ");
    while (atual != NULL) {
        printf("[%d] ", atual->valor);
        atual = atual->proximo;
    }
    printf("<- Fim\n");
}

// Libera toda a memória alocada para a fila
void fila_destruir(Fila f) {
    if (f == NULL) return;

    // Vai desenfileirando até esvaziar tudo
    while (!fila_esta_vazia(f)) {
        fila_desenfileirar(f);
    }
    free(f); // Libera a estrutura de controle da fila
}