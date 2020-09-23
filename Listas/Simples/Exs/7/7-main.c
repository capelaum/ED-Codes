#include <stdio.h>
#include <stdlib.h>

#include "lista7.h"

int main() {
	int N,valor,i,pos;
	
	t_lista* lista = aloca_lista();
	
	printf("---------LISTA SIMPLES----------\n");
	printf("Insira o numero de nos: ");
	scanf("%d", &N);
	
	for(i=1;i<=N;i++){
		printf("Insira o valor para o no %d: ", i);
		scanf("%d", &valor);
		inserir_final(valor, lista);
	}
	imprime_lista(lista);
	
	printf("=================================\n");
	printf("Informe a posicao do no que deseja remover: ");
	scanf("%d", &pos);
	
	remove_lugar(pos,lista);
	
	printf(">Lista apos remo%cao -> ", 135);
	imprime_lista(lista);
	

	apaga_lista(lista);
	return 0;
}
