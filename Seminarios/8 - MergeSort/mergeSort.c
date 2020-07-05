/*
 * Universidade de Brasília
 * Estruturas de Dados - Prof. Dr. Marcos Caetano
 * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * 05/06/2018
 * Matheus Ferreira Resende, 17/0019101
 * Pedro Vitor Valença Mizuno, 17/0043665
 * João José Rocha de Sousa, 11/0032225
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Ordenação por Intercalação
 * Recursivo - dividir para conquistar
 * Divide, recursivamente, o array em duas partes, até que cada psoição dele seja considerada um array de um único elemento
 * Combina dois arrays para obter um array maior e ordenado. -> intercalando os elementos e ordenando
 * O processo se repete até existir apenas um array
 *
 */

//Protótipos das funções: : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : :
//Função merge:
void merge(int *vet, int inicio, int meio, int fim);

//Função mergeSort:
void mergeSort(int *vet, int inicio, int fim);

//Função "sleep":
void sleep();

//Implementando as funções: : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : :
//FUNÇÃO DE ORDENAÇÃO - MERGE-SORT:
void mergeSort(int *vet, int inicio, int fim)
{
	int meio;

	if (inicio < fim)
	{
		meio = floor((inicio + fim)/2);
		mergeSort(vet, inicio, meio);  //primeira metade
		mergeSort(vet, meio + 1, fim);  //segunda metade
		merge(vet, inicio, meio, fim);  //depois intercala ordenando
	}
}

//FUNÇÃO DE INTERCALAÇÃO - MERGE:
void merge(int *vet, int inicio, int meio, int fim)
{
	int p1 = inicio, p2 = meio + 1;  //marca o inicio das partes
	int tam = fim - inicio + 1;  //tamanho do vetor total
	int fim1 = 0, fim2 = 0;  //booleanas

	int *temp = (int*) malloc(tam * sizeof(int));  //aloca um vetor auxiliar

	if (temp != NULL)  //se a alocação não der errado
	{
		for (int i = 0; i < tam; i++)
		{
			if (!fim1 && !fim2)  //se fim1 = 0 e fim2 = 0
			{
				if (vet[p1] < vet[p2])  //compara os elementos
					temp[i] = vet[p1++];  //armazena no vetor auxiliar e avança p1
				else
					temp[i] = vet[p2++];  //idem e avança p2

				if (p1 > meio)  //se chegar ao final
					fim1 = 1;  //marca fim = 1 para nao executar mais
				if (p2 > fim)
					fim2 = 1;
			}
			else
			{
				if (!fim1)  //caso sobre elemento
					temp[i] = vet[p1++];
				else
					temp[i] = vet[p2++];
			}
		}

		for (int j = 0, k = inicio; j < tam; j++, k++)
			vet[k] = temp[j];  //copia para o vetor original
	}

	free(temp);  //libera o auxiliar
}

//FUNÇÃO SYSTEM PAUSE:
void sleep()
{
	setbuf(stdin, NULL);
	printf("\nPress \"Enter\" to quit the program...");
	char exit = getchar();
}

//MAIN PROGRAM:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

int main()
{
	int tam;

	printf("Entre com o tamanho do vetor: ");
	scanf("%d", &tam);

	int *vet = (int*) malloc(tam * sizeof(int));

	int fim = tam - 1, inicio = 0;

	printf("\nEntre com os valores do vetor: ");

	for (int i = 0; i < tam; i++)
		scanf("%d", &vet[i]);

	mergeSort(vet, inicio, fim);

	printf("\nResultado:\n");

	for (int i = 0; i < tam; i++)
		printf("%d\t", vet[i]);
	printf("\n");

	free(vet);

	sleep();
	return 0;
}