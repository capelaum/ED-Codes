
// Funcionamento de uma arvore 

#include "arvore.h"

//=======================================================
// Menor Valor 
int Menor_Valor (t_no* raiz) {
	t_no* atual = raiz;
	
	// loop ate encontrar no mais a esquerda
	while (atual->esq != NULL) {
		atual = atual->esq;
	}
	return (atual->dado);
}

// Maior Valor 
int Maior_Valor (t_no* raiz) {
	t_no* atual = raiz;
	
	// loop ate encontrar no mais a direita
	while (atual->dir != NULL) {
		atual = atual->dir;
	}
	
	return (atual->dado);
}
//=======================================================
// Profundidade maxima da arvore (nivel)
int Max_Profundidade (t_no* raiz) {

	if (raiz==NULL) 
		return false;
	
	else {
		
		// computa profundidade de cada subarvore
		
		int esq_Prof = Max_Profundidade (raiz->esq);
		int dir_Prof = Max_Profundidade (raiz->dir);
	
	// usa a maior
	if (esq_Prof > dir_Prof) 
		return (esq_Prof+1);
	else 
		return (dir_Prof+1);
	
	}
	
}
//=======================================================
// Retorna quantidade de nos em uma arvore
int qtd (t_no* raiz) {

	if (raiz == NULL) 
		return false;

	else 
		return ( qtd (raiz->esq) + 1 + qtd (raiz->dir) );
	
}
//=======================================================
// soma do caminho de uma arvore
int Soma_caminho(t_no* raiz, int soma) {
	// return true if we run out of tree and sum==0

	if (raiz == NULL)
		return (soma == 0);
	else {
		
		// otherwise check both subtrees
		int subSoma = soma - raiz->dado;
		
		return (Soma_caminho (raiz->esq, subSoma) || 
				Soma_caminho(raiz->dir, subSoma));
	
	}
}
//=======================================================
// Printa todos caminhos possiveis de uma arvore
void printPaths (t_no* raiz) {
	int path[1000];
	printPathsRecur(raiz, path, 0);
}
//=======================================================
/*
Recursive helper function -- given a node, and an array containing
the path from the root node up to but not including this node,
print out all the root-leaf paths.
*/
void printPathsRecur (t_no* raiz, int path[], int pathLen) {
	if (raiz==NULL) 
		return;
		
	// append this node to the path array
	path[pathLen] = raiz->dado;
	pathLen++;
	
	// it's a leaf, so print the path that led to here
	if (raiz->esq == NULL && raiz->dir == NULL) {
		imprime_array (path, pathLen);
	}
	else {
		// otherwise try both subtrees
		printPathsRecur (raiz->esq, path, pathLen);
		printPathsRecur (raiz->dir, path, pathLen);
	}
}
//=======================================================
// Utility that prints out an array on a line.
void imprime_array (int ints[], int len) {
	
	int i;
	
	for (i=0; i<len; i++) 
		printf("%d ", ints[i]);
	
	printf("\n");
}
//=======================================================
// Para os valore de 1 a numKeys, quantas arvores bst unicas
// possiveis existem para armazenar esses dados?

int countTrees (int numKeys) { 

	if (numKeys <=1) {    
		return(1);  
	}else{   
		
		// there will be one value at the root, with whatever remains    
		// on the left and right each forming their own subtrees.   
		// Iterate through all the values that could be the root...  

		int sum = 0;    
		int left, right, root;    
		
		for (root=1; root<=numKeys; root++) {     
			left  = countTrees(root - 1);    
			right = countTrees(numKeys - root);      
			
			// number of possible trees with this root == left*right;      
			sum += left*right;    
		}    

		return(sum);  

	}

}
//=======================================================
/* Returns true if a binary tree is a binary search tree.*/
int isBST (t_no* raiz) {  
	
	if (raiz == NULL) return true;  
	
	// false if the min of the left is > than us  
	if (raiz->esq!=NULL && Menor_Valor (raiz->esq) > raiz->dado)    
		return false;  
	
	// false if the max of the right is <= than us  
	if (raiz->dir!=NULL && Maior_Valor (raiz->dir) <= raiz->dado)    
		return false;  // false if, recursively, the left or right is not a BST  
	
	if (!isBST(raiz->esq) || !isBST(raiz->dir))    
		return false;  // passing all that, it's a BST  
	
	return true;
}



