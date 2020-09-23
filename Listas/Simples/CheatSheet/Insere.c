
//INSERIR()
//===========================================================================
int inserir_ordenado (int dado, t_lista* lista){
    if(!lista) return FALSE;
    
    t_no* no = aloca_no(dado);
    
    if(!no) return FALSE;
    
    t_no* ptr = lista->primeiro;
    
    while( ptr!=NULL && ptr->dado < dado)
        ptr = ptr->proximo;
        
        if(esta_vazia(lista)){
            lista->primeiro = no;
            lista->ultimo   = no;
        }else if(ptr == lista->primeiro){
            no->proximo     = lista->primeiro;
            lista->primeiro = no;
        }else if(!ptr){
            lista->ultimo->proximo = no;
            lista->ultimo          = no;
        }else{
        		t_no* aux = lista->primeiro;
    			if(!aux) return FALSE;
    			
				while( aux!=NULL && aux->proximo!=ptr)
        			aux = aux->proximo;
        			
            no->proximo  = aux->proximo;
            aux->proximo = no;
        }
        
        lista->qtd++;
        return TRUE;
}
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
		if(pos <= 1){
			no->proximo     = lista->primeiro;
			lista->primeiro = no;
		}else if( pos>1 && pos <= lista->qtd ){
			no->proximo  = ptr->proximo;
			ptr->proximo = no;
		}else{
			lista->ultimo->proximo = no;
			lista->ultimo          = no;
		}
	}

	lista->qtd++;
	return TRUE;
}
//===============================================================
int inserir_inicio (int dado, t_lista* lista){

	if(!lista){
		printf("lista nao alocada!\n");
		return FALSE;
	}
		
	t_no* ptr = aloca_no(dado);
		
	if(!ptr)
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
//===============================================================
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
//===============================================================//Versao2
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
			return;
		}
	}

	lista->qtd++;
	return TRUE;
}
//===============================================================
