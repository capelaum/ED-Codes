#include <stdlib.h>
#include "lista11.h"

//----------ALOCAÇÃO----------------
t_no* aloca_no (int dado){
	t_no* novo = (t_no*) malloc(sizeof(t_no));
	
	if(!novo){
		return FALSE;
	}
	
	novo->dado = dado;
	novo->proximo = NULL;
	
	return novo;
}
t_lista* aloca_lista (){                                                                             
	t_lista* ptr = (t_lista*) malloc(sizeof(t_lista));
	
	if(!ptr){
		return FALSE;
	}
	
	ptr->primeiro = NULL;
	ptr->ultimo = NULL;
	ptr->qtd = 0;
	
	return ptr;
}
//-----------INSERIR----------------
int inserir_final (int dado, t_lista* lista){
	
	if(!lista){
		printf("lista nao alocada!\n");
		return FALSE;
	}
	
	t_no* ptr = aloca_no(dado);
	
	if(!ptr)
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

//=========================LISTA==================================
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
//=============================================================
int troca_no(int pos1,int pos2,t_lista* lista){
	
	return TRUE;
}
//=============================================================
int procura_valor(int dado, t_lista* lista){
	
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
	}else{
		printf("Valor nao encontrado!\n");
	}
	return;
}
