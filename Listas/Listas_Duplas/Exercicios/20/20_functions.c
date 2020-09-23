#include "lista_20.h"

#include <stdlib.h>
#include <stdio.h>
//==============================================================================
t_lista* aloca_lista(){
	t_lista* lista = (t_lista*) malloc(sizeof(t_lista));
	
	if(!lista) return FALSE;
	
	lista->primeiro = NULL;
	lista->ultimo   = NULL;
	lista->qtd      = 0;
	
	return lista;
}
//==============================================================================
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
//==============================================================================
int esta_vazia(t_lista* lista){
	return (lista->primeiro == NULL && lista->ultimo == NULL);
}
//==============================================================================
void imprime_lista(t_lista* lista){
	
	if (!esta_vazia(lista)){
		
		t_elemento* ptr = lista->primeiro;
		
		printf("->Lista: ");
		while( ptr!=NULL){
			printf(" %d", ptr->dado->num);
			ptr = ptr->prox;
		}
		printf("\n>qtd = %d", lista->qtd);
	
	}else{
		printf("Lista vazia!");
		return;
	}
	
}
void imprime (t_lista *lista) {
   t_elemento *p = lista->primeiro;
   for ( ; p != NULL; p = p->prox) 
      printf ("%d\n", p->dado->num);
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
//==============================================================================
int inserir_ordenado (int num, t_lista* lista){
	if(lista==NULL)
		return FALSE;
	
	t_elemento* no = aloca_elemento(num);
	
	if(no == NULL)
		return FALSE;
		
	t_elemento* ptr = lista->primeiro;
	
	while( (ptr != NULL) && (ptr->dado->num < num))
		ptr = ptr->prox;
		
	if(esta_vazia(lista)){  // lista vazia
		lista->primeiro = no;
		lista->ultimo   = no;
	}else if(ptr == lista->primeiro){ // inserir primeiro
		no->prox             = lista->primeiro;
		lista->primeiro->ant = no;
		lista->primeiro      = no;
	}else if(ptr == NULL){  // inserir ultimo
		lista->ultimo->prox = no;
		no->ant             = lista->ultimo;
		lista->ultimo       = no;
	}else{
		no->ant        = ptr->ant;
		ptr->ant->prox = no;
		ptr->ant       = no;
		no->prox       = ptr;
	}
	
	lista->qtd++;
	
	return TRUE;
}	
//==============================================================================
int procura_maior(t_lista* lista){

	t_elemento* maior = lista->primeiro;
	if(!maior) return FALSE;
	
	t_elemento* ptr = lista->primeiro->prox;
	
	if(!ptr){
		printf("\nMaior e unico elemento = %d\n", maior->dado->num);
	return FALSE;
	}
	
	while(ptr){
		if(maior->dado->num < ptr->dado->num){
			maior = ptr;
		}
		ptr = ptr->prox;
	}
	printf("\nMaior valor encontrado na lista: %d", maior->dado->num);
	
	return TRUE;
}
//================================================================================

