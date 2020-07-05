//===================================================================================================//REMOVE 
void remove_elemento (t_elemento* elemento){
	free(elemento->dado);
	free(elemento);
}
//===================================================================================================//INICIO
int remove_inicio (t_lista* lista){
	
	if (!lista) return FALSE;
	
	if(esta_vazia(lista)) return FALSE;
	
	t_elemento* ptr = lista->primeiro;
	
	if(!ptr) return FALSE;
	
	if(lista->primeiro != lista->ultimo){
	  	lista->primeiro = ptr->proximo;
		ptr->proximo->anterior = ptr->anterior;
	}else{
		lista->primeiro = NULL;
		lista->ultimo   = NULL;
	}
	remove_elemento(ptr);
	
	lista->qtd--;
	return TRUE;
}
//===================================================================================================//FINAl
int remove_final (t_lista* lista){
	
	if (!lista) return FALSE;
	
	if(esta_vazia(lista)) return FALSE;
	
	t_elemento* ptr = lista->ultimo;
	
	if(!ptr) return FALSE;
	
	if(lista->primeiro != lista->ultimo){
	  	lista->ultimo = ptr->anterior;
		ptr->anterior->proximo = ptr->proximo;
	}else{
		lista->primeiro = NULL;
		lista->ultimo   = NULL;
	}
	remove_elemento(ptr);
	
	lista->qtd--;
	return TRUE;
}
//===================================================================================================//DADO
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
//===================================================================================================//POSIÇÃO
int remove_pos (int pos, t_lista* lista){
	
	if (!lista) return FALSE;
	
	if(esta_vazia(lista)) return FALSE;
	
	t_elemento* ptr = lista->primeiro;
	
	if(!ptr) return FALSE;
	
	int cont=1;
	while( (ptr!= NULL) && cont<pos){
		ptr = ptr->proximo;
		cont++;
	}
	if(lista->primeiro != lista->ultimo){
		if(pos<=1){
			remove_inicio(lista);
		}else if (pos >= lista->qtd){
			remove_final(lista);
		}else{
			ptr->anterior->proximo = ptr->proximo;
			ptr->proximo->anterior = ptr->anterior;
			remove_elemento(ptr);
			lista->qtd--;
		}
	}else{
		lista->primeiro = NULL;
		lista->ultimo   = NULL;
	}
	return TRUE;
}
//===================================================================================================
