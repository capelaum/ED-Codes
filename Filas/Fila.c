
// Fila.c - prof. Caetano

#include "Fila.h"
#include <stdlib.h>
#include <stdio.h>

/********************************************/
void inserir_na_fila (t_no* valor, t_fila* fila){
    
    t_elemento* ptr = aloca_elemento(valor);

    if(esta_vazia(fila)){
        fila->primeiro = ptr;
    }else{
        fila->ultimo->proximo = ptr;
    }

    fila->ultimo = ptr;

}//end inserir()
/********************************************/
t_no* remover (t_fila* fila){

    t_elemento* ptr = fila->primeiro;

    if(esta_vazia(fila)){

        printf("Fila está vazia!\n");
        free (fila);
        exit (-1);
    }

    t_no* resultado = ptr->dado;

    if(fila->primeiro == fila->ultimo)
        fila->ultimo = NULL;
    
    fila->primeiro = fila->primeiro->proximo;
   
    free(ptr);

    return resultado;

}//end remover()
/********************************************/
void libera_fila (t_fila* fila){

    t_elemento* ptr = fila->primeiro;

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
int esta_vazia (t_fila* fila){
    return (fila->primeiro == NULL && fila->ultimo == NULL);
}// end esta_vazia()
/********************************************/
t_fila* aloca_fila (){
    
    t_fila* ptr = (t_fila*) malloc (sizeof(t_fila));

    ptr->primeiro = NULL;
    ptr->ultimo   = NULL;

    return ptr;
}// end aloca_fila()
/********************************************/
t_elemento* aloca_elemento (t_no* dado){

    t_elemento* ptr = (t_elemento*) malloc (sizeof(t_elemento));

    ptr->dado    = dado;
    ptr->proximo = NULL;

    return ptr;

}//end aloca_elemento ()
/********************************************/






