// 2.7 - prototipos de funcoes

typedef struct node{

	Team* team;
	struct node* left;
	struct node* right;

} t_node;

typedef struct {
	
	char* nome;
	
	int ataque; // 0 a 100
	int defesa; // 0 a 100
	int resistencia; // 0 a 100
	int velocidade; // 0 a 100
	
} Team;

t_node* node_create ();

/* 
Retorna endereço para estrutura do tipo t_node alocada dinamicamente. 
Os ponteiros team, left e right são inicializados com o valor NULL 
*/

Team* team_create (char* _nome, int _ataque, int _defesa, int _resistencia, int _velocidade);
/* 
Aloca dinamicamente memória para estrutura do tipo Team. 
Inicializa POR CÓPIA os atributos nome, ataque, defesa, resistencia
e velocidade, utilizando, respectivamente, os parâmetros _nome,
_ataque, _defesa, _resistencia e _velocidade. Ao final, a
função retorna o endereço para estrutura Team alocada  
*/


void team_free (Team* team);
/* libera a memória alocada e referenciada por team */

t_node* tree_create ();
/* retorna o endereço para o nó raiz de uma da árvore binária com-
pleta de quatro nı́veis. TODOS os nós da árvore apresentam o
atributo team apontado para NULL */


void tree_free (t_node* tree);
/* remove de forma recursiva todos os nós presentes da árvore. A
memória referente ao atributo team também deve ser liberada */


Team* match (Team* team_one, Team* team_two, int attribute);
/* Compara o valor do atributo definido por attribute do team_one
com o do team_two, retornando o ponteiro para o time vencedor.
Em caso de empate, o ponteiro para team_one deverá ser retor-
nado */


void tree_print_preorder (t_node* root);
/* percore a árvore binária em pré-ordem, imprimindo os times re-
ferenciados em team */