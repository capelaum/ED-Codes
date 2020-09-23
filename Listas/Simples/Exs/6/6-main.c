#include <stdio.h>
#include <stdlib.h>

#include "lista6.h"

int main() {
	int N=3,valor=5,i,pos;
	
	t_lista* lista = aloca_lista();
	
	printf("---------LISTA SIMPLES----------\n");
	printf("Insira o numero de nos: ");
	scanf("%d", &N);
	
	for(i=1;i<=N;i++){
		printf("Insira o valor para o no %d: ", i);
		scanf("%d", &valor);
		inserir_inicio(valor, lista);
	}
	
	imprime_lista(lista);
	
	printf("=================================\n");
	
	printf("Insira a posi%cao para o novo no: ",135 );
		scanf("%d",&pos);
	
	printf("Insira o valor para o novo no: ");
		scanf("%d", &valor);
	
	inserir_lugar (pos, valor, lista);
	
	imprime_lista(lista);
	
	apaga_lista(lista);
	return 0;
}
