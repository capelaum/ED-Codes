#include <stdio.h>
#include <stdlib.h>

//============================================================
//Programing C - list of 2 itens
struct node {
  int x;
  
  struct node *next;
};

int main()
{

struct node *root, *conductor;  

int valor;

root = malloc( sizeof(struct node) );  
root->next = 0;   

printf("Insira o valor para o no 1: ");
scanf("%d", &valor);
root->x = valor;
conductor = root; 
    
if ( conductor != 0 ) {
    while ( conductor->next != 0)
	        conductor = conductor->next;
}
    
/* Creates a node at the end of the  list */
conductor->next = malloc( sizeof(struct node) );  

conductor = conductor->next; 

if ( conductor == 0 ){
    printf( "Out of memory" );
    return 0;
}
    
/* initialize the new memory */
conductor->next = 0; 

printf("Insira o valor para o no 2: ");
scanf("%d", &valor);        
conductor->x = valor;

/* Repeat  */
conductor->next = malloc( sizeof(struct node) );
conductor = conductor->next; 
  
if ( conductor == 0 ){
    printf( "Out of memory" );
    return 0;
}
  
conductor->next = 0; 

printf("Insira o valor para o no 3: ");
scanf("%d", &valor);
conductor->x = valor;
    
imprime (root);
	
apaga_lista (root);

conductor=NULL;
root=NULL;

	return 0;
}

void apaga_lista(struct node* ptr){
	while (ptr) {
	    struct node *aux = ptr;
	    ptr = ptr->next;
	    free(aux);
	}
}

void imprime (struct node* raiz){
printf("Lista = ");
    while (raiz){
        printf("%d ",raiz->x);
        raiz = raiz->next;
    }
    
}
