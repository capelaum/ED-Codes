#include "tabelahash.c"

int main(){

	tabela 	tab[10];
	IniciaTabela(tab);
	printf("\n");
	ImprimeTabela(tab);
	char nome[30], linha[1024];
	int matricula;
	float n1, n2, n3;
	FILE *ptr_arquivo = fopen("alunos.txt","r");


	if (ptr_arquivo == NULL) {
    	printf("ERRO! O arquivo não foi aberto!\n");
	} else {
		while(fgets(linha, sizeof(linha), ptr_arquivo) != NULL){
			fscanf(ptr_arquivo, "%d %s %f %f %f", &matricula, nome, &n1, &n2, &n3);
			CriaAluno(nome, matricula, n1, n2, n3, tab);
		}
	}

	/*
	COMO A FUÇÃO DE LEITURA DE ARQUIVO FUNCIONA:
		char * fgets (char * string, int tamanho, FILE * fluxo);
		string - Cadeia de caracteres a ser lida.
		tamanho - Número máximo de caracteres a serem lidos na cadeia de caracteres string.
		fluxo - Ponteiro para um objeto FILE que será utilizado como entrada. Para ler da entrada padrão, utilizar stdin.

	*/


	printf("\n");
	ImprimeTabela(tab);
	printf("\n");
	elemento *elem = BuscaElemento(tab, 102);

	if(elem == NULL)
		printf("Elemento nao encontrado!\n\n");
	else
		printf("Elemento %s encontrado!\n\n", elem->aluno->nome);

	RemoveElemento(tab, 102);
	printf("\n");
	ImprimeTabela(tab);
	DestroiTabela(tab);

	return 0;
}


