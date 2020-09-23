
// Funcionamento de uma arvore 

#include "arvore.h"
//=======================================================
// aloca o no
t_no* aloca_no (int dado){
    
   t_no* ptr = (t_no*) malloc (sizeof(t_no));

   ptr->dado = dado;
   ptr->dir = NULL;
   ptr->esq = NULL;

   return ptr;

}
//=======================================================
// Inserir -  recursivo 
t_no* inserir (t_no* raiz, int dado){

   if (raiz == NULL) {
        return aloca_no(dado);
    }else{
        if(raiz->dado > dado)                      // Se dado da raiz for maior que o dado a ser inserido
            raiz->esq = inserir (raiz->esq, dado); // inserir no ptr esquerdo da arvore
        else if (raiz->dado < dado)                //  Se o dado da raiz for menor que o dado a ser inserido
            raiz->dir = inserir (raiz->dir, dado); // inserir no ptr direito da arvore
    }
   return raiz;

}
//=======================================================
// Imprime em pre_ordem / ordem / pos_ordem
void pre_ordem (t_no* raiz) {

   if(raiz != NULL){

      printf ("%d\n", raiz->dado);

      pre_ordem (raiz->esq);
      pre_ordem (raiz->dir);
   }

}
//=======================================================
// Imprime em pre_ordem / ordem / pos_ordem
void em_ordem (t_no* raiz) {

   if(raiz != NULL){
      em_ordem (raiz->esq);
      printf ("%d\n", raiz->dado);
      em_ordem (raiz->dir);
   }

}
//=======================================================
// Imprime em pre_ordem / ordem / pos_ordem
void pos_ordem (t_no* raiz) {

   if(raiz != NULL){
      pos_ordem (raiz->esq);
      pos_ordem (raiz->dir);
      printf ("%d\n", raiz->dado);
   }

}
//=======================================================
// Busca - recursiva
t_no* busca ( t_no* raiz, int dado){

   if(raiz == NULL)
      return NULL;

   if(raiz->dado > dado) 
      return busca (raiz->esq, dado);

   if (raiz->dado < dado)
      return busca (raiz->dir, dado);
         
   return raiz;

}
//=======================================================
// Busca pai - recursiva
t_no* busca_pai (t_no* raiz, int dado){
	
	if(raiz == NULL || raiz->dado == dado)
		return NULL;
		
	if(raiz->dado > dado){
		
		if(raiz->esq != NULL && raiz->esq->dado == dado)
			return raiz;
			
		return busca_pai (raiz->esq, dado);
			
	}else if (raiz->dado < dado){
		
		if(raiz->dir != NULL && raiz->dir->dado == dado)
			return raiz;
			
		return busca_pai (raiz->dir, dado);
		
	}
	
	return 0;
}
//=======================================================
t_no* busca_folha_dir (t_no* raiz){

    if(raiz != NULL)
        if(raiz->dir != NULL)
            return busca_folha_dir (raiz->dir);

    return raiz;
}//end busca_folha_dir()
//=======================================================
t_no* remove_no (t_no* raiz, int numero){

    t_no *ptr_no     = NULL;
    t_no *ptr_return = NULL; 
    t_no *ptr_pai    = NULL;
    t_no *ptr_fusao  = NULL;

    if(raiz == NULL)   
        return NULL;

    ptr_no = busca (raiz, numero);

    if(ptr_no == NULL){
        printf("No de dado %d nao existe na arvore!!\n", numero);
        return raiz;
    }

    ptr_pai = busca_pai (raiz, ptr_no->dado);

    if(!ptr_pai) 
        printf ("Nao tem Pai - so pode ser raiz da arvore!\n");

    // 0 filhos
    if(ptr_no->esq == NULL && ptr_no->dir == NULL)
        ptr_return = NULL;

    // 1 filho
    if( (ptr_no->esq != NULL && ptr_no->dir == NULL) || 
        (ptr_no->esq == NULL && ptr_no->dir != NULL)) {

        if(ptr_no->esq != NULL){
            ptr_return = ptr_no->esq;
        }else{
            ptr_return = ptr_no->dir;
        }

    }

    // 2 filhos
    if(ptr_no->esq != NULL && ptr_no->dir != NULL){

        ptr_return      = ptr_no->esq;
        printf("ptr_return = %d\n", ptr_return->dado);

        ptr_fusao       = busca_folha_dir (ptr_return);
        printf("ptr_fusao = %d\n", ptr_fusao->dado);

        ptr_fusao->dir  = ptr_no->dir;
        printf("ptr_fusao->direita = %d\n", ptr_fusao->dir->dado);

    }

    if(ptr_pai != NULL){

        if( (ptr_pai->esq != NULL) && (ptr_pai->esq->dado == ptr_no->dado) ){
           
            ptr_pai->esq = ptr_return;
        
        }else if ( (ptr_pai->dir != NULL) && (ptr_pai->dir->dado == ptr_no->dado) ){

            ptr_pai->dir = ptr_return;

        }

        ptr_return = raiz;// so recebe se o pai do no a ser removido existir!

    }

    free (ptr_no);

    return ptr_return;

}//end remove_no()
//=======================================================
void libera_arvore(t_no* raiz){

    if(raiz == NULL) return;

    // deleta as subarvores
    libera_arvore(raiz->esq);
    libera_arvore(raiz->dir);

    // deleta o pai
    printf("Deletando no: %d\n", raiz->dado);

    free (raiz);
    
}
//=======================================================
int soma_nos (t_no* raiz){

    if (raiz == NULL)
        return 0;

    return (raiz->dado + soma_nos (raiz->esq) + soma_nos (raiz->dir));
}

