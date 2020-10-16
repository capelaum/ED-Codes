#include "ListaH.h"

//ALOCA��O
//===============================================================
t_lista* aloca_lista (){                                                                             
	t_lista* ptr = (t_lista*) malloc(sizeof(t_lista));
	
	if(!ptr){
		printf("lista nao alocada!\n");
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
//===================================================================
//=========================LISTA=====================================
void imprime_lista (t_lista* lista){
	t_no* ptr = lista->primeiro;
	
	if(esta_vazia(lista)){
		printf("LISTA VAZIA!\n");
		return;
	}
	
	while(ptr){
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
	
	while(ptr){
		lista->primeiro = lista->primeiro->proximo;
		if(!lista->primeiro) lista->ultimo = NULL;
		free(ptr);
		ptr = lista->primeiro;
	}
	lista->ultimo = NULL;
	free(lista);
}
//===================================================================
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
	return TRUE;
}
//================================================================
int procura_maior(t_lista* lista){

	t_no* maior = lista->primeiro;
	if(!maior) return FALSE;
	
	t_no* ptr = lista->primeiro->proximo;
	
	if(!ptr){
		printf("\nMaior e unico elemento = %d\n", maior->dado);
	return FALSE;
	}
	
	while(ptr){
		if(maior->dado < ptr->dado){
			maior = ptr;
		}
		ptr = ptr->proximo;
	}
	printf("\nMaior valor encontrado na lista: %d\n", maior->dado);
	
	return TRUE;
}
