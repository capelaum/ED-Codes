#ifndef TABELAHASH_H
#define TABELAHASH_H

//------------------------->Tipo aluno
typedef struct t_aluno{ 
	char nome[30];
	int matricula;
	float n1, n2, n3;
} aluno;

//------------------------->Tipo elemento
typedef struct elem{
	aluno *aluno;
	struct elem *proximo;
	struct elem *anterior;
} elemento;

//------------------------->Tipo tabela
typedef struct{
	elemento *primeiro;
	int quantidade;
} tabela;


void IniciaTabela(tabela *tabela);
int CriaAluno(char *nome, int matricula, float n1, float n2, float n3, tabela *ptr);
int InsereAluno(tabela *tab, elemento *elem);
void DestroiTabela(tabela *tabela);
void ImprimeTabela(tabela *tabela);
elemento* BuscaElemento(tabela *tab, int matricula);
void RemoveElemento(tabela *tab, int matricula);

#endif
