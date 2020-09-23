//===================================================================================================//INSERIR
//===================================================================================================//INICIO
int inserir_inicio (int num, t_lista* lista){        
	
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
//===================================================================================================//POSIÇÃO
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
