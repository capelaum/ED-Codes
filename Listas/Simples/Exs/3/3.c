#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node{
	int num;
	
	struct node* next;
}t_node;

typedef struct{
	t_node* first;
	t_node* last;
	
	int size;
}t_list;
//==============================================
void delete_list(t_list* list){
	
	t_node* ptr = list->first;
	
	if(!empity_list(list)) {
		
		while(ptr!=NULL){
			list->first= list->first->next;
			free (ptr);
			ptr = list->first;
		}
	}else{
		printf("EMPITY LIST!\n");
	}
	
	free(list);
}//delete list
//==============================================
int empity_list (t_list* list){
	return (list->first == NULL && list->last == NULL);
}//is empity
//==============================================
void print_list(t_list* list){
	t_node* ptr = list->first;
	
	if(empity_list(list)){
		printf("EMPTY LIST!\n");
		return;
	}
	printf("Lista = ");
	while(ptr){
		printf("%d ", ptr->num);
		ptr = ptr->next;
	}
	printf("\nNumero total de nos: %d \n", list->size);
}//print
//==============================================
t_node* make_node (int x){
	t_node* new = (t_node*) malloc(sizeof(t_node));
	
	if(!new){
		printf("ERRO"); 
		exit;
	}
	
	new -> num = x;
	new ->next = NULL;
	
	return new;
}//make node
//==============================================
int end_insertion (int x, t_list* list){
	
	if(!list){
		printf("ERROR"); 
		exit;
	}
	
	t_node* ptr = make_node(x);
	
	if(ptr == NULL)
		return FALSE;
	
	
	if(empity_list(list)){
		list->first  = ptr;
	}else{
		list->last->next   = ptr;
		ptr->next = NULL;
	}
	
	list->last = ptr;
	
	list->size++;
	return TRUE;
}
//==============================================
t_list* make_list (){
	t_list* list = (t_list*) malloc(sizeof(t_list));
	
	if(!list){
		printf("\nERRO\n");
		exit;
	}
	
	list->first     = NULL;
	list->last      = NULL;
	list->size      = 0;
	
	return list;
}//aloca lista
//==============================================
int main() {
int N=4, value =7,i;
	
t_list* list = make_list();

printf("Insira o numero de nos: ");
	scanf("%d", &N);
	
for(i=1; i<=N ;i++){
	printf("Insira o valor para o no %d: ",i);
	scanf("%d", &value);
	end_insertion (value,list);
}

print_list(list);

delete_list(list);

return 0;
}
