// 2.7 - prototipos de funcoes

#include "T2_Header.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

t_node* node_create (){

    t_node* ptr = (t_node*) malloc(sizeof(t_node));
	
	if(!ptr)  return false;

	ptr->team  = NULL;
	ptr->left  = NULL;
	ptr->right = NULL; 

}
/* retorna endereço para estrutura do tipo t_node alocada dinami-
camente. Os ponteiros team, left e right são inicializados com
o valor NULL */

Team* team_create (char* _nome, int _ataque, int _defesa, int _resistencia, int _velocidade){

    Team* team = (Team*) malloc(sizeof(Team)); // aloca ponteiro para struct Team
	
	if(!team){
		free(team);
		return false;
	}
	
    team->nome = (char*) malloc (sizeof(strlen(_nome)+1)); // aloca espaço para a string nome recebida
    strcpy (team->nome, _nome); // copia a string recebida para o espaço recem alocado

	team->ataque      = _ataque;
	team->defesa      = _defesa;
    team->resistencia = _resistencia;
    team->velocidade  = _velocidade;

	return team;

}
/* aloca dinamicamente memória para estrutura do tipo Team. Inici-
aliza POR CÓPIA os atributos nome, ataque, defesa, resistencia
e velocidade, utilizando, respectivamente, os parâmetros _nome,
_ataque, _defesa, _resistencia e _velocidade. Ao final, a
função retorna o endereço para estrutura Team alocada  */

void team_free (Team* team){
    free(team->nome);
	free(team);
}
/* libera a memória alocada e referenciada por team */

t_node* tree_create (){


	t_node* tree = node_create ();

	node->left  = node;
	node->right = node


}

/* 
Retorna o endereço para o nó raiz de uma da árvore binária completa de quatro nı́veis. 
TODOS os nós da árvore apresentam o atributo team apontado para NULL 
*/


void tree_free (t_node* tree){

	if(tree == NULL) 
		return;

    // deleta as subarvores
    libera_arvore(tree->left);
    libera_arvore(tree->right);

    // deleta o pai
    printf("Deletando time: %s\n", tree->team->nome);

	free (tree->team);
    free (tree);
}
/* remove de forma recursiva todos os nós presentes da árvore. A
memória referente ao atributo team também deve ser liberada */


Team* match (Team* team_one, Team* team_two, int attribute);
/* Compara o valor do atributo definido por attribute do team_one
com o do team_two, retornando o ponteiro para o time vencedor.
Em caso de empate, o ponteiro para team_one deverá ser retor-
nado */


void tree_print_preorder (t_node* root){

	if(root != NULL){
		printf ("Time %s\n", root->team->nome);
		pre_ordem (root->left);
		pre_ordem (root->right);
	}

}
/* percore a árvore binária em pré-ordem, imprimindo os times re-
ferenciados em team */