#include <stdio.h>
#include <stdlib.h>
#include "avl_2.h"



int main() {

	Arv_AVL *raiz;//ponteiro de ponteiro pra raiz 

	raiz = aloca_arvore();//alocando ponteiro de ponteiro na raiz da arvore 

	inseri_AVL(raiz, 9);

	inseri_AVL(raiz, 7);

	inseri_AVL(raiz, 2);

	inseri_AVL(raiz, 13);

	inseri_AVL(raiz, 15);

	mostra_arvore(raiz);

	libera_arvore(raiz);



	return 0;
}