
// Main da minha implementação de Huffman


#include "Lista_S.h"
#include "arvore_huff.h"


int main() {

    t_lista* lista = aloca_lista ();
    t_no_h* raiz = NULL;

    inserir_ordenado (raiz, 1, 'n', lista);
    inserir_ordenado (raiz, 1, 'a', lista);
    inserir_ordenado (raiz, 1, 'm', lista);
    inserir_ordenado (raiz, 2, 'f', lista);
    inserir_ordenado (raiz, 1, 'u', lista);
    inserir_ordenado (raiz, 1, 'H', lista);

    printf("======================================\n");
    printf("Começa contrução da arvore de huffman \n");
    
    raiz = cria_arvore (lista);
    // Arvore feita! 

    // Finaliza lista
    apaga_lista  (lista);


    printf("======================================\n");

    // Caminhos
    imprime_caminhos (raiz);

    libera_arvore    (raiz);
	return 0;
}// end main ()

