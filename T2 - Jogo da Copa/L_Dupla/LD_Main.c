
#include "LD_Header.h"



int main (){

    t_lista* lista = aloca_lista ();

    inserir_final ("Rússia", 33, 44 , 45, 12, lista);
    inserir_final ("Brasil", 78, 54 , 85, 93, lista);
    inserir_final ("Dinamarca", 93, 50 , 65, 72, lista);
    inserir_final ("Holanda", 93, 50 , 35, 22, lista);
    inserir_final ("Austrália", 66, 55 , 65, 72, lista);
    inserir_final ("Koreia", 93, 50 , 66, 72, lista);

    imprime_lista (lista);
    
    remove_pos (rand()%lista->qtd ,lista);

    imprime_lista (lista);

    apaga_lista (lista);

    return 0;

}