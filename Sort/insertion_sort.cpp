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
    {
        cout << vetor[i] << " ";
    }
    
}

void insertion_sort(int vetor[TAM])
{

    int i, j, atual;

    for (i = 1; i < TAM; i++)
    {
        atual = vetor[i];
        j = i - 1;

        // Analisando membros anteriores
        while ((j >= 0) && (atual < vetor[j]))
        {
            // Posiciona os elementos uma posicao para frente
            vetor[j + 1] = vetor[j];
            j--;
        }

        // Agora que o espaco foi aberto, colocamos o atual (Menor numero) na posicao correta
        vetor[j + 1] = atual;
        
        imprimeVetor(vetor);
    }
}

int main()
{

    int vetor[TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    insertion_sort(vetor);
    imprimeVetor(vetor);

    return 0;
}
