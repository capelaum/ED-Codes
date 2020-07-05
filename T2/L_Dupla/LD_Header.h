
#ifndef _LD_H_
#define _LD_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//=================================================================
// Figura 2 - definicao da estrutura Team que representa um time ( Selecao )
typedef struct {
	
	char* nome; // ponteiro para string nome - alocado dinamicamente
	
	int ataque; // 0 a 100
	int defesa; // 0 a 100
	int resistencia; // 0 a 100
	int velocidade; // 0 a 100
	
} Team;
	
//=================================================================
// elementos da Lista duplamente encadeada
typedef struct elemento{
	Team* team; // ponteiro para struct Team
	
	struct elemento* proximo;
	struct elemento* anterior;
}t_elemento;

// controle da Lista duplamente encadeada
typedef struct {
	t_elemento* primeiro;
	t_elemento* ultimo;
	
	int qtd;
}t_lista;
//=================================================================
// Prototipos

t_elemento* aloca_elemento (char* nome, int ataque, int defesa, int resistencia, int velocidade);
t_lista* aloca_lista ();

void apaga_lista(t_lista* lista);
void remove_elemento (t_elemento* elemento);

int esta_vazia(t_lista* lista);

void imprime_lista(t_lista* lista);

int inserir_inicio (char* nome, int ataque, int defesa, int resistencia, int velocidade, t_lista* lista);

int inserir_final (char* nome, int ataque, int defesa, int resistencia, int velocidade, t_lista* lista);

int remove_inicio (t_lista* lista);
int remove_final  (t_lista* lista);
int remove_pos    (int pos, t_lista* lista);
//=================================================================
#endif