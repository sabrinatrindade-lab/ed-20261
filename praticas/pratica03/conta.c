#include "conta.h"
#include <stdlib.h>
struct conta {
    int numero;
    double saldo;
};

conta_t* conta_criar(int numero, double saldo_inicial) {
    conta_t* conta = (conta_t*)malloc(sizeof(conta_t));
    if (conta != NULL) {
        conta->numero = numero;
        conta->saldo = saldo_inicial;
    }
    return conta;
}

void conta_depositar(conta_t* conta, double valor) {
    if (conta != NULL && valor > 0) {
        conta->saldo += valor;
    }
}

void conta_sacar(conta_t* conta, double valor) {
    if (conta != NULL && valor > 0 && conta->saldo >= valor) {
        conta->saldo -= valor;
    }
}

double conta_obter_saldo(conta_t* conta) {
    if (conta != NULL) {
        return conta->saldo;
    }
    return 0;
}

void conta_destruir(conta_t* conta) {
    if (conta != NULL) {
        free(conta);
    }
}