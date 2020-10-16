
// Fila.c - prof. Caetano

#include "Fila.h"

/********************************************/
void inserir_na_fila (ItemType dado, t_fila* fila){
    
    t_no* ptr = aloca_elemento(dado);

    if(esta_vazia(fila)){
        fila->primeiro = ptr;
    }else{
        fila->ultimo->proximo = ptr;
    }

    fila->ultimo = ptr;
    fila->qtd++;

}//end inserir()
/********************************************/
ItemType remover (t_fila* fila){

    t_no* ptr = fila->primeiro;

    if(esta_vazia(fila)){
        printf("Fila está vazia!\n");
        free (fila);
        exit (-1);
    }

    ItemType resultado = ptr->dado;

    printf("Item removido: %d\n", resultado);

    if(fila->primeiro == fila->ultimo)
        fila->ultimo = NULL;
    
    fila->primeiro = fila->primeiro->proximo;

    free(ptr);

    return resultado;
}//end remover()
/********************************************/
void libera_fila (t_fila* fila){

    t_no* ptr = fila->primeiro;

    if(!esta_vazia(fila)){

        while (ptr != NULL){
            fila->primeiro = fila->primeiro->proximo;

            free(ptr);

            ptr = fila->primeiro;
        }// end while
    }// end if (!esta_vazia())
    
    free (fila);
}// end apaga_fila()
/********************************************/
bool esta_vazia(t_fila* fila){
    return (fila->primeiro == NULL && fila->ultimo == NULL);
}// end esta_vazia()
/********************************************/
t_fila* aloca_fila (){
    
    t_fila* ptr = (t_fila*) malloc (sizeof(t_fila));

    ptr->primeiro = NULL;
    ptr->ultimo   = NULL;
    ptr-> qtd = 0;

    return ptr;
}// end aloca_fila()
/********************************************/
t_no* aloca_elemento (ItemType dado){

    t_no* ptr = (t_no*) malloc (sizeof(int));

    ptr->dado    = dado;
    ptr->proximo = NULL;

    return ptr;

}//end aloca_elemento ()
/********************************************/
void imprime_fila(t_fila* fila){

    t_no* ptr = fila->primeiro;
	
	if(esta_vazia(fila)){
		printf("Fila VAZIA!\n");
		return ;
	}

	while(ptr) {
        printf("%d ", ptr->dado);
        ptr = ptr->proximo;
    }
	
	printf("\n>Tamanho da fila: %d \n", fila->qtd);
}





