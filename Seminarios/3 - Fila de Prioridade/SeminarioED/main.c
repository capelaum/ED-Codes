/*  Aluno1: Lucas Mendonça Macedo Amaral
    Aluno2: Davi Cunha Dupin
    Aluno3:Lucas Verissimo Botelho
    Materia: Estrutura de dados(Marcos F. Caetano)
                                                    */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "algoritmo.h"






//funcoes-------------------------------------------------
void menu(){
    t_arvore *ptr=alocaelemento();
    int prioridade,posicao=1;
    char nome[100];
    int x;
    while(1){
        printf("----------Menu de opcoes----------\n");
        printf("1-Adicionar na Fila\n");
        printf("2-Chamar o proximo da fila\n");
        printf("3-Sair\n");
        scanf("%d", &x);
        if(x==1){
            if(ptr==NULL){
                ptr=alocaelemento();
            }
            printf("Digite o nome: ");
            scanf("%s", nome);
            printf("Digite a prioridade: ");
            scanf("%d", &prioridade);
            inserirelemento(ptr, &posicao, prioridade, nome);
        }
        else if(x==2){
            if(ptr==NULL){
                printf("Codigo invalido, digite novamente\n");
                continue;
            }
            if(novazio(ptr)){
                printf("%s\n\n", ptr->nome);
                free(ptr);
                ptr=NULL;
                continue;
            }
            removerelemento(ptr, &posicao);
        }
        else if(x==3){
            destroifila(ptr, &posicao);
            return;
        }
    }
}

int main(){
    menu();
    return 0;
}
