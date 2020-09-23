
#include "BST.h"

int main (){
    
    t_no* raiz = NULL;
    t_no* ptr  = NULL;
    int num = 0;

    raiz = inserir (raiz, 50);
    raiz = inserir (raiz, 17);
    raiz = inserir (raiz, 72);
   
    raiz = inserir (raiz, 83);
    raiz = inserir (raiz, 22);
    raiz = inserir (raiz, 11);

/*
              50
             /   \
           17     72
          / \    / \
         11  22 64  83
              
              
                 
             
*/


//==========================================================
    printf("=============================\n");

    printf("Arvore em pre_ordem: \n");
    pre_ordem (raiz);

    printf("=============================\n");

    ptr = busca_folha_dir (raiz);
    printf("Folha mais a direita: %d\n", ptr->dado);

    printf("=============================\n");

    printf("Informe o numero de busca: ");
    scanf("%d", &num);

    ptr = busca (raiz, num);

    if(ptr == NULL) 
        printf ("Numero %d nao encontrado! \n", num);
    else
        printf ("Numero encontrado: %d \n", ptr->dado);

    getchar();
    printf("=============================\n");

    printf("Informe o numero para descobrir o pai: ");
    scanf("%d", &num);

    ptr = busca_pai (raiz, num);

    if(ptr == NULL) 
        printf ("Numero %d é orfão! \n", num);
    else
        printf ("Pai de %d é: %d \n",num, ptr->dado);

    getchar();
    printf("=============================\n");
   
    printf("Informe um numero para ser removido: ");
    scanf("%d", &num);

    raiz = remove_no (raiz, num);

    if(!raiz)
        printf("Raiz foi perdida!\n"); 

    printf("=============================\n");

    printf("Em largura: \n");
    percurso_largura (raiz);

    printf("=============================\n");
    libera_arvore (raiz);
    printf("=============================\n");

    raiz = NULL;// nao fica null, nao sei pq..
    return 0;
}