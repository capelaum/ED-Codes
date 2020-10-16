#include <stdio.h>
#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>
#define TAM 10

using namespace std; //para utilizar cout

void imprime_vetor(int vetor[TAM])
{
    int cont;

    for (cont = 0; cont < TAM; cont++)
    {
        cout << vetor[cont] << " - ";
    }
}

int busca_simples(int vetor[TAM], int valorProcurado, int *posicaoEncontrada)
{
    int cont;
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
        return 1;
    else
        return -1;
    
}

int busca_binaria(int vetor[TAM], int valorProcurado, int *posicaoEncontrada)
{
    int esquerda = 0;      
    int direita = TAM - 1; 
    int meio;              

    while (esquerda <= direita)
    {
        //Encontra o meio da analise
        meio = (esquerda + direita) / 2;

        cout << "meio: " << vetor[meio] << " | posicao: " << meio << "\n";
        cout << "esquerda: " << esquerda << "\n";
        cout << "direita: " << direita << "\n";
        cout << "-------------\n";

        //Quando o valor do meio � encontrado
        if (valorProcurado == vetor[meio])
        {
            *posicaoEncontrada = meio;
            return 1;
        }

        // Ajustando os limites laterais
        if (vetor[meio] < valorProcurado)
            esquerda = meio + 1;
        else
            direita = meio - 1;
        
    }

    return -1;
}

int main()
{

    int vetor[TAM] = {1, 23, 44, 56, 63, 72, 84, 90, 98};
    int valorProcurado, posicaoEncontrada;
    
    
    imprime_vetor(vetor);
    
    printf("\nQual numero deseja encontrar? ");
    //scanf("%d", &valorProcurado);

    valorProcurado = 98;

    if (busca_binaria(vetor, valorProcurado, &posicaoEncontrada) == 1)
        cout << "O valor foi encontrado na posicao: " << posicaoEncontrada;
    else
        cout << "Valor nao encontrado";

    return 0;
}
