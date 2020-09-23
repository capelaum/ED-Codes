#ifndef ED_LISTA_H
#define ED_LISTA_H


#define TRUE 1
#define FALSE 0
//===================================================================================================
//Structs

typedef struct dado{
	int num;
}t_dado;

typedef struct elemento{
	t_dado* dado;
	
	struct elemento* anterior;
	struct elemento* proximo;
}t_elemento;

typedef struct{
	t_elemento* primeiro;
	t_elemento* ultimo;
	
	int qtd;
}t_lista;
//===================================================================================================
//Functions

t_elemento* aloca_elemento  (int num);

void        remove_elemento (t_elemento* elemento);

int         remove_dado     (int num, t_lista* lista);
int         remove_inicio   (t_lista* lista);
int         remove_final    (t_lista* lista);
int         remove_pos      (int pos, t_lista* lista);

t_lista*    aloca_lista     ();
void        apaga_lista     (t_lista* lista);
int         esta_vazia      (t_lista* lista);
void        imprime_lista   (t_lista* lista);


int         inserir_final   (int num, t_lista* lista);

//===================================================================================================
#endif //ED_LISTA_H
