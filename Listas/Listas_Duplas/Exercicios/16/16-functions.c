#include "lista16.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//===================================================================================================//ELEMENTO
t_elemento* aloca_elemento(int num){                 //ALOCA
	t_elemento* ptr = (t_elemento*) malloc(sizeof(t_elemento));
	
	if(ptr == NULL)
		return NULL;
		
	ptr->dado = (t_dado*) malloc(sizeof(t_dado));
	
	if(ptr->dado == NULL){
		free(ptr);
		return NULL;
	}
	
	ptr->dado->num = num;
	
	ptr->anterior = NULL;
	ptr->proximo = NULL;
	
	return ptr;
}
//===================================================================================================//REMOVE
void remove_elemento (t_elemento* elemento){
	free(elemento->dado);
	free(elemento);
}
//===================================================================================================//ALUNO
int remove_dado (int num, t_lista* lista){
	if(lista==NULL)
		return FALSE;
		
	if(esta_vazia(lista))
		return FALSE;
		
	t_elemento* ptr = lista->primeiro;
	
	while( (ptr!=NULL) && (ptr->dado->num != num))
		ptr = ptr->proximo;
		
	if(ptr==NULL){
		printf ("elemento nao encontrado!\n");
		return FALSE;
	}
	
	if(ptr->anterior == NULL){         // primeiro elemento
		lista->primeiro = ptr->proximo;	
	}else{
		ptr->anterior->proximo = ptr->proximo;
	}
		
	if(ptr->proximo != NULL){          //nao é o ultimo
		ptr->proximo->anterior = ptr->anterior;
	}else{
		lista->ultimo = ptr->anterior;	
	}
	
	remove_elemento(ptr);
	
	lista->qtd--;
	
	return TRUE;
	
}
//===================================================================================================//LISTA
t_lista* aloca_lista(){                                                                             //ALOCA
	t_lista* ptr = (t_lista*) malloc(sizeof(t_lista));
	ptr->primeiro = NULL;
	ptr->ultimo = NULL;
	ptr->qtd = 0;
	
	return ptr;
}
//===================================================================================================//APAGA
void apaga_lista(t_lista* lista){
	t_elemento* ptr = lista->primeiro;
	
	if(!esta_vazia(lista)) {
		
		while(ptr!=NULL){
			lista->primeiro = lista->primeiro->proximo;
			remove_elemento(ptr);
			ptr = lista->primeiro;
		}
	}
	
	free(lista);
}
//===================================================================================================//VAZIA?
int esta_vazia(t_lista* lista){
	return (lista->primeiro == NULL && lista->ultimo == NULL);
}
//===================================================================================================//IMPRIME
void imprime_lista(t_lista* lista){
	t_elemento* ptr = lista->primeiro;
	double media;
	int i;
	
	if(esta_vazia(lista)){
		printf("LISTA VAZIA!\n");
		return;
	}

	printf("-->Lista dupla:");
	
	for(i=0; i<lista->qtd; i++,ptr = ptr->proximo){
		printf(" %d", ptr->dado->num);
	}
	
	printf("\nqtd: %d\n", lista->qtd);
}
//===================================================================================================
//===================================================================================================//Inserir
int inserir_inicio (int num, t_lista* lista){        //INICIO
	
	if(lista==NULL)
		return FALSE;
	
	t_elemento* ptr = aloca_elemento(num);
	
	if(ptr==NULL)
		return FALSE;
	
	ptr->proximo = lista->primeiro;

	if(lista->primeiro == NULL){
		lista->primeiro = ptr;
		lista->ultimo   = ptr;
	}else{
		lista->primeiro->anterior = ptr;
		lista->primeiro           = ptr;
	}
	
	lista->qtd++;
	
	return TRUE;
}
//===================================================================================================//FINAL
int inserir_final (int num, t_lista* lista){
	if(lista==NULL)
		return FALSE;
	
	t_elemento* ptr = aloca_elemento(num);
	
	if(ptr == NULL)
		return FALSE;
	
	ptr->anterior = lista->ultimo;
	
	if(esta_vazia(lista)){
		lista->ultimo   = ptr;
		lista->primeiro = ptr;
	}else{
		lista->ultimo->proximo = ptr;
		lista->ultimo        = ptr;
	}
	
	lista->qtd++;
	return TRUE;
}
//===================================================================================================//ORDENADO
int inserir_ordenado (int num, t_lista* lista){
	if(lista==NULL)
		return FALSE;
	
	t_elemento* no = aloca_elemento(num);
	
	if(no == NULL)
		return FALSE;
		
	t_elemento* ptr = lista->primeiro;
	
	while( (ptr != NULL) && (ptr->dado->num < num))
		ptr = ptr->proximo;
		
	if(esta_vazia(lista)){  // lista vazia
		lista->primeiro = no;
		lista->ultimo   = no;
	}else if(ptr == lista->primeiro){ // inserir primeiro
		no->proximo               = lista->primeiro;
		lista->primeiro->anterior = no;
		lista->primeiro           = no;
	}else if(ptr == NULL){  // inserir ultimo
		lista->ultimo->proximo = no;
		no->anterior           = lista->ultimo;
		lista->ultimo          = no;
	}else{
		no->anterior = ptr->anterior;
		ptr->anterior->proximo = no;
		ptr->anterior          = no;
		no->proximo            = ptr;
	}
	
	lista->qtd++;
	
	return TRUE;
}	
//===================================================================================================
int inserir_pos (int pos, int num, t_lista* lista){
	
	if(lista==NULL)
		return FALSE;
	
	t_elemento* no = aloca_elemento(num);
	
	if(no == NULL)
		return FALSE;
		
	t_elemento* ptr = lista->primeiro;
	
	int cont=1;
	while( (ptr != NULL) && (cont < pos)){

		ptr = ptr->proximo;
		cont++;
	}
	
	if(esta_vazia(lista)){  // lista vazia
		lista->primeiro = no;
		lista->ultimo   = no;
	}else if(ptr == lista->primeiro){ // inserir primeiro
		no->proximo               = lista->primeiro;
		lista->primeiro->anterior = no;
		lista->primeiro           = no;
	}else if(ptr == NULL){  // inserir ultimo
		lista->ultimo->proximo = no;
		no->anterior           = lista->ultimo;
		lista->ultimo          = no;
	}else{
		no->anterior = ptr->anterior;
		ptr->anterior->proximo = no;
		ptr->anterior          = no;
		no->proximo            = ptr;
	}
	
	lista->qtd++;
	return TRUE;
}
