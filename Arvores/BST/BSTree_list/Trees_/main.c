

#include "arvore_1.h"

int main (){ 
    
   t_no* raiz = NULL;
   
   raiz = inserir (raiz, 8);
	raiz = inserir (raiz, 3);
	raiz = inserir (raiz, 6);
	raiz = inserir (raiz, 4);
	raiz = inserir (raiz, 7);
	raiz = inserir (raiz, 1);
	raiz = inserir (raiz, 10);
	raiz = inserir (raiz, 14);
	raiz = inserir (raiz, 13);
	
	printf("Arvore em ordem: \n");
	em_ordem (raiz);
	printf("---------------------\n");
	
	printf("Menor valor = %d\n", Menor_Valor (raiz));
	
	printf("Maior valor = %d\n", Maior_Valor (raiz));
	
	printf("Maxima Profundidade = %d\n", Max_Profundidade (raiz));
	
	printf("Numero de nos = %d\n", qtd (raiz));
	
	int noid = 13;
	t_no* no = NULL;
	t_no* nopai = NULL;
	
	no    = busca     (raiz, noid);
	nopai = busca_pai (raiz, noid);
	
	if(no)  printf("no encontrado: %d\n", no->dado);
	if(!no) printf("no nao encontrado!\n");
	
   if(nopai)  printf("Pai de %d eh: %d\n", no->dado, nopai->dado);
	if(!nopai) printf("O no %d nao tem pai\n",no->dado);
	
	int soma = 12;
	
	if (hasPathSum ( raiz, soma))  printf("Soma encontrada = %d\n", soma);
	if (!hasPathSum( raiz, soma))  printf("Soma nao encontrada!\n");
	
	
	printf("------------------------\n");
	printPaths (raiz);
	
	
	return 0;
}
