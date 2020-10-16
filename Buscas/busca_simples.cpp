#include <stdio.h>
#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>

#define TAM 10

using namespace std;

void imprime_vetor(int vetor[TAM])
{
    int cont;

    for (cont = 0; cont < TAM; cont++)
        cout << vetor[cont] << " - ";
    
}

int busca_simples(int vetor[TAM], int valorProcurado, int *posicaoEncontrada)
{
    int cont;

    //Verifica se o valor foi encontrado
    bool valorFoiEncontrado;

    //Percorre a lista em busca do valor
    for (cont = 0; cont < TAM; cont++)
    {
        if (vetor[cont] == valorProcurado)
        {
            valorFoiEncontrado = true;
            *posicaoEncontrada = cont;
        }
    }

    if (valorFoiEncontrado)
        return true;
    else
        return false;
}

int main()
{
    int vetor[TAM] = {1, 23, 44, 56, 63, 72, 84, 90, 98};
    int valorProcurado;
    int posicao, posicaoEncontrada;

    //Auxiliar contador
    int cont;

    imprime_vetor(vetor);

    printf("\nQual numero deseja encontrar? ");
    scanf("%d", &valorProcurado);

    if (busca_simples(vetor, valorProcurado, &posicaoEncontrada) == true)
        cout << "O valor foi encontrado na posicao: " << posicaoEncontrada;
    else
        cout << "Valor nao encontrado";

    return 0;
}
