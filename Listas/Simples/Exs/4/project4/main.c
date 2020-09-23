#include <stdio.h>
#include <stdlib.h>

#include "head.h"

int main() {
	int N=3,valor=5,i,pos;
	
	t_lista* lista = aloca_lista();
	printf("---------LISTA SIMPLES----------\n");
	printf("Insira o numero de nos: ");
	scanf("%d", &N);
	
	for(i=1;i<=N;i++){
		printf("Insira o valor para o no %d: ", i);
		scanf("%d", &valor);
		inserir_final(valor, lista);
	}
	printf("=================================\n");
	printf("Insira o valor para ser inserido no final da lista: " );
	scanf("%d",&valor);
	inserir_final(valor, lista);
	
	imprime_lista(lista);
	printf("=================================\n");
	printf("Insira o valor para ser inserido no inicio da lista: " );
	scanf("%d",&valor);
	
	inserir_inicio(valor, lista);
	
	imprime_lista(lista);
	printf("=================================\n");
	printf("Insira a posi%cao para o novo no: ",135 );
		scanf("%d",&pos);
	
	printf("Insira o valor para o novo no: ");
		scanf("%d", &valor);
	
	inserir_pos (pos, valor, lista);
	imprime_lista(lista);
	
	printf("Insira o valor a ser removido: ");
		scanf("%d", &valor);
	remove_dado(valor, lista);
	
	imprime_lista(lista);
	
	apaga_lista(lista);
	return 0;
}
