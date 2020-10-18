#include <iostream>
#include <stdlib.h>
#include <string>

#define TAM 10

using namespace std;

void imprimeVetor(int vetor[])
{
    int i;
    cout << "\n";
    for (i = 0; i < TAM; i++)
        cout << " |" << vetor[i] << "| ";
}

void selection_sort(int vetor[TAM])
{
    int indiceMenorValor, aux, i, j;

    for (i = 0; i < TAM; i++)
    {
        imprimeVetor(vetor);
        // Recebe a posicao inicial para o menor valor
        indiceMenorValor = i;
        // Analisa os elementos na frente
        for (j = i + 1; j < TAM; j++)
        {
            // Caso encontre um valor menor na frente dos analisados
            if (vetor[j] < vetor[indiceMenorValor])
                indiceMenorValor = j;
        }
        // Verifica se houve mudanca e troca os valores
        if (indiceMenorValor != i)
        {
            aux = vetor[i];
            vetor[i] = vetor[indiceMenorValor];
            vetor[indiceMenorValor] = aux;
        }
    }
}

int main()
{
    int vetor[TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    selection_sort(vetor);
    imprimeVetor(vetor);
    return 0;
}
