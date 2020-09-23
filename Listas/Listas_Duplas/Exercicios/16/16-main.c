#include <stdio.h>
#include <stdlib.h>

#include "lista16.h"


int main() {
	int i, N, valor,pos;
	
	t_lista* lista = aloca_lista();
	
	printf("Insira o numero de nos: ");
	scanf("%d", &N);
	
	for(i=1;i<=N;i++){
		printf("Insira o valor para o no %d: ", i);
		scanf("%d", &valor);
		
		inserir_ordenado (valor, lista);
	}
	
	imprime_lista(lista);
	
	printf("=======================================\n");
	printf("Insira posicao do novo no: ");
	scanf("%d",&pos);
	
	printf("Insira novo numero: ");
	scanf("%d", &valor);
	
	inserir_pos (pos, valor, lista);
	
	imprime_lista(lista);
	
	apaga_lista(lista);
	
	return 0;

}
