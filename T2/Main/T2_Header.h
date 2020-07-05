
// Header da T2, contem as estruturas utilizadas pela arvore e a lista duplamente encadeada

#ifndef T2_H
#define T2_H


//==============================================================================
// ARVORE BINARIA - 5 niveis
// Figura 1 - definicao da estrutura no que forma a arvore binaria que representa o torneio
typedef struct node{

	Team* team;
	struct node* left;
	struct node* right;

} t_node;
//==============================================================================
// TIMES
// Figura 2 - definicao da estrutura Team que representa um time ( Selecao )
typedef struct {
	
	char* nome;
	
	int ataque; // 0 a 100
	int defesa; // 0 a 100
	int resistencia; // 0 a 100
	int velocidade; // 0 a 100
	
} Team;
//==============================================================================
// Lista dupla - elementos (times)
typedef struct elemento{
	Team* team;
	
	struct elemento* prox;
	struct elemento* ant;
}t_elemento;

// Lista dupla - controle
typedef struct {
	t_elemento* primeiro;
	t_elemento* ultimo;
	
	int qtd;
}t_lista;
//==============================================================================

t_node* node_create ();



#endif