#include <stdio.h>
#include <stdlib.h>
#include "avl_2.h"



//Aloca o no para inserir 

elemento *aloca_no(int dado){

	elemento *novo_no 				= (elemento *) malloc(sizeof(elemento)); //Aloca novo no 

	novo_no->dado     				= dado;//recebe o dado 

	novo_no->fator_de_balanceamento = 0;//fator de balanceamento do no 

	novo_no->esq	  				= NULL;// no esquerda e setado pra NULL

	novo_no->dir      				= NULL;// no direito e setado pra NULL

	return novo_no;//retorna no

}

//Aloca ponteiro de ponteiro pra arvore 

Arv_AVL *aloca_arvore(){

	Arv_AVL *raiz = (Arv_AVL *) malloc(sizeof(Arv_AVL));//faz a alocação 

	if(raiz != NULL){//se a raiz não tiver nula 

		*raiz = NULL;//então coloca ela como nula
	}

	return raiz;//retorna a raiz

}


//percorre a arvore e libera cada no
void libera_no(elemento *no){

	if(no == NULL){
		return;//se o no for NULL não faça nada  
	}

	libera_no(no->esq);//anda pos-ordem na arvore 
	libera_no(no->dir);//anda em pos-ordem na arvore 
	free(no);//da free no no

	no = NULL;// coloca null no pra evitar verificações posteriores

}


//libera o ponteiro de ponteiro pra raiz 
void libera_arvore(Arv_AVL *raiz){

	if(raiz == NULL){//verifica se raiz não e vazia 
		return;
	}
	libera_no(*raiz);//passo a raiz para o libera os no para percorrer a arvore e liberar os nos 
	free(raiz);//dou ponteiro de ponteiro da raiz
}

//altura do no
int altura(elemento *no){//calcula a altura do no

	if (no == NULL){//se chegar no maximo da direita ou da esquerda retorna zero e vai somando mais 1 a cada recursão
		return 0;
	}

	int alt_esq = altura(no->esq);//vai ao máximo da esquerda do no
	int alt_dir = altura(no->dir);//vai ao máximo da direita do no

	if(alt_esq > alt_dir){	//verifica qual altura da subarvore e maior e acrescente um 
		return alt_esq + 1;
	}
	else {
		return alt_dir + 1;//calcula maior altura do no da arvore 
	}

}

//calcula o fator de balanceamento do no 
int calcula_fat_bal(elemento *no){

	
	int fat_bal = altura(no->esq) - altura(no->dir);//usa a definicação do fator de balanceamento do no

	no->fator_de_balanceamento = fat_bal;//passa pra estrutura do no

	return fat_bal;

}



int fat_bal_no(elemento *no){//retorna o fator de balanceamento do no

	if(no == NULL){//se o no for null retorna -1 

		return -1;

	}
	else{
		
		return no->fator_de_balanceamento;//se não retorna o valor de seu fator de balanceamento

	}
}


//faz uma rotação simples pra direita
void rotacao_LL(Arv_AVL *raiz){

	elemento *aux;//seta um ponteiro auxiliar

	aux          = (*raiz)->esq;//ponteiro auxiliar aponta pra esquerda 

	(*raiz)->esq = aux->dir;//raiz esquerda recebe aux direita

	aux->dir     = *raiz; 

	calcula_fat_bal(*raiz);//calcula novo fator de balanceamento 

	calcula_fat_bal(aux);//calcula novo fator de balanceamento 

	*raiz        = aux;//seta a nova raiz 

}

//faz uma rotação simples pra esquerda 
void rotacao_RR(Arv_AVL *raiz){

	elemento *aux;//seta um ponteiro auxiliar

	aux          = (*raiz)->dir;//ponteiro auxiliar aponta pra esquerda

	(*raiz)->dir = aux->esq;//raiz direita troca com a sub-arvore esquerda

	aux->esq     = *raiz;//sub-arvore esq troca com raiz 

	calcula_fat_bal(*raiz);

	calcula_fat_bal(aux);

	*raiz        = aux;//atualiza nova raiz

}


//faz uma rotação dupla pra esquerda 
void rotacao_LR(Arv_AVL *raiz){

	rotacao_RR(&(*raiz)->esq);//rotação simples pra esquerda
	rotacao_LL(raiz);//rotação simples pra direita
}

//faz uma rotação dupla pra direita 

void rotacao_RL(Arv_AVL *raiz){

	rotacao_LL(&(*raiz)->dir);//rotação simples pra direita
	rotacao_RR(raiz);//rotação simples pra esquerda

}

int inseri_AVL(Arv_AVL *raiz, int valor){

	int ret;

	if(*raiz == NULL){

		elemento *novo = aloca_no(valor);

		*raiz          = novo;

		return 1;
	}
	
		elemento *atual = *raiz;

		if(valor < atual->dado){

			if(ret = inseri_AVL(&(*raiz)->esq,valor) == 1){

				if(calcula_fat_bal(atual) >=  2 || calcula_fat_bal(atual) <= -2){

					if(valor < (*raiz)->esq->dado){

						rotacao_LL(raiz);
					}
					else {
						rotacao_LR(raiz);
					}

				}
			}
		}
		else if(valor > atual->dado){	
			if(ret = inseri_AVL(&(*raiz)->dir,valor) == 1){
				if(calcula_fat_bal(atual) <= -2 || calcula_fat_bal(atual) >= 2){
					if(valor > (*raiz)->dir->dado){
						rotacao_RR(raiz);

					}
					else {

						rotacao_RL(raiz);
					}
				}
			}
		}
		
		else {
			printf("O valor ja existe!!\n");
			return -1;
		}


		return ret;
}


void mostra_arvore(Arv_AVL *raiz){

	if(*raiz != NULL){
		printf("No : %d\n Tem fator de balanceamento: %d\n", (*raiz)->dado, (*raiz)->fator_de_balanceamento);
		mostra_arvore(&(*raiz)->esq);
		mostra_arvore(&(*raiz)->dir);
	}
}

