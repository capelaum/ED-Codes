#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MALLOC(a) (a*)malloc(sizeof(a))

typedef struct no{
	int dado;
	
	struct no* proximo;
}t_no;

typedef struct {
	t_no* primeiro;
	t_no* ultimo;
	
	int qtd;
}t_lista;

//Funçoes:
//------------------------------------------
int inserir_inicio (int x, t_lista* lista);

t_no* aloca_no(int x);
void remove_no(t_no* no);


t_lista* aloca_lista();
void apaga_lista(t_lista* lista);
int esta_vazia(t_lista* lista);
//--------------------------------------------
int inserir_inicio (int x, t_lista* lista){

	t_no* ptr = aloca_no(x);

	if(ptr==NULL)
		return FALSE;

	if(lista->primeiro == NULL){
		lista->ultimo   = ptr;
	}
	
	ptr->proximo = lista->primeiro;
	
	lista->primeiro = ptr;
	
	lista->qtd++;

	return TRUE;
}//inserir Inicio
//--------------------------------------

//--------------------------------------
t_no* aloca_no (int x){
	t_no* novo = (t_no*) malloc(sizeof(t_no));
	
	if(!novo){
		printf("ERRO"); 
		exit;
	}
	
	novo->dado = x;
	novo->proximo = NULL;
	
	return novo;
}//aloca no
//--------------------------------------

//--------------------------------------
t_lista* aloca_lista (){
	t_lista* lista = (t_lista*) malloc(sizeof(t_lista));
	
	if(!lista){
		printf("\nERRO\n");
		exit;
	}

	lista->primeiro = NULL;
	lista->ultimo = NULL;
	lista->qtd = 0;
	
	return lista;
}//aloca lista
//--------------------------------------

//--------------------------------------
int esta_vazia (t_lista* lista){
	return (lista->primeiro == NULL && lista->ultimo == NULL);
}//esta vazia
//--------------------------------------

//--------------------------------------
void apaga_lista(t_lista* lista){
	t_no* ptr = lista->primeiro;
	
	if(!esta_vazia(lista)) {
		
		while(ptr!=NULL){
			lista->primeiro = lista->primeiro->proximo;
			free (ptr);
			ptr = lista->primeiro;
		}
	}
	
	free(lista);
}//apaga lista
//--------------------------------------

//--------------------------------------
void imprime_lista (t_lista* lista){
	t_no* ptr = lista->primeiro;
	
	if(esta_vazia(lista)){
		printf("LISTA VAZIA!\n");
		return;
	}
	
	printf(">Lista Invertida = ");
	
	while(ptr!=NULL){
		printf("%d ",ptr->dado);
		ptr = ptr->proximo;
	}
	
	printf("\n>qtd: %d\n", lista->qtd);
}//Imprime
//--------------------------------------

int main() {
int N=4, dado=7,i;
	
t_lista* lista = aloca_lista();

printf("Insira o numero de nos: ");
	scanf("%d", &N);
	
for(i=1;i<=N;i++){
	printf("Insira o valor para o no %d: ",i);
	scanf("%d", &dado);
	inserir_inicio(dado,lista);
}

imprime_lista(lista);

apaga_lista(lista);
	
	return 0;
}




