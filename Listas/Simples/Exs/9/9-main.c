#include <stdio.h>
#include <stdlib.h>

#include "lista9.h"

int main() {
	int N,valor,i,pos;
	
	t_lista* lista = aloca_lista();
	
	printf("---------LISTA SIMPLES----------\n");
	printf("Insira o numero de nos: ");
	scanf("%d", &N);
	
	for(i=1;i<=N;i++){
		printf("Insira o valor para o no %d: ", i);
		scanf("%d", &valor);
		inserir_ordenado(valor, lista);
	}
	imprime_lista(lista);
	
	printf("=================================\n");
	printf("Informe o valor ord# que deseja inserir: ");
	scanf("%d", &valor);
	
	inserir_ordenado (valor,lista);
	imprime_lista(lista);
	
	printf("=================================\n");
	
	apaga_lista(lista);
	
	return 0;
}
