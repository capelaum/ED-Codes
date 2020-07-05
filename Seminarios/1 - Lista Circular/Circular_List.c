/*	Circular_List_CPP 
	Autor : Rafael Mascarenhas Dal Moro e Guilherme Mendel de Almeida Nascimento
	Revisão: Gabriel Rodrigues Pacheco
	Matrículas: 17/0021041, 17/0143970, 17/0058280, respectivamente
	Professor: Marcos F. Caetano
	Disciplina: Estrutura de Dados - Turma A
	Última alteração: 04/06/2018
*/

#include <stdlib.h>
#include <stdio.h>
#include "Circular_List.h"

t_element* newElement(int i){
	t_element* ptr = (t_element*) malloc(sizeof(t_element));
	if(ptr == NULL)
		return NULL;
	ptr->next = NULL;
	ptr->i = i;	
	return ptr;	
}

void removeElement(t_element * ptr){
	free(ptr);
}

t_list* newCircularList(){
	t_list* list = (t_list*) malloc(sizeof(t_list));
	if(list == NULL)
		return NULL;
	list->first = NULL;
	return list;
}

int isEmpty(t_list * list){
	return (list->first == NULL);
}
int insert(int i, int pos, t_list* list){ 
	int j;	
	t_element * aux;
	t_element * ptr = newElement(i);	
	if(ptr == NULL)
		return FALSE;
	if((isEmpty(list))){
		list->first = ptr;
		ptr->next = ptr;
	}
	else if(pos==1) {
		ptr->next = list->first;
		list->first = ptr;
		for(aux = ptr->next; aux->next != ptr->next; aux = aux->next);
		aux->next = ptr;
	}
	else{		
		for(aux = list->first, j=1; (aux->next != list->first) && (j<pos-1); j++){
			aux= aux->next;
		}
		ptr->next = aux->next;
		aux->next = ptr;
	}
	return TRUE;
} 

int removeTargeted(int pos, t_list * list){ 	 
	if(isEmpty(list)){
		return FALSE;	
	}
	t_element * ptr = list->first;	
	if(ptr->next == NULL){ /* checa se há apenas um elemento */ 
		if(pos == 1)list->first = NULL;
		else{
			return FALSE;		
		}
	}else if(pos==1){
		list->first = ptr->next;
	}else{
		int j;
		for(j=1; j<pos-1; j++, ptr = ptr->next) if(ptr->next == list->first) return FALSE;
		t_element *aux = ptr->next;
		ptr->next = aux->next;
		free(aux);
		return TRUE;
	}
	removeElement(ptr); 
	return TRUE;
}

int removeFirst(t_list * list){ 	 
	if(isEmpty(list)){
		return FALSE;	
	}
	t_element * ptr = list->first;	
	if(ptr->next == ptr){
		list->first = NULL;
	}else{
		list->first = ptr->next;
		t_element *aux;
		for(aux = ptr->next; aux->next != ptr; aux = aux->next);
		aux->next = ptr->next;
	}
	removeElement(ptr); 
	return TRUE;
}
void removeList(t_list* list){
	while(removeFirst(list));
	free(list);
}

void cleanList(t_list* list){
	while(removeFirst(list));
}

void printList(t_list* list){
	t_element * ptr = list->first;
	int i=0;	
	if(isEmpty(list))
		printf("Lista Vazia!\n");
	else do{
		printf("%d. %d\n",(i++)+1, ptr->i);
		ptr = ptr->next;
	}while(ptr != list->first );
}
