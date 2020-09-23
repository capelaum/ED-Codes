#include <stdio.h>
#include <stdlib.h>

#include "lista11.h"

int main() {
	int i,N,valor;
	
	t_lista* lista = aloca_lista();
	
	printf("Insira o numero de nos: ");
	scanf("%d", &N);
	
	for(i=1;i<=N;i++){
		printf("Insira o valor para o no %d: ", i);
		scanf("%d", &valor);
		
		inserir_final(valor, lista);
	}
	
	imprime_lista(lista);
	printf("Insira o valor a ser procurado: ");
	scanf("%d", &valor);
	
	procura_valor(valor,lista);
	imprime_lista(lista);
	
	/*
	int pos1,pos2;
	
	printf("Insira a posicao do primeiro no a ser trocado: ");
	scanf("%d", &pos1);
	
	printf("Insira a posicao do segundo no a ser trocado: ");
	scanf("%d", &pos2);
	
	troca_no(pos1,pos2,lista);
	*/
	
	
	
	
	apaga_lista(lista);
	
	
	return 0;
}
