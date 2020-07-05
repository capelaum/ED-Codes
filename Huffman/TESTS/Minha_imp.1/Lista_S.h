#ifndef HEAD_H
#define HEAD_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
//===========================================================================
typedef struct no{
	char simbolo;
    int freq;
	
	struct no* prox;
}t_no;

typedef struct {
	t_no* primeiro;
	t_no* ultimo;
	
	int qtd;
}t_lista;
//===========================================================================
t_lista* aloca_lista      ();
t_no*    aloca_no         (int freq, char simbolo);

void     imprime_lista    (t_lista* lista);
void     apaga_lista      (t_lista* lista);
int      esta_vazia       (t_lista* lista);

int      inserir_ordenado (int freq, char simbolo, t_lista* lista);
int      remove_primeiro  (t_lista* lista);
//===========================================================================
#endif