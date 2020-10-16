
#ifndef __FILA_H__
#define __FILA_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef int ItemType;

typedef struct elemento{
    ItemType dado;
    struct elemento* proximo;
}t_no;

typedef struct {
    t_no* primeiro;
    t_no* ultimo;

    int qtd;
}t_fila;

//========================================================
void  inserir_na_fila (ItemType dado, t_fila* fila);
ItemType   remover         (t_fila* fila);

bool  esta_vazia     (t_fila* fila);
void libera_fila    (t_fila* fila);

t_fila*     aloca_fila ();
t_no* aloca_elemento (ItemType dado);

void imprime_fila(t_fila* fila);

#endif