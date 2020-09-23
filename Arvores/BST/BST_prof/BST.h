

// Header - arvore BST do professor Caetano

#ifndef __ARVORE_H__
#define __ARVORE_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct no{
    int dado;
    
    struct no* esq;
    struct no* dir;
}t_no;

//======================================================
t_no* busca           (t_no* raiz, int dado);
t_no* busca_pai       (t_no* raiz, int dado);
t_no* busca_folha_dir (t_no* raiz);

t_no* remove_no       (t_no* raiz, int dado);

t_no* aloca_no (int dado);
t_no* inserir  (t_no* raiz, int dado);

void pre_ordem (t_no* raiz);
void em_ordem  (t_no* raiz);
void pos_ordem (t_no* raiz);

void percurso_largura (t_no* raiz);

void libera_arvore    (t_no*raiz);

#endif //  __ARVORE_H__