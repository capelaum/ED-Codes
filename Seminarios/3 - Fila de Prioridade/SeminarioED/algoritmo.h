/*  Aluno1: Lucas Mendonça Macedo Amaral
    Aluno2: Davi Cunha Dupin
    Aluno3:Lucas Verissimo Botelho
    Materia: Estrutura de dados(Marcos F. Caetano)
                                                    */


typedef struct arvore{
    int prioridade;
    struct arvore *esquerda;
    char nome[100];
    struct arvore *direita;
} t_arvore;



//assinaturas----------------------------------------------------
t_arvore *alocaelemento();
int estavazia(t_arvore *ptr);
t_arvore *acharelemento(t_arvore *ptr, int posicao);
int verificanode(t_arvore *ptr);
void troca(t_arvore *ptr, t_arvore *aux);
void organiza(t_arvore *ptr, int posicao);
int inserirelemento(t_arvore *ptr, int *posicao, int prioridade, char *nome);
void organizaquandoremove(t_arvore *ptr);
void removerelemento(t_arvore *ptr, int *posicao);
int novazio(t_arvore *ptr);
void destroifila(t_arvore *ptr, int *posicao);
//endassinaturas-------------------------------------------------
