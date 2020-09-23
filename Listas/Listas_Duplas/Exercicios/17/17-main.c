#include <stdio.h>
#include <stdlib.h>

#include "lista17.h"


int main() {
	int i, N, valor,pos;
	
	t_lista* lista = aloca_lista();
	
	printf("Insira o numero de nos: ");
	scanf("%d", &N);
	
	for(i=1;i<=N;i++){
		printf("Insira o valor para o no %d: ", i);
		scanf("%d", &valor);
		
		inserir_final (valor, lista);
	}
	
	imprime_lista(lista);
	
	printf("=======================================\n");
	printf("Removendo primeiro e ultimo no respectivamente: \n");
	
	remove_inicio(lista);
	imprime_lista(lista);

	remove_final(lista);
	imprime_lista(lista);
	
	printf("=======================================\n");
	printf("Informe a posicao do no a ser removido: ");
	scanf("%d",&pos);
	
	remove_pos   (pos,lista);
	imprime_lista(lista);
	
	printf("=======================================\n");
	printf("Informe o valor do no a ser removido: ");
	scanf("%d",&valor);
	
	remove_dado(valor,lista);
	imprime_lista(lista);
	
	
	apaga_lista(lista);
	return 0;

}
