#ifndef __DEQUE_H__
#define __DEQUE_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Aviao{
    char *companhia;
    int combustivel;
    int desviado;
}nave;

typedef struct elemento{
    nave *atual;
    struct elemento *proximo;
    struct elemento *anterior;
} a_elemento;

typedef struct Deque{
    a_elemento *prioriodade;
    a_elemento *final;
    int quantidade;
} a_deque;

a_deque *cria_deque();
void apagar_elemento(a_elemento *elemento);
a_elemento *criar_elemento(char *companhia, int combustivel);
void inserir_final(a_deque *deque,char *companhia, int combustivel);
void inserir_prioridade(a_deque *deque, char *companhia, int combustivel);
void remover_prioridade(a_deque *deque);
void remover_final(a_deque *deque);
void apagar_deque(a_deque *deque);
void imprimir_deque(a_deque *deque);
void reduzir_combustao(a_deque *deque);
int alternar_destino(a_deque *deque);
void mover_final(a_deque *deque, a_elemento *ptr);
void remover_inativos(a_deque *deque);

#endif

