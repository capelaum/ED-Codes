#ifndef HEAD_H
#define HEAD_H

#define TRUE 1
#define FALSE 0
//===========================================================================
typedef struct no{
	int dado;
	
	struct no* proximo;
}t_no;

typedef struct {
	t_no* primeiro;
	t_no* ultimo;
	
	int qtd;
}t_lista;
//===========================================================================
t_lista* aloca_lista      ();
t_no*    aloca_no         (int dado);

int      inserir_final    (int dado, t_lista* lista);
int      inserir_inicio   (int dado, t_lista* lista);
int      inserir_pos      (int pos, int dado, t_lista* lista); 
int      inserir_ordenado (int dado, t_lista* lista);

void     imprime_lista    (t_lista* lista);
void     apaga_lista      (t_lista* lista);
int      esta_vazia       (t_lista* lista);

int      remove_primeiro  (t_lista* lista);
int      remove_ultimo    (t_lista* lista);
int      remove_pos       (int pos, t_lista* lista);

int      procura_valor    (int dado, t_lista* lista);
#endif
