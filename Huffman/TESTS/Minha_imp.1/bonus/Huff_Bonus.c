
// Alternative - https://rosettacode.org/wiki/Huffman_coding#C

#include <stdio.h>
#include <string.h>
 
typedef struct t_no {
	int  freq;
	char simbol;
	
	struct t_no *esq;
	struct t_no *dir;
}*no;

//=============================================================================
// VARIAVEIS GLOBAIS
struct t_no banco_dados[256] = {{0}};

no   qqq[255]; 
no   *fila = qqq - 1;

int  n_nodes = 0, fila_final = 1;
char *code[128] = {0}; 
char buffer[1024];
//============================================================================= 
no novo_no (int freq, char c, no a, no b){
	
	no n = banco_dados + n_nodes++;
	
	if (freq){
		n->simbol = c; 
		n->freq = freq;
	}
	else {
		n->esq = a, n->dir = b;
		n->freq = a->freq + b->freq;
	}
	
	return n;
}
//============================================================================= 
/* Fila de prioridade */
void insere_fila (no n){
	int j, i = fila_final++;
	while ((j = i / 2)) {
		if (fila[j]->freq <= n->freq) break;
		fila[i] = fila[j], i = j;
	}
	fila[i] = n;
}
//============================================================================= 
no remove_fila(){
	int i, l;
	no n = fila[i = 1];
 
	if (fila_final < 2) return 0;
	fila_final--;
	
	while ((l = i * 2) < fila_final) {
		if (l + 1 < fila_final && fila[l + 1]->freq < fila[l]->freq) l++;
		fila[i] = fila[l], i = l;
	}
	
	fila[i] = fila[fila_final];
	return n;
}
//=============================================================================
/* walk the tree and put 0s and 1s */
void cria_codigo(no n, char *s, int tam){
	static char *out = buffer;
	
	if (n->simbol) {

		s[tam] = 0;
		
		strcpy(out, s);

		code[n->simbol] = out;

		out += tam + 1;
		
		return;
	
	}
 
	s[tam] = '0'; 
	cria_codigo(n->esq,  s, tam + 1);

	s[tam] = '1'; 
	cria_codigo(n->dir,  s, tam + 1);
}
//============================================================================= 
void inicializa(char *string){
	
	int i, freq[128] = {0};
	char simbolo[16];
 
	while (*string) freq[(int)*string++]++;
 
	for (i = 0; i < 128; i++)
		if (freq[i]) insere_fila (novo_no(freq[i], i, 0, 0));
 
	/* Completa o heap juntando os nos, começando das menores frequencias 
	   Feito por passos:
	   (1) Remove os 2 nos da fila que tem a maior prioridade (menor frequencia)
	   (2) Faz um no com os dois nois removidos contendo a soma das 2 frequencias
	   (3) Quando feito o no, ele guarda os dois nos removidos da fila como esq/dir
	   (4) Continua juntando de 2 em 2 os nos ate sobrar apenas 1 na fila de prioridade
	*/

	while (fila_final > 2) 
		insere_fila (novo_no(0, 0, remove_fila(), remove_fila()) );

	/* (1) Traversa a arvore construida da raiz para as folhas 
	   (2) Define e concatena '0' para no->esq e '1' para no->dir de cada no percorrido. 
	   (3) Os '0' e '1' a cada galho percorrido definem o código Huffman gerado
	*/

	cria_codigo(fila[1], simbolo, 0);
}
//============================================================================= 
void codifica(char *str, char *saida){
	while (*str) {
		strcpy (saida, code[*str]);
		saida += strlen (code[*str++]);
	}
}
//=============================================================================
//============================================================================= 
int  main () {
	
	int i;
	
	char *str = "Huffman";
    char buffer[1024]; // guarda a string buffer 
 
	inicializa (str);
	printf("==================================\n");
	printf(" Simbolo | Codigo  |  \n");
	printf("==================================\n");

	for (i = 0; i < 128; i++){
		// imprime os simbolos e seus codigos
		if ( code[i] ) 
			printf("  '%c'       %s      \n", i, code[i]);
	
	}

	codifica (str, buffer);
	printf("==================================\n");
	printf("Codificado: %s \n", buffer);
 

	return 0;
}
//=============================================================================