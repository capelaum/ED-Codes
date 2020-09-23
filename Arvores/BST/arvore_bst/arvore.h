// everybody gotta start somewhere

// Arquivo header - structs da arvore
//  do pdf de exercicios

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef arvore_1
#define arvore_1

typedef struct no{
    
   int dado;
    
   struct no* esq;
   struct no* dir;

}t_no;

//=======================================================
// arvore_1

t_no* aloca_no        (int dado);
t_no* inserir         (t_no* raiz, int dado);

void pre_ordem        (t_no* raiz);
void em_ordem         (t_no* raiz);
void pos_ordem        (t_no* raiz);

t_no* busca           (t_no* raiz, int dado);
t_no* busca_pai       (t_no* raiz, int dado);
t_no* busca_folha_dir (t_no* raiz);

t_no* remove_no       (t_no* raiz, int numero);

void libera_arvore    (t_no*raiz);

int soma_nos         (t_no* raiz);

//=======================================================
// arvore_2.c

int Menor_Valor      (t_no* raiz);
int Maior_Valor      (t_no* raiz);
int Max_Profundidade (t_no* raiz);

int qtd              (t_no* raiz);

int Soma_caminho     (t_no* raiz, int soma);

void printPaths      (t_no* raiz);
void printPathsRecur (t_no* raiz, int path[], int pathLen);
void imprime_array   (int ints[], int len);

int countTrees       (int numKeys);
int isBST            (t_no* raiz);

//=======================================================
#endif // arvore_1
