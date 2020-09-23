#ifndef HEAD_H
#define HEAD_H

#define TRUE 1
#define FALSE 0 

//==================================================
typedef struct dado{
	int num;
}t_dado;

typedef struct elemento{
	t_dado* dado;
	
	struct elemento* prox;
	struct elemento* ant;
}t_elemento;

typedef struct {
	t_elemento* primeiro;
	t_elemento* ultimo;
	
	int qtd;
}t_lista;
//==================================================

t_lista*    aloca_lista      ();
t_elemento* aloca_elemento   (int num);

void imprime (t_lista *lista);
void        imprime_lista    (t_lista* lista);
int         esta_vazia       (t_lista* lista);

int         inserir_final    (int num, t_lista* lista);
int         inserir_ordenado (int num, t_lista* lista);
int         procura_maior    (t_lista* lista);

//==================================================
#endif
