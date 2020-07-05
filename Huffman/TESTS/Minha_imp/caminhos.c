

#include "arvore_huff.h"

//=======================================================
// Printa todos caminhos possiveis de uma arvore
void imprime_caminhos (t_no_h* raiz) {

    //char binario  [1000];
    char caminhoc [1000];
	int caminho[1000];
	caminhos_recur (raiz, caminho,caminhoc, 0);


}
//=======================================================
/*
Função recursiva de suporte, dado um no, e um array contendo
o caminho da raiz ate a as folhas sem incluir esse no
imprime em tral todos percursos no-raiz.
*/
void caminhos_recur (t_no_h* raiz, int caminho[],char caminhoc[], int caminho_tam){
	
    if (raiz==NULL) 
		return;
		
	// adiciona a frequencia do nó no array de caminho
    // adiciona o simbolo do nó no array de caminhoc
	caminhoc [caminho_tam] = raiz->simb;
    caminho  [caminho_tam] = raiz->freq;
	caminho_tam++;
	
	// se for uma folha, imprime o caminho que levou ate ele
	if (raiz->esq == NULL && raiz->dir == NULL) {
		imprime_caminho (caminho,caminhoc, caminho_tam);
	}
	else {
		
        // senao tenta ambas subarvores

		caminhos_recur (raiz->esq, caminho, caminhoc, caminho_tam);
		caminhos_recur (raiz->dir, caminho, caminhoc, caminho_tam);
	}
}
//=======================================================
// Imprime o array de caminhos em uma linha
void imprime_caminho (int caminho[], char caminhoc[], int tam) {
	
	int i;
	
	for (i=0; i<tam; i++) 
		printf("no '%c' - %d \n",caminhoc[i], caminho[i]);
    
	printf("\n");
}
//=======================================================
/*
tetantiva de pegar os 1 e 0
void printHuffman(node *head, node *parent, char *a, int len) {
    if(head->left == NULL && head->right == NULL) {
        if(parent != NULL && parent->right == head) {
            cout << head->letter << " " << a << "1";
        } else if(parent != NULL && parent->left == head) {
            cout << head->letter << " " << a;
        }
    } else {
        a[len] = '0';
        printHuffman(head->left, head, a, len + 1);
        a[len] = '1';
        printHuffman(head->right, head, a, len + 1);
    }
}
*/