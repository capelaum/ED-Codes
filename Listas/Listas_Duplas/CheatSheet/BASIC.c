
//===================================================================================================//BASIC
//==================================================================================================//ELEMENTO
t_elemento* aloca_elemento(int num){                 
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
//===================================================================================================//LISTA
t_lista* aloca_lista(){                                                                             
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
//===================================================================================================//VAZIA
int esta_vazia(t_lista* lista){
	return (lista->primeiro == NULL && lista->ultimo == NULL);
}
//===================================================================================================//IMPRIME
void imprime_lista(t_lista* lista){
	t_elemento* ptr = lista->primeiro;
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
//==============================================================================//Procura maior
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
