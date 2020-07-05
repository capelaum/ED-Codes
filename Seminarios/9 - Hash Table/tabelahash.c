#ifndef TABELA_C
#define TABELA_C
#define TRUE 1
#define FALSE 0
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "tabelahash.h"


void IniciaTabela(tabela *tabela){
	for(int i = 0; i < 10; i++){
		tabela[i].primeiro = NULL;
	}
}

int CriaAluno(char *nome, int matricula, float n1, float n2, float n3, tabela *ptr){

	elemento *elem = (elemento*) malloc(sizeof(elemento));
	if(elem == NULL)
		return FALSE;

	elem->aluno    = (aluno*) malloc(sizeof(aluno));
	if(elem->aluno == NULL){
		free(elem);
		return FALSE;
	}

	elem->aluno->matricula = matricula;
	strcpy (elem->aluno->nome, nome);
	elem->aluno->n1 = n1;
	elem->aluno->n2 = n2;
	elem->aluno->n3 = n3;
	elem->proximo  = NULL;
	elem->anterior = NULL;

	InsereAluno(ptr,elem);

}//----------------------------------------------> Cria um elemento


int InsereAluno(tabela *tab, elemento *elem){
	
	int i = elem->aluno->matricula % 10;
	

	if(i > 10){
		printf("O resto da divisao deu maior que 10\n");
		return FALSE;
	}

	if(tab[i].primeiro == NULL){
		tab[i].primeiro = elem;
		tab[i].quantidade++;
		return TRUE;
	} else{
		tab[i].primeiro->anterior = elem;
		elem->proximo = tab[i].primeiro;
		tab[i].primeiro = elem;
		tab[i].quantidade++;
		return TRUE;
	}
} //----------------------------------------------> Insere aluno nas listas


void DestroiTabela(tabela *tabela){
	
	elemento *ptr;

	for(int i=0; i < 10; i++){
		ptr = tabela[i].primeiro;
		while(ptr != NULL){                                //Lista vazia
			if(tabela[i].primeiro->proximo == NULL){    			   //Lista com apenas um elemento
				tabela[i].primeiro = NULL;
				free(ptr->aluno);
				free(ptr);
				ptr = tabela[i].primeiro;
			} else{                                        //lista com varios elementos
				tabela[i].primeiro = ptr->proximo;
				tabela[i].primeiro->anterior = NULL;
				free(ptr->aluno);
				free(ptr);
				ptr = tabela[i].primeiro;
			}

		}
	}

}

void ImprimeTabela(tabela *tabela){
	elemento *ptr;

	for(int i=0; i < 10; i++){
		ptr = tabela[i].primeiro;
		printf("%d: ", i);
		while(ptr != NULL){
			printf("%d %s", ptr->aluno->matricula, ptr->aluno->nome);
			printf(" -> ");
			ptr = ptr->proximo;
		}
		printf("%p", ptr);
		printf("\n");
	}
}

elemento* BuscaElemento(tabela *tab, int matricula){
	
	int i = matricula % 10;
	elemento *ptr = tab[i].primeiro;

	while(ptr != NULL && matricula != ptr->aluno->matricula){
		ptr = ptr->proximo;
	}
	return ptr;
}



void RemoveElemento(tabela *tab, int matricula){

	elemento *elem = BuscaElemento(tab, matricula);
	int i = matricula % 10;

	if (elem == NULL){
		printf("Nao fui possivel remover o elemento, elemento nao econtrado!\n");
	} else{
		if(elem == tab[i].primeiro && elem->proximo == NULL){                       //Apenas um elemento da lista
			tab[i].primeiro = elem->proximo;
			free(elem->aluno);
			free(elem);
			tab[i].quantidade--;
			printf("Elemento removido!\n");
		} else if(elem == tab[i].primeiro && elem->proximo != NULL){				//Primeiro elemento e proximo != NULL
			tab[i].primeiro = elem->proximo;
			elem->proximo->anterior = elem->anterior;
			free(elem->aluno);
			free(elem);
			tab[i].quantidade--;
			printf("Elemento removido!\n");
			
		} else if(elem->proximo == NULL){											//Ultimo elemento da lista
			elem->anterior->proximo = elem->proximo;
			free(elem->aluno);
			free(elem);
			tab[i].quantidade--;
			printf("Elemento removido!\n");
		} else{																		//Qualquer outro elemento
			elem->proximo->anterior = elem->anterior;
			elem->anterior->proximo = elem->proximo;
			free(elem->aluno);
			free(elem);
			tab[i].quantidade--;
			printf("Elemento removido!\n");
		}
	}

	
}
#endif
