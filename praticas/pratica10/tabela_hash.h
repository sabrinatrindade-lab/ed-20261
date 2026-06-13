#ifndef TABELA_HASH_H
#define TABELA_HASH_H
#include <stdbool.h>

typedef struct hash_t TabelaHash;

TabelaHash *hash_criar(int tamanho);
void hash_inserir(TabelaHash *tabela, int valor);
void hash_buscar(TabelaHash *tabela, int valor);
void hash_remover(TabelaHash *tabela, int valor);
void hash_exibir(TabelaHash *tabela);
bool hash_esta_vazia (TabelaHash *tabela);
void hash_destruir(TabelaHash *tabela);

#endif // TABELA_HASH_H