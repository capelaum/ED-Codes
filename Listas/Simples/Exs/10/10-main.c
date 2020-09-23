// PROCURA ELEMENTO EXISTENTE NA LISTA
#include <stdio.h>
#include <stdlib.h>

#include "lista10.h"

int main() {
	int i,N,valor,pos;
	
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
	
	procura_valor(valor, lista);
	
	printf("Insira o valor a ser inserido: ");
	scanf("%d", &valor);
	
	printf("Insira a posicao: ");
	scanf("%d", &pos);
	
	inserir_pos(pos,valor,lista);
	imprime_lista(lista);
	
	apaga_lista(lista);
	
	return 0;
}
