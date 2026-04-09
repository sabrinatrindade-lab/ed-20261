#ifndef  CONTA_H
#define  CONTA_H

typedef struct conta conta_t;
conta_t* conta_criar(int numero, double saldo_inicial);
void conta_depositar(conta_t* conta, double valor);
void conta_sacar(conta_t* conta, double valor);
double conta_obter_saldo(conta_t* conta);
void conta_destruir(conta_t* conta);

#endif
