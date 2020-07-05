
#ifndef __FILA_H__
#define __FILA_H__

#include "BST.h"

typedef struct elemento{
    t_no* dado;
    struct elemento* proximo;
}t_elemento;

typedef struct {
    t_elemento* primeiro;
    t_elemento* ultimo;
}t_fila;

//========================================================
void  inserir_na_fila (t_no* valor, t_fila* fila);
t_no* remover         (t_fila* fila);

int  esta_vazia     (t_fila* fila);
void libera_fila    (t_fila* fila);

t_fila*     aloca_fila ();
t_elemento* aloca_elemento (t_no* dado);


#endif