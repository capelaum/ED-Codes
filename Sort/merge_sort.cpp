#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#define TAM 10

using namespace std;

void imprimeVetor(int vetor[])
{
    int i;
    cout << "\n";
    for (i = 0; i < TAM; i++)
        cout << " |" << vetor[i] << "| ";
}

// Junta os 2 sub arrays criados
void merge(int vetor[], int inicio, int meio, int fim)
{
    int inicio1 = inicio, 
        inicio2 = meio + 1, 
        inicioAux = 0, 
        tam = fim - inicio + 1;

    int *vetAux;
    vetAux = (int*) malloc(tam * sizeof(int));

    while (inicio1 <= meio && inicio2 <= fim)
    {
        if (vetor[inicio1] < vetor[inicio2])
        {
            vetAux[inicioAux] = vetor[inicio1];
            inicio1++;
        }
        else
        {
            vetAux[inicioAux] = vetor[inicio2];
            inicio2++;
        }
        inicioAux++;
    }

    //Caso ainda haja elementos na primeira metade
    while (inicio1 <= meio)
    { 
        vetAux[inicioAux] = vetor[inicio1];
        inicioAux++;
        inicio1++;
    }

    //Caso ainda haja elementos na segunda metade
    while (inicio2 <= fim)
    { 
        vetAux[inicioAux] = vetor[inicio2];
        inicioAux++;
        inicio2++;
    }

    //Move os elementos de volta para o vetor original
    for (inicioAux = inicio; inicioAux <= fim; inicioAux++)
        vetor[inicioAux] = vetAux[inicioAux - inicio];

    free(vetAux);
}

void mergeSort(int vetor[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (fim + inicio) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

int main()
{
    int vetor[TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    imprimeVetor(vetor);

    // int vetorSize = sizeof(vetor) / sizeof(vetor[0]);
    mergeSort(vetor, 0, TAM - 1);

    imprimeVetor(vetor);

    return 0;
}
