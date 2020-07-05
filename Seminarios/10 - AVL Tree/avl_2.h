/*
Aluno : João Victor Cabral de Melo 
Data : 28/05/18
Sobre : Implementação do Algoritmo de Balanceamento de Árvore AVL 

*/
#ifndef __AVL_H__
#define __AVL_H__

typedef struct elemento {

	int dado;//dado da estrutura
	int fator_de_balanceamento;//fator de balanceamento da arvore 
	struct elemento *esq;//estrutura elemento pra esquerda 
	struct elemento *dir;//estrutura elemento pra direita 

}elemento;

typedef struct elemento *Arv_AVL;//ponteiro de ponteiro pra raiz 

elemento *aloca_no(int dado);

Arv_AVL *aloca_arvore();

void libera_no(elemento *no);

void libera_arvore(Arv_AVL *raiz);

int altura(elemento *no);

int calcula_fat_bal(elemento *no);

int fat_bal_no(elemento *no);//retorna o fator de balanceamento do no

void rotacao_LL(Arv_AVL *raiz);

void rotacao_RR(Arv_AVL *raiz);

void rotacao_LR(Arv_AVL *raiz);

void rotacao_RL(Arv_AVL *raiz);

int inseri_AVL(Arv_AVL *raiz, int valor);

void mostra_arvore(Arv_AVL *raiz);

#endif 