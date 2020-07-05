

#include "LD_Header.h"


//===================================================================================================//IMPRIME
void imprime_lista_times (t_lista* lista){
	
    int i;
    
    t_elemento* ptr = lista->primeiro;
	
	if(esta_vazia(lista)){
		printf("LISTA VAZIA!\n");
		return ;
	}

	printf("-->Lista dupla:\n");
	
	for(i=0; i < lista->qtd; i++,ptr = ptr->proximo){
		
        printf("Time %d: ", lista->qtd);
        printf("Ataque: %d, ", ptr->team->ataque);
        printf("Defesa: %d, ", ptr->team->defesa);
        printf("Resistencia: %d, ", ptr->team->resistencia);
        printf("Velocidade:  %d. \n", ptr->team->velocidade);
	}
	
	printf("\n>Numero de times: %d \n", lista->qtd);
}
//===================================================================================================
