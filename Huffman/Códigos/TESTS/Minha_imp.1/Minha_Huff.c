
// Main da minha implementação de Huffman

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Lista_S.h"
#include "arvore_huff.h"


int main() {

    t_lista* lista = aloca_lista ();

    inserir_ordenado (1, 'n', lista);
    inserir_ordenado (1, 'a', lista);
    inserir_ordenado (1, 'm', lista);
    inserir_ordenado (2, 'f', lista);
    inserir_ordenado (1, 'u', lista);
    inserir_ordenado (1, 'H', lista);

    printf("======================================\n");
    imprime_lista    (lista);
    printf("======================================\n");
    printf("Começa contrução da arvore de huffman:\n\n");
    printf("Lista a cada passo: \n");
    printf("======================================\n");

    t_no_h* ptr1;
    t_no_h* ptr2;

    int contador = 1;

// Passo 1
//=============================================================================================   

    ptr1 =  aloca_no_folha (lista->primeiro->freq, lista->primeiro->simbolo);
    ptr2 =  aloca_no_folha (lista->primeiro->prox->freq, lista->primeiro->prox->simbolo);
        
    t_no_h* raiz =  aloca_no_raiz ( ptr1, ptr2 );

    remove_primeiro  (lista);
    remove_primeiro  (lista);


    inserir_ordenado (raiz->freq, raiz->simb, lista);
 

    printf("Passo %d\n\n", contador++);

    imprime_lista    (lista);
    printf("======================================\n");

// Passo 2
//=============================================================================================
    ptr1 =  aloca_no_folha (lista->primeiro->freq, lista->primeiro->simbolo);
    ptr2 =  aloca_no_folha (lista->primeiro->prox->freq, lista->primeiro->prox->simbolo);
        
    t_no_h* raiz_1 =  aloca_no_raiz ( ptr1, ptr2 );

    remove_primeiro  (lista);
    remove_primeiro  (lista);

    inserir_ordenado (raiz_1->freq, raiz_1->simb, lista);

    printf("Passo %d\n\n", contador++);

    imprime_lista    (lista);
    printf("======================================\n");

// Passo 3
//=============================================================================================
    ptr1 =  aloca_no_folha (lista->primeiro->freq, lista->primeiro->simbolo);
        
    t_no_h* raiz_2 =  aloca_no_raiz ( ptr1, raiz_1 );

    remove_primeiro  (lista);
    remove_primeiro  (lista);

    inserir_ordenado (raiz_2->freq, raiz_2->simb, lista);

    printf("Passo %d\n\n", contador++);

    imprime_lista    (lista);
    printf("======================================\n");

// Passo 4
//=============================================================================================
    ptr2 =  aloca_no_folha (lista->primeiro->prox->freq, lista->primeiro->prox->simbolo);
        
    t_no_h* raiz_3 =  aloca_no_raiz ( raiz, ptr2 );

    remove_primeiro  (lista);
    remove_primeiro  (lista);

    inserir_ordenado (raiz_3->freq, raiz_3->simb, lista);

    printf("Passo %d\n\n", contador++);

    imprime_lista    (lista);
    printf("======================================\n");

// Passo 5
//=============================================================================================
        
    t_no_h* raiz_4 =  aloca_no_raiz ( raiz_2, raiz_3 );

    remove_primeiro  (lista);
    remove_primeiro  (lista);

    inserir_ordenado (raiz_4->freq, raiz_4->simb, lista);

    printf("Passo %d\n\n", contador++);

    imprime_lista    (lista);
    printf("======================================\n");
//=============================================================================================

int cont = 1;
printf("Imprime elementos de cada raiz:\n");
printf("======================================\n");
    printf("Quantidade de nos na arvore raiz: %d\n", qtd (raiz) );
    
    pre_ordem (raiz);
printf("======================================\n");
    printf("Quantidade de nos na arvore raiz_%d: %d\n",cont++, qtd (raiz_1) );
    
    pre_ordem (raiz_1);
printf("======================================\n");
    printf("Quantidade de nos na arvore raiz_%d: %d\n",cont++, qtd (raiz_2) );
    
    pre_ordem (raiz_2);
printf("======================================\n");
    printf("Quantidade de nos na arvore raiz_%d: %d\n",cont++, qtd (raiz_3) );
    
    pre_ordem (raiz_3);
printf("======================================\n");
    printf("Quantidade de nos na arvore raiz_%d: %d\n",cont++, qtd (raiz_4) );
    
    pre_ordem (raiz_4);
printf("======================================\n");   

// Arvore feita!

// Finaliza Lista

    apaga_lista (lista);

// Caminhos

    printf("Imprimindo caminhos da arvore:\n");

    imprime_caminhos (raiz_4);
printf("======================================\n");

    libera_arvore    (raiz_4);
	
    
    return 0;

}// end main ()

