/*	list_H
	Autor : Rafael Mascarenhas Dal Moro
	Matrícula: 17/0021041
	Professor: Marcos F. Caetano
	Disciplina: Estrutura de Dados - Turma A
	Última alteração: 27/5/2018
*/

#ifndef Circular_List_H
#define Circular_List_H

#define FALSE 0
#define TRUE 1

typedef struct element{ /* elemento da lista */
	int i;		
	struct element* next;
}t_element;

typedef struct{ /* lista circular simplesmente encadeada */ 
	t_element* first;
}t_list;

t_element* newElement(int i);	/* aloca um novo elemento da lista */
void removeElement(t_element * ptr);	/* remove um elemento da lista */

t_list* newCircularList();	/* aloca uma nova lista */
int isEmpty(t_list * list);	/* checa se a lista está vazia*/
void removeList(t_list* list);	/** apaga lista */
void cleanList(t_list* list);	/** limpa todos os elementos da lista */
void printList(t_list* list); /** imprime lista */

int insert(int i, int pos, t_list* list); /* insere elemento em posição especifica da lista */
int removeFirst(t_list * list); /*  remove elemento em posicao especifica da lista */
int removeTargeted(int pos, t_list * list); /*  remove elemento em posicao especifica da lista */
#endif /*list_H*/
