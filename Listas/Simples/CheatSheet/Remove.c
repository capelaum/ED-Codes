//REMOVER()9
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
//===============================================================
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
		
	if (lista->primeiro == lista->ultimo){ //unico elemento
		lista->primeiro = NULL;
		lista->ultimo   = NULL;
		free(ptr);
	}else{
		while( ptr->proximo != lista->ultimo)
			ptr = ptr->proximo;
		
		ptr->proximo  = lista->ultimo->proximo;
		lista->ultimo = ptr;
		
	}
	
	lista->qtd--;
	return TRUE;
	
}
//===============================================================
int remove_pos (int pos, t_lista* lista){
	
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
				atual    = atual->proximo;	
			}
			
			anterior->proximo = atual->proximo;
			free(atual);
			lista->qtd--;
		}

	return TRUE;
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
