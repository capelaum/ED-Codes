//Functions
#include "lista20.h"

#include <stdlib.h>
#include <stdio.h>

t_lista* aloca_lista(){
	t_lista* lista = (t_lista*) malloc(sizeof(t_lista));
	
	if(!lista) return FALSE;
	
	lista->primeiro = NULL;
	lista->ultimo   = NULL;
	lista->qtd      = 0;
}

t_elemento* aloca_elemento(int num){
	 
	t_elemento* elemento = (t_elemento*) malloc(sizeof(t_elemento));
	
	if(!elemento) return FALSE;
	
	elemento->dado = (t_dado*) malloc(sizeof(t_dado));
	
	if(elemento->dado == NULL){
		free(elemento);
		return FALSE;
	}
	
	elemento->dado->num = num;
	
	elemento->prox = NULL;
	elemento->ant  = NULL;
	
	return elemento;
}

int esta_vazia(t_lista* lista){
	return (lista->primeiro == NULL && lista->ultimo == NULL);
}

void imprime_lista(t_lista* lista){
	
	if (!esta_vazia(lista)){
		
		t_elemento* ptr = lista->primeiro;
		
		printf("->Lista: ");
		while( ptr!=NULL){
			printf(" %d", ptr->dado->num);
			ptr = ptr->prox;
		}
		printf(">qtd = %d", lista->qtd);
	
	}else{
		printf("Lista vazia!");
		return;
	}
	
}
//==============================================================================
int inserir_final (int num, t_lista* lista){
	
	if(!lista) return FALSE;
	
	t_elemento* ptr = aloca_elemento(num);
	
	if(!ptr) return FALSE;
	
	ptr->ant = lista->ultimo;
	
	if(!esta_vazia(lista)){
		lista->ultimo->prox = ptr;
		lista->ultimo       = ptr;
	}else{
		lista->primeiro = ptr;
		lista->ultimo   = ptr;
	}
	
	lista->qtd++;
	return TRUE;
}
