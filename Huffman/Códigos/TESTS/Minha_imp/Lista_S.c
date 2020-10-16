


#include "Lista_S.h"


//ALOCAÇÃO
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

t_no* aloca_no (int freq, char simbolo){
	t_no* novo = (t_no*) malloc(sizeof(t_no));
	
	if(!novo){
		printf("elemento nao alocado!\n");
		return FALSE;
	}
	
    novo->simbolo = simbolo;
	novo->freq    = freq;
	novo->prox = NULL;
	novo->raiz = NULL;

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
	
	int cont = 1;

	while(ptr){
		printf("%d. %c - freq: %d \n",cont++, ptr->simbolo, ptr->freq);
		ptr = ptr->prox;
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
		lista->primeiro = lista->primeiro->prox;
		if(!lista->primeiro) lista->ultimo = NULL;
		free(ptr);
		ptr = lista->primeiro;
	}
	
    lista->ultimo = NULL;
	free(lista);
}

//===================================================================
int inserir_ordenado (t_no_h* raiz, int freq, char simbolo, t_lista* lista){
    
	if(!lista) return FALSE;
    

	t_no* no = aloca_no(freq,simbolo);
		
	if(!no) return FALSE;
		
	t_no* ptr = lista->primeiro;
		
	while( ptr!=NULL && ptr->freq < freq){
		ptr = ptr->prox;
	}   

	if(esta_vazia(lista)){
		lista->primeiro = no;
		lista->ultimo   = no;
	}else if(ptr == lista->primeiro){
		no->prox     = lista->primeiro;
		lista->primeiro = no;
	}else if(!ptr){
		lista->ultimo->prox = no;
		lista->ultimo          = no;
	}else{
		t_no* aux = lista->primeiro;
				
		if(!aux) return FALSE;
					
		while( (aux != NULL) && (aux->prox!=ptr) ){
			aux = aux->prox;
		}		

			no->prox  = aux->prox;
			aux->prox = no;
	}   
		

    lista->qtd++;

    return TRUE;
}

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
	
	lista->primeiro = ptr->prox;
	
	free(ptr);
	
	lista->qtd--;
	return TRUE;
}
//===============================================================