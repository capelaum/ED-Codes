#include <stdio.h>
#include <stdlib.h>

#include "lista_20.h"

int main() {
	
	int N,i,valor;
	
	t_lista* lista = aloca_lista();
	
	printf("Entre com o numero de nos: ");
	scanf("%d", &N);
	
	for(i=1;i<=N;i++){
		printf("Insira o valor para o no %d: ", i);
		scanf("%d", &valor);
		
		inserir_final(valor,lista);
	}
	
	imprime_lista(lista);
	
	procura_maior(lista);
	
	
	return 0;
}
