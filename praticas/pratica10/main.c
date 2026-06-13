#include <stdio.h>
#include "tabela_hash.h"

int main (){

    TabelaHash *tabela = hash_criar(10); // Cria uma tabela hash com tamanho 10

    hash_inserir(tabela, 5);
    hash_inserir(tabela, 18);
    hash_inserir(tabela, 30);
    hash_inserir(tabela, 6);
    hash_inserir(tabela, 23);

    hash_buscar(tabela, 5); // Deve encontrar o valor
    hash_buscar(tabela, 10); // Não deve encontrar o valor
    hash_buscar(tabela, 30); // Deve encontrar o valor

    hash_remover(tabela, 18);
    hash_buscar(tabela, 18); // Não deve encontrar o valor após remoção
    hash_remover(tabela, 23); 

    hash_destruir(tabela); // Libera a memória alocada para a tabela hash

    return 0;
}