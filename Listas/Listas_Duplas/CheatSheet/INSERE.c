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
/*
* Função: inserir char ordenadamente numa lista duplamente encadeada
*  Descrição:
*		Insere caractere em uma lista duplamente encadeada de forma que o elemento seguinte da lista
*		tenha um valor maior do que o foi inserido, enquanto que todos elementos anteriores são menores
*
*  Parametros:
*		num: valor a ser inserido na lista
*		lista: ponteiro para o primeiro item de uma lista duplamente encadeada
*
*  Valor retornado:
*  		Retorna true se inserção foi sucedida e false caso a lista não exista (NULL) ou não foi possível alocar espaço para o novo elemento
*  
* Assertiva de entrada:
* 		lista != NULL
* 
* Assertiva de saída:
* 		Se retornar True entao:
*		a lista conterá 1 ou mais caracteres
*		
* 		Se valor já estiver presente na lista:
*			 o valor que foi inserido estará na posição posterior ao que já estava presente na lista
*		
*		Se retornar FALSE:
*			Lista dupla não será alterada
*
* 
*/
int inserir_ordenado (int num, t_lista* lista){
	if(lista==NULL)
		return FALSE;				// verifica se lista existe 
	
	t_elemento* no = aloca_elemento(num);
	
	if(no == NULL)					// verfica se espaço fo alocado corretamente para o novo elemento
		return FALSE;
		
	t_elemento* ptr = lista->primeiro;
	
	while( (ptr != NULL) && (ptr->dado->num < num))
		ptr = ptr->proximo;
		
	if(esta_vazia(lista)){  			// lista vazia
		lista->primeiro = no;
		lista->ultimo   = no;
	}else if(ptr == lista->primeiro){ 	// inserir primeiro
		no->proximo               = lista->primeiro;
		lista->primeiro->anterior = no;
		lista->primeiro           = no;
	}else if(ptr == NULL){  			// inserir ultimo
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
//===================================================================================================//POSI��O
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
