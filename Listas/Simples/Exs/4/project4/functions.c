#include <stdio.h>
#include <stdlib.h>

#include "head.h"

//ALOCA��O
//===============================================================
t_lista* aloca_lista (){                                                                             
	t_lista* ptr = (t_lista*) malloc(sizeof(t_lista));
	
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
	int inserir_pos (int pos, int dado, t_lista* lista){
	
	if(!lista){
		printf("lista nao alocada!\n");
		return FALSE;
	}
	
	t_no* no  = aloca_no(dado);
	
	if(!no)
		return FALSE;
	
	t_no* ptr = lista->primeiro;
	
	int cont=1;
	while( (ptr != NULL) && (cont < pos-1)){
		ptr = ptr->proximo;
		cont++;	
	}
	
	if(esta_vazia(lista)){
		lista->primeiro = no;
		lista->ultimo   = no;
	}else{
		if(pos == 1){
			no->proximo     = lista->primeiro;
			lista->primeiro = no;
		}else if( pos>1 && pos < lista->qtd ){
			no->proximo  = ptr->proximo;
			ptr->proximo = no;
		}else if(pos == lista->qtd){
			lista->ultimo->proximo = no;
			lista->ultimo          = no;
		}else{
			printf("Posicao n existe carai\n");
			return FALSE;
		}
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
		lista->primeiro = ptr;
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
//===============================================================
int remove_dado(int dado, t_lista* lista){
	if(!lista){
		printf("lista nao alocada!\n");
		return FALSE;
	}
	
	t_no* ptr = lista->primeiro;
	
	int cont=1;
	while( (ptr != NULL) && ptr->dado != dado){
		ptr = ptr->proximo;
		cont++;
	}
	
	if(ptr){
		printf("Valor %d foi encontrado no no %d\n",ptr->dado, cont);
		
		
		if(lista->primeiro == lista->ultimo){
			lista->primeiro = NULL;
			lista->ultimo   = NULL;
		
		}else if(ptr == lista->primeiro){
			lista->primeiro = ptr->proximo;
		
		}else {
		
		t_no* aux = lista->primeiro;
		if(!aux) return FALSE;
		
		while( (aux != NULL) && aux->proximo != ptr)
			aux = aux->proximo;	
		
		
		aux->proximo = ptr->proximo;
		
		}
	}else{
		printf("Valor nao encontrado!\n");
		return TRUE;
	}
	free(ptr);
	
	lista->qtd--;
	return TRUE;
	
}
