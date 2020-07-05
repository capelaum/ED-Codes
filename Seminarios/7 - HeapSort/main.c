#include "heap.h"
#include <stdlib.h>      //Necessary for "srand" and "rand" functions.
#include <stdio.h>
#include <time.h>       //Necessary for "time" functions.

int main(){
  int qtd;

  srand(time(NULL));

  printf("Insira o tamanho da Arvore.\n");
  scanf("%d", &qtd);
  setbuf(stdin, NULL);
  
  int aux;
  int input[qtd];
  for (int i=0; i<qtd; i++) {
    aux = -100 + (rand() % 201);
    input[i] = aux;
  }
  
  Heap *heap = init_heap(qtd);        //Initialize the heap structure.
  
  max_heap_int(heap, input, qtd);      //Contruct the heap.

  print_heap_int(heap);

  HeapSort_int(heap);
  printf("#############\n");
  print_heap_int(heap);

  free_heap(heap);

  return 0;
}
