#include <stdio.h>
#include <stdlib.h>

#include "lista7.h"

//ALOCAÇÃO
//===============================================================
t_lista* aloca_lista (){                                                                             
	t_lista* ptr = (t_lista*) malloc(sizeof(t_lista));
	
	if(!ptr){
		printf("elemento nao alocado!\n");
		return FALSE;
	}
	
	ptr->primeiro = NULL;
	ptr->ultimo = NULL;
	ptr->qtd = 0;
	
	return ptr;
}

t_no* aloca_no (int dado){
	t_no* novo = (t_no*) malloc(sizeof(t_no));
	
	if(!novo){
		printf("elemento nao alocado!\n");
		return FALSE;
	}
	
	novo->dado = dado;
	novo->proximo = NULL;
	
	return novo;
}

//INSERIR()
//===============================================================
int inserir_lugar (int pos, int dado, t_lista* lista){
	
	if(!lista){
		printf("lista nao alocada!\n");
		return FALSE;
	}
	
	t_no* no  = aloca_no(dado);
	
	if(no == NULL)
		return FALSE;
	
	t_no* ptr = lista->primeiro;
	
	int cont=1;
	
	while( (ptr != NULL) && (cont < pos-1)){
		ptr = ptr->proximo;
		cont++;	
	}
	
	if(!esta_vazia(lista)){
		if(pos<=1){
			no->proximo     = lista->primeiro;
			lista->primeiro = no;
		}else if( pos>1 && pos < lista->qtd ){
			no->proximo  = ptr->proximo;
			ptr->proximo = no;
		}else{
			lista->ultimo->proximo = no;
			lista->ultimo          = no;
		}
	}else{
		lista->primeiro = no;
		lista->ultimo   = no;
	}

	lista->qtd++;
	return TRUE;
}

int inserir_inicio (int dado, t_lista* lista){

if(!lista){
	printf("lista nao alocada!\n");
	return FALSE;
}
	
t_no* ptr = aloca_no(dado);
	
if(ptr == NULL)
		return FALSE;
	
if(esta_vazia(lista)){
		lista->ultimo   = ptr;
}else{
	ptr->proximo = lista->primeiro;	
}
	
lista->primeiro = ptr;
lista->qtd++;

return TRUE;
	
}

int inserir_final (int dado, t_lista* lista){
	
	if(!lista){
		printf("lista nao alocada!\n");
		return FALSE;
	}
	
	t_no* ptr = aloca_no(dado);
	
	if(ptr == NULL)
		return FALSE;
		
	
	if(esta_vazia(lista)){
		lista->primeiro = ptr;
	}else{
		lista->ultimo->proximo = ptr;	
	}
	
	lista->ultimo = ptr;
	lista->qtd++;
	return TRUE;
}

//LISTA
//===============================================================
void imprime_lista (t_lista* lista){
	t_no* ptr = lista->primeiro;
	
	if(esta_vazia(lista)){
		printf("LISTA VAZIA!\n");
		return;
	}
	
	while(ptr!=NULL){
		printf("%d ",ptr->dado);
		ptr = ptr->proximo;
	}
	
	printf("\n>Lista - qtd: %d\n", lista->qtd);
}

int esta_vazia (t_lista* lista){
	return (lista->primeiro == NULL && lista->ultimo == NULL);
}

void apaga_lista (t_lista* lista){
	t_no* ptr = lista->primeiro;
	
	if(esta_vazia(lista)){
		printf("LISTA VAZIA!\n");
		return;
	}
	
	while(ptr!=NULL){
		lista->primeiro = lista->primeiro->proximo;
		free(ptr);
		ptr = lista->primeiro;
	}
	free(lista);
}

//REMOVER()
//===============================================================
int remove_primeiro(t_lista* lista){
	
	if(!lista){
		printf("lista nao alocada!\n");
		return FALSE;
	}
	
	if(esta_vazia(lista)){
		printf("LISTA VAZIA!\n");
		return FALSE;
	}
	
	t_no* ptr = lista->primeiro;
	
	lista->primeiro = ptr->proximo;
	
	free(ptr);
	
	lista->qtd--;
	return TRUE;
}

int remove_ultimo(t_lista* lista){
	
	if(!lista){
		printf("lista nao alocada!\n");
		return FALSE;
	}
	
	if(esta_vazia(lista)){
		printf("LISTA VAZIA!\n");
		return;
	}
	
	t_no* ptr = lista->primeiro;
	
	if(!ptr)
		return FALSE;
		
	if (lista->primeiro == lista->ultimo){
		lista->primeiro = NULL;
		lista->ultimo   = NULL;
		free(ptr);
	}else{
		while( ptr->proximo != lista->ultimo)
			ptr = ptr->proximo;
	
		lista->ultimo = ptr;
		ptr->proximo = NULL;
	}
	
	lista->qtd--;
	return TRUE;
	
}

int remove_lugar (int pos, t_lista* lista){
	
	if(!lista){
		printf("lista nao alocada!\n");
		return FALSE;
	}
	
	if(esta_vazia(lista)){
		printf("LISTA VAZIA!\n");
		return;
	}
	
	int i;
	
		if(pos<=1){
			remove_primeiro(lista);
		}else if(pos >= lista->qtd ){
			remove_ultimo(lista);
		}else{
			
			t_no* anterior = lista->primeiro;
			t_no* atual    = lista->primeiro->proximo;
			
			if(atual == NULL || anterior == NULL) return FALSE;
			
			for(i=2;i<pos;i++){
				anterior = atual;
				atual = atual->proximo;	
			}
			
			anterior->proximo =atual->proximo;
			free(atual);
			lista->qtd--;
		}

	return TRUE;
}
