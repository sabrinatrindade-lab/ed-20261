#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    Arvore *arvore = arvore_criar();

    arvore_inserir(arvore, 10);
    arvore_inserir(arvore, 5);
    arvore_inserir(arvore, 15);
    arvore_inserir(arvore, 25);
    arvore_inserir(arvore, 18);
    arvore_inserir(arvore, 9);


    printf("Exibicao Pre-Ordem: ");
    arvore_exibir_pre_ordem(arvore);

    printf("Exibicao Em-Ordem: ");
    arvore_exibir_em_ordem(arvore);
     
    printf("Exibicao Pos-Ordem: ");
    arvore_exibir_pos_ordem(arvore);


    return 0;
}