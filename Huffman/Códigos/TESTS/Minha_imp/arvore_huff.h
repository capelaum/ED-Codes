

#ifndef arvore_huff_h
#define arvore_huff_h

#include "Lista_S.h"

typedef struct no_h{
    int  freq;
    char simb;

    struct no_h* esq;
    struct no_h* dir;
}t_no_h;

//=======================================================
t_no_h* aloca_no_folha  (int freq, char simbolo);
t_no_h* aloca_no_raiz   (t_no_h* ptr1, t_no_h* ptr2);

void pre_ordem          (t_no_h* raiz);
int qtd                 (t_no_h* raiz);

t_no_h* cria_arvore     (t_lista* lista);
void    libera_arvore   (t_no_h* raiz);
//=======================================================

void imprime_caminhos   (t_no_h* raiz);
void imprime_caminho    (int caminho[],char caminhoc[], int tam);
void caminhos_recur     (t_no_h* raiz, int caminho[], char caminhoc[], int caminho_tam);

#endif // arvore_huff_h