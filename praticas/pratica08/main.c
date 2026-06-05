#include <stdio.h>
#include "fila.h"

int main() {
    // 1. Criar a fila
    Fila minha_fila = fila_criar();
    printf("--- Testando a Fila ---\n");

    // 2. Enfileirar elementos
    printf("Enfileirando: 45, 21, 03\n");
    fila_enfileirar(minha_fila, 45);
    fila_enfileirar(minha_fila, 21);
    fila_enfileirar(minha_fila, 03);

    // 3. Exibir a fila
    fila_exibir(minha_fila);

    // 4. Consultar o início
    printf("Elemento no início atual: %d\n", fila_inicio(minha_fila));

    // 5. Desenfileirar (deve sair o 45 primeiro, pois foi o primeiro a entrar)
    printf("Desenfileirando um elemento: %d\n", fila_desenfileirar(minha_fila));
    fila_exibir(minha_fila);

    printf("Enfileirando mais um elemento: 40\n");
    fila_enfileirar(minha_fila, 40);
    fila_exibir(minha_fila);

    printf("Desenfileirando outro elemento: %d\n", fila_desenfileirar(minha_fila));
    fila_exibir(minha_fila);

    // 6. Destruir a fila
    fila_destruir(minha_fila);
    printf("Fila destruída com sucesso!\n");

    return 0;
}