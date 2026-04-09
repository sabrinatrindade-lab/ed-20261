#include <stdio.h>
#include "conta.h"

int main() {
    conta_t* minha_conta = conta_criar(12345, 1000.0);
    if (minha_conta == NULL) {
        printf("Erro ao criar a conta.\n");
        return 1;
    }

    printf("Saldo inicial: %.2f\n", conta_obter_saldo(minha_conta));

    conta_depositar(minha_conta, 500.0);
    printf("Saldo após depósito: %.2f\n", conta_obter_saldo(minha_conta));

    conta_sacar(minha_conta, 200.0);
    printf("Saldo após saque: %.2f\n", conta_obter_saldo(minha_conta));

    conta_destruir(minha_conta);
    return 0;

 }