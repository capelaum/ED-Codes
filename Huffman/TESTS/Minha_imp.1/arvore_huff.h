
#include "Lista_S.h"

#ifndef arvore_huff_h
#define arvore_huff_h

typedef struct no_h{
    int  freq;
    char simb;

    struct no_h* esq;
    struct no_h* dir;
}t_no_h;

//=======================================================
t_no_h* aloca_no_folha (int freq, char simbolo);
t_no_h* aloca_no_raiz  (t_no_h* ptr1, t_no_h* ptr2);

void pre_ordem         (t_no_h* raiz);
int qtd                (t_no_h* raiz);

void libera_arvore     (t_no_h* raiz);
//=======================================================
// Caminhos
void imprime_caminhos  (t_no_h* raiz);
void imprime_caminho   (int caminho[], char caminhoc[], int tam);
void caminhos_recur    (t_no_h* raiz, int caminho[], char caminhoc[], int tam);

//=======================================================
#endif // arvore_huff_h