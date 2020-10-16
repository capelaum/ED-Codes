#include "Fila.h"

int main (){

    t_fila* fila = aloca_fila();

    inserir_na_fila(333, fila);
    inserir_na_fila(666, fila);
    inserir_na_fila(999, fila);

    ItemType res = remover(fila);

    printf("%d\n", res);

    imprime_fila(fila);

    libera_fila(fila);
    return 0;

}