#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10

using namespace std;

void imprime_vetor(int vetor[TAM], int topo)
{
    int cont;
    
    for (cont = 0; cont < TAM; cont++)
        cout << vetor[cont] << " - ";

    cout << "Topo: " << topo << "\n";
}

bool pilha_vazia(int topo)
{
    if (topo == -1)
        return true;
    else
        return false;
}

bool pilha_cheia(int topo)
{
    if (topo == TAM - 1)
        return true;
    else
        return false;
}

int pilha_tamanho(int topo)
{
    return topo + 1;
}

int pilha_get(int pilha[TAM], int *topo)
{
    if (pilha_vazia(*topo)){
        cout << "A pilha esta vazia" << "\n";
        return 0;
    }
    else
        return pilha[*topo];
}

void pilha_push(int pilha[TAM], int valor, int *topo)
{
    //Caso n�o possa colocar mais valores
    if (pilha_cheia(*topo))
        cout << "Pilha cheia!" << "\n";
    else
    {
        *topo = *topo + 1;
        pilha[*topo] = valor;
    }
}

void pilha_pop(int pilha[TAM], int *topo)
{
    if (pilha_vazia(*topo))
        cout << "A Pilha ja esta vazia" << "\n";
    else
    {
        cout << "Valor Removido: " << pilha[*topo] << "\n";
        pilha[*topo] = 0;
        *topo = *topo - 1;
    }
}

void pilha_construtor(int pilha[TAM], int *topo)
{
    int i;

    //Coloca o topo negativo para indicar uma pilha vazia
    *topo = -1;
    
    for (i = 0; i < TAM; i++)
        pilha[i] = 0;
}

int main()
{

    int pilha[TAM], topo; 

    pilha_construtor(pilha, &topo);

    cout << "Tamanho da pilha: " << pilha_tamanho(topo) << "\n";

    if(pilha_vazia(topo)){
        cout << "Pilha esta vazia \n";
    }

    imprime_vetor(pilha, topo);

    pilha_push(pilha, 5, &topo);
    imprime_vetor(pilha, topo);

    cout << "Ultimo valor da pilha: " << pilha_get(pilha, &topo) << "\n";
    cout << "Tamanho da Pilha: " << pilha_tamanho(topo) << "\n";

    pilha_push(pilha, 1, &topo);
    pilha_push(pilha, 2, &topo);
    pilha_push(pilha, 3, &topo);
    pilha_push(pilha, 4, &topo);
    pilha_push(pilha, 5, &topo);
    pilha_push(pilha, 6, &topo);
    pilha_push(pilha, 7, &topo);
    pilha_push(pilha, 8, &topo);
    pilha_push(pilha, 9, &topo);

    imprime_vetor(pilha, topo);

    if(pilha_cheia(topo)){
        cout << "Pilha esta cheia \n";
    }

    pilha_pop(pilha, &topo);

    if(pilha_cheia(topo)){
        cout << "Pilha esta cheia \n";
    }

    imprime_vetor(pilha, topo);

    cout << "Tamanho da pilha: " << pilha_tamanho(topo) << "\n";
}
