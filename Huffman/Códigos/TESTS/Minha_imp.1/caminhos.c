
#include "arvore_huff.h"

//=======================================================
// Imprime todos caminhos possiveis de uma arvore
void imprime_caminhos (t_no_h* raiz) {

   // array com tentativa de armazenar o codigo binario gerado
   // char bin [1000]; 
    char caminhoc [1000];
	int  caminho[1000];

	caminhos_recur (raiz, caminho, caminhoc, 0);

}
//=======================================================
/*
    Função recursiva de suporte, dado um no, e um array contendo
    o caminho da raiz ate a as folhas sem incluir esse no
    imprime todos percursos no-raiz em sucessão da esquerda para direita.
*/
void caminhos_recur (t_no_h* raiz, int caminho[], char caminhoc[], int tam){
	
    if (raiz == NULL) 
		return;
		
	// adiciona a frequencia do nó no array de caminho
    // adiciona o simbolo do nó no array de caminhoc
	caminhoc [tam] = raiz->simb;
    caminho  [tam] = raiz->freq;
	tam++;
	
	// se for uma folha, imprime o caminho que levou ate ele
	if (raiz->esq == NULL && raiz->dir == NULL) {
		imprime_caminho (caminho, caminhoc, tam);
	}
	else {

		// senao tenta ambas subarvores
        // como saber qual subarvore ta sendo utilizada?

		caminhos_recur (raiz->esq, caminho, caminhoc, tam);

		caminhos_recur (raiz->dir, caminho, caminhoc, tam);
        
	}
}
//=======================================================
// Imprime o array de caminhos em uma linha
void imprime_caminho (int caminho[], char caminhoc[], int tam) {
	
	int i;

    printf("==========================\n");
	printf(" Simbolo   |   Frequencia \n");

	for (i=0; i<tam; i++) 
		printf(" '%c'       |       %d \n",caminhoc[i], caminho[i]);
    
	printf("\n");
}
//=======================================================
