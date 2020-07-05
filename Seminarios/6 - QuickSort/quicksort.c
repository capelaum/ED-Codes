/*
SEMINÁRIO DE ESTRUTURA DE DADOS

GRUPO: 6 (Algoritmo QuickSort)
ALUNA: Carolina Soares Lôbo
MATRÍCULA: 17/0139131
TURMA: A
DATA: 12/06/2018
 */

#include <stdio.h>
#include <stdlib.h>

/* Assinatura da função que contém o algoritmo QuickSort */
void quicksort(int* array, int pos_inicial, int pos_final);

int main()
{
	int n, i;
	int* array;

	/* Solicita o tamanho do array a ser ordenado e escanea o valor desse tamanho */
	printf("Digite o tamanho do array a ser ordenado: ");
	scanf("%d", &n);

	/* Aloca dinamicamente memória para o tamanho array que será inserido pelo usuário */
	array = (int*)malloc(n*sizeof(int));

	/* Solicita o array que será ordenado e o escanea */
	printf("\nDigite o array a ser ordenado:\n");
	for(i=0; i<n; i++)
	{
		scanf("%d", &array[i]);
	}

	/* Chama a função com o algoritmo QuickSort para ordenar o array */
	quicksort(array, 0, n-1);

	/* Imprime o array já ordenado */
	printf("\nArray ordenado:\n");
	for(i=0; i<n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	/* Libera a memória alocada para o array */
	free(array);

	return 0;
}

void quicksort(int* array, int pos_inicial, int pos_final)
{
	int p = pos_inicial;
	int r = pos_final;
	int pivo, aux;

	/* Iguala o pivô ao último elemento do array */
	pivo = array[pos_final];

	/* Enquanto o valor de p for menor que o de r, executar todas as operações 
	abaixo repetidamente */
	while(p < r)
	{
		/* Enquanto o valor na posição p do array for menor que o pivô,
		 continuar incrementando o valor de p */
		while(array[p] < pivo)
		{
			p++;
		}

		/* Enquanto o valor na posição r do array for maior que o pivô,
		 continuar decrementando o valor de r */
		while(array[r] > pivo)
		{
			r--;
		}

		/* Se depois de todas as incrementações em p e as decrementações em r,
		o índice p for menor ou igual a r, trocar o valor na posição p do array 
		de lugar com o valor na posição r do array. Em seguida, incrementar p e 
		decrementar r */
		if(p <= r)
		{
			aux = array[p];
			array[p] = array[r];
			array[r] = aux;
			p++;
			r--;
		}
	}

	/* Se depois de todas as operações feitas, o índice r ainda for maior que a posição
	inicial do array, chamar recursivamente a função QuickSort de novo, passando como 
	parâmetro de início a posição inicial e como parâmetro de fim o índice r */
	if(r > pos_inicial)
	{
		quicksort(array, pos_inicial, r);
	}

	/* Se depois de todas as operações feitas, o índice p ainda for maior que a posição
	final do array, chamar recursivamente a função QuickSort de novo, passando como 
	parâmetro de início o índice p e como parâmetro de fim a posição inicial */
	if(p < pos_final)
	{
		quicksort(array, p, pos_final);
	}
}