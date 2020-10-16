
#include "LD_Header.h"

// aloca elemento da lista duplamente encadeada
t_elemento* aloca_elemento (char* nome, int ataque, int defesa, int resistencia, int velocidade){                 
	
    t_elemento* ptr = (t_elemento*) malloc(sizeof(t_elemento));
	
	if(!ptr)  return false;
		
	ptr->team = (Team*) malloc(sizeof(Team)); // aloca ponteiro para struct Team
	
	if(!ptr->team){
		free(ptr);
		return false;
	}
	
    ptr->team->nome = (char*) malloc (sizeof(strlen(nome)+1)); // aloca espaço para a string nome recebida
    strcpy (ptr->team->nome, nome); // copia a string recebida para o espaço recem alocado

	ptr->team->ataque      = ataque;
	ptr->team->defesa      = defesa;
    ptr->team->resistencia = resistencia;
    ptr->team->velocidade  = velocidade;

	ptr->anterior = NULL;
	ptr->proximo = NULL;
	
	return ptr;
}
//===================================================================================================//LISTA
// aloca a estrutura da lista dupla
t_lista* aloca_lista(){                                                                             
	
	t_lista* ptr = (t_lista*) malloc(sizeof(t_lista));
	
	ptr->primeiro = NULL;
	ptr->ultimo = NULL;
	ptr->qtd = 0;
	
	return ptr;
}
//===================================================================================================//APAGA
// remove elemento por elemento e por fim a lista
void apaga_lista(t_lista* lista){
	
	t_elemento* ptr = lista->primeiro;
	
	if(!esta_vazia(lista)) {
		
		while(ptr){
			lista->primeiro = lista->primeiro->proximo;
			remove_elemento(ptr);
			ptr = lista->primeiro;
		}
	}
	
	free(lista);
}

// remove elemento de entrada
void remove_elemento (t_elemento* elemento){
	free(elemento->team->nome);
	free(elemento->team);
	free(elemento);
}
//===================================================================================================//VAZIA
int esta_vazia(t_lista* lista){
	return (lista->primeiro == NULL && lista->ultimo == NULL);
}
//===================================================================================================//IMPRIME
void imprime_lista(t_lista* lista){
	
	int i;
	t_elemento* ptr = lista->primeiro;
	
	if(esta_vazia(lista)){
		printf("LISTA VAZIA!\n");
		return ;
	}

	printf("-->Lista dupla:\n");
	
	for(i=0; i<lista->qtd; i++,ptr = ptr->proximo){
		
		printf("Time %d: %s -> ", i+1, ptr->team->nome);
		printf("ataque: %d, ", ptr->team->ataque);
		printf("defesa: %d, ", ptr->team->defesa);
		printf("resistencia: %d, ", ptr->team->resistencia);
		printf("velocidade: %d. \n", ptr->team->velocidade);
	}
	
	printf("\n>Numero de times: %d \n", lista->qtd);
}
//===================================================================================================
// FINAL
int inserir_final (char* nome, int ataque, int defesa, int resistencia, int velocidade, t_lista* lista){
	
	if(!lista)	return false;
	
	t_elemento* ptr = aloca_elemento(nome, ataque, defesa, resistencia, velocidade);
	
	if(!ptr)    return false;
	
	ptr->anterior = lista->ultimo;
	
	if(esta_vazia(lista)){
		lista->ultimo   = ptr;
		lista->primeiro = ptr;
	}else{
		lista->ultimo->proximo = ptr;
		lista->ultimo          = ptr;
	}
	
	lista->qtd++;
    return true;
}
//===================================================================================================