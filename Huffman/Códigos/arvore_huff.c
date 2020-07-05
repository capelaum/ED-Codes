
// Arquivo contendo as funcoes da Arvore implementada

#include "arvore_huff.h"

//=======================================================

// Aloca o nos folhas da arvore de Huffman
t_no_h* aloca_no_folha (int freq, char simbolo){ 
    
    t_no_h* ptr  = (t_no_h*) malloc (sizeof(t_no_h));

    ptr->simb    = simbolo;
    ptr->freq    = freq;

    ptr->dir     = NULL;
    ptr->esq     = NULL;

    return ptr;

}

//=======================================================

// Aloca os nos internos da arvore
t_no_h* aloca_no_raiz ( t_no_h* ptr1, t_no_h* ptr2 ){

    t_no_h* ptr = (t_no_h*) malloc (sizeof(t_no_h));

    ptr->simb = ' ';
    ptr->freq = ptr1->freq + ptr2->freq;

    ptr->esq = ptr1;
    ptr->dir = ptr2;

    return ptr;
}

//=======================================================

// Imprime em pre_ordem 
void pre_ordem (t_no_h* raiz) {

   if(raiz != NULL){
      printf ("%c - %d\n",raiz->simb, raiz->freq);
      pre_ordem (raiz->esq);
      pre_ordem (raiz->dir);
   }

}

//=======================================================

// Retorna quantidade de nos em uma arvore
int qtd (t_no_h* raiz) {
	
    if (raiz == NULL) 
		return false;
	 else 
		return ( qtd(raiz->esq) + 1 + qtd(raiz->dir) );

}

//=======================================================

// Libera memória alocada por toda a árvore
void libera_arvore (t_no_h*raiz){

    if (raiz == NULL) return;

    // deleta as subarvores
    libera_arvore(raiz->esq);
    libera_arvore(raiz->dir);

    // deleta os nos das folhas e os pais sucessivamente
    //printf("Deletando no: %c %d\n",raiz->simb, raiz->freq);

    free (raiz);
    
}

//=======================================================