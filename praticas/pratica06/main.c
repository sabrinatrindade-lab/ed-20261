#include <stdio.h>
#include "lista_linear.h"

int main() {
    // 1. Criar a lista
    Lista minha_lista = lista_criar();
    printf("--- Testando Lista Linear Duplamente Encadeada ---\n");

    // 2. Testar se está vazia
    if (lista_esta_vazia(minha_lista)) {
        printf("A lista iniciou vazia corretamente.\n");
    }

    // 3. Inserir elementos
    printf("\nInserindo valores: 10, 20, 30...\n");
    lista_inserir(minha_lista, 10);
    lista_inserir(minha_lista, 20);
    lista_inserir(minha_lista, 30);

    // 4. Exibir a lista
    printf("Conteudo da lista: ");
    lista_exibir(minha_lista);

    // 5. Testar a busca
    int valor_busca = 20;
    if (lista_buscar(minha_lista, valor_busca)) {
        printf("\nO valor %d foi encontrado na lista!\n", valor_busca);
    } else {
        printf("\nO valor %d NAO foi encontrado.\n", valor_busca);
    }

    // 6. Testar a remocao
    printf("\nRemovendo o valor 20...\n");
    lista_remover(minha_lista, 20);
    
    printf("Lista apos a remocao: ");
    lista_exibir(minha_lista);

    // 7. Destruir a lista (Liberar memoria)
    printf("\nLimpando memoria e finalizando...\n");
    lista_destruir(minha_lista);

    return 0;  