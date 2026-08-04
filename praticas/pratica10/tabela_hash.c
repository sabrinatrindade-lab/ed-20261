#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

typedef struct no_t {
  int valor;
    struct no_t *proximo;
} No;

typedef struct hash_t {
    No **tabela; // arrey de ponteiros 
    int tamanho;
} TabelaHash;

TabelaHash *hash_criar(int tamanho) {
    TabelaHash *tabela = (TabelaHash *)malloc(sizeof(TabelaHash));
    if (tabela == NULL) {
        return NULL; // Falha na alocação de memória
    }
    tabela->tamanho = tamanho;
    tabela->tabela = (No **)malloc(tamanho * sizeof(No *));
    if (tabela->tabela == NULL) {
        free(tabela); // Libera a memória alocada para a tabela
        return NULL; // Falha na alocação de memória
    }
    for (int i = 0; i < tamanho; i++) {
        tabela->tabela[i] = NULL; // Inicializa os ponteiros para NULL
    }
    return tabela;
} 
    void hash_inserir(TabelaHash *tabela, int valor) {
    int indice = valor % tabela->tamanho; // Função de hash simples
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL) {
        return; // Falha na alocação de memória
    }
    novo_no->valor = valor;
    novo_no->proximo = tabela->tabela[indice]; // Insere no início da lista
    tabela->tabela[indice] = novo_no; // Atualiza o ponteiro para o novo nó
} 
void hash_buscar(TabelaHash *tabela, int valor) {
    int indice = valor % tabela->tamanho; // Função de hash simples
    No *atual = tabela->tabela[indice];
    while (atual != NULL) {
        if (atual->valor == valor) {
            printf("Valor %d encontrado na tabela hash.\n", valor);
            return;
        }
        atual = atual->proximo; // Move para o próximo nó
    }
    printf("Valor %d não encontrado na tabela hash.\n", valor);
}
void hash_remover(TabelaHash *tabela, int valor) {
    int indice = valor % tabela->tamanho; // Função de hash simples
    No *atual = tabela->tabela[indice];
    No *anterior = NULL;
    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                tabela->tabela[indice] = atual->proximo; // Remove o nó do início da lista
            } else {
                anterior->proximo = atual->proximo; // Remove o nó do meio ou do fim da lista
            }
            free(atual); // Libera a memória do nó removido
            printf("Valor %d removido da tabela hash.\n", valor);
            return;
        }
        anterior = atual; // Move o ponteiro anterior para o nó atual
        atual = atual->proximo; // Move para o próximo nó
    }
    printf("Valor %d não encontrado na tabela hash. Não foi possível remover.\n", valor);
}
void hash_exibir(TabelaHash *tabela) {
    printf("Tabela Hash:\n");
    for (int i = 0; i < tabela->tamanho; i++) {
        No *atual = tabela->tabela[i];
        printf("Índice %d: ", i);
        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximo; // Move para o próximo nó
        }
        printf("NULL\n");
    }
}
bool hash_esta_vazia(TabelaHash *tabela) {
    for (int i = 0; i < tabela->tamanho; i++) {
        if (tabela->tabela[i] != NULL) {
            return false; // A tabela não está vazia
        }
    }
    return true; // A tabela está vazia
}
void hash_destruir(TabelaHash *tabela) {
    for (int i = 0; i < tabela->tamanho; i++) {
        No *atual = tabela->tabela[i];
        while (atual != NULL) {
            No *temp = atual; // Armazena o nó atual para liberar a memória
            atual = atual->proximo; // Move para o próximo nó
            free(temp); // Libera a memória do nó atual
        }
    }
    free(tabela->tabela); // Libera a memória do array de ponteiros
    free(tabela); // Libera a memória da estrutura da tabela hash
}