
#include "LD_Header.h"

int main (){

    t_lista* lista = aloca_lista();

    inserir_final ("Russia", 33, 44 , 45, 12, lista);

    imprime_lista (lista);

    apaga_lista (lista);

    return 0;

}