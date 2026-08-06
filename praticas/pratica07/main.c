#include <stdio.h>
#include "pilha.h"

int main() {
    // 1. Criar a pilha
    Pilha minha_pilha = pilha_criar();
    printf("--- Testando a Pilha ---\n");

    // 2. Empilhar elementos
    printf("Empilhando: 10, 20, 30\n");
    pilha_empilhar(minha_pilha, 10);
    pilha_empilhar(minha_pilha, 20);
    pilha_empilhar(minha_pilha, 30);

    // 3. Exibir a pilha
    pilha_exibir(minha_pilha);

    // 4. Consultar o topo
    printf("Elemento no topo atual: %d\n", pilha_topo(minha_pilha));

    // 5. Desempilhar elementos
    printf("Desempilhando um elemento: %d\n", pilha_desempilhar(minha_pilha));
    pilha_exibir(minha_pilha);

    printf("Desempilhando outro elemento: %d\n", pilha_desempilhar(minha_pilha));
    pilha_exibir(minha_pilha);

    // 6. Destruir a pilha no final
    pilha_destruir(minha_pilha);
    printf("Pilha destruída com sucesso!\n");

    return 0;
}