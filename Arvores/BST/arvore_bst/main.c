

#include "arvore.h"

int main (){ 
    
	t_no* raiz  = NULL;

	t_no* no    = NULL;
	t_no* nopai = NULL;

	raiz = inserir  (raiz, 8);
    raiz = inserir  (raiz, 10);
	raiz = inserir  (raiz, 3);
	raiz = inserir  (raiz, 1);
	raiz = inserir  (raiz, 6);
	raiz = inserir  (raiz, 14);
	raiz = inserir  (raiz, 4);
	raiz = inserir  (raiz, 7);
	raiz = inserir  (raiz, 13);

	int noid = 10;
	
	no = busca (raiz, noid);
	
	if(no) {
		
		printf("no encontrado: %d\n", no->dado);

		nopai = busca_pai (raiz, noid);

		if(nopai)  printf("Pai de %d eh: %d\n", no->dado, nopai->dado);
		if(!nopai) printf("O no %d nao tem pai\n",no->dado);
	
	}else {
		printf("no nao encontrado!\n");
	}
	
	printf("---------------------\n");
	printf("Arvore em pre ordem: \n");
	pre_ordem (raiz);
	printf("---------------------\n");

//============================================

	printf("(a) Menor valor = %d\n", Menor_Valor (raiz));
	
	printf("(b) Maior valor = %d\n", Maior_Valor (raiz));

	printf("(d) Numero de nos = %d\n", qtd (raiz));
	
	printf("(f) Maxima Profundidade = %d\n", Max_Profundidade (raiz));

	printf("------------------------\n");
	printPaths (raiz);
	
	int soma = 21;
	
	if (Soma_caminho  (raiz, soma))  printf("Soma encontrada = %d\n", soma);
	if (!Soma_caminho (raiz, soma))  printf("Soma nao encontrada!\n");

	printf("------------------------\n");
	soma = soma_nos (raiz);
	printf("Soma de todos nos: %d \n",soma);

	printf("------------------------\n");

	int numKeys = 3;

	soma = countTrees (numKeys);
	printf("Numero de arvores possiveis com %d numeros é igual a: %d\n", numKeys, soma);
	printf("------------------------\n");

	if(isBST(raiz) == false) printf("Nao é BST!\n");
	if(isBST(raiz) == true)  printf("É BST!\n");


	libera_arvore (raiz);
	return 0;
}
//============================================	
// Exs Arvore_ED_2018

/* (1)
	t_no* criaRaiz (int dado);
	t_no* inserirNo (t_no* raiz, int dado);
	t_no* buscaNo (int dado);
	void liberaNo (t_no* no);
*/
//============================================
/* (2)
	(a) Saida: no mais a esquerda: 1
	(b) Saida: no mais a direita: 14
	(c) Saida: no de maior profund: 13
	(d) Saida: numero de nos: 9
	(e) Saida: soma do conteudo dos nos: 66
	(f) Saida: profundidade da bst: 4

	Arvore:

		  8
		/   \
       3    10
 	  / \     \
	 1   6    14
	    / \   /
	   4   7 13

*/
//============================================

/*
	(3) Percursos
	(4) Menor valor
	(5) Busca_pai
	(6) Verifica se 2 arvores sao iguais
	(7) Função espelho
	(8) Duplica uma arvore
	(9) Verifica se arvore esta completa
   (10) Verifica se todos nos a esquerda sao menores e a direita maiores
   (11) Transforma arvore em lista duplamente encadeada
	
	Deafio: quantas arvore podem ser feitas com valores de 1..N 
*/