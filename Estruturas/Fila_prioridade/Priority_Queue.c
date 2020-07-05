
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct priority_queue{

    unsigned int max_heap_size;
    unsigned int size;
    int array

};

struct priority_queue* create_pq(unsigned int max_elements){
    
struct priority_queue* H;

if(max_elements<MIN_PQ_SIZE)
    printf("Fila de prioridade é muito pequena!\n");

    // cria espaço para fila de prioridade
    H = (struct priority_queue*) malloc (sizeof(struct priority_queue));

    if(H == NULL)
        printf("\nERRO NA ALOCAÇÃO!\n");

    // cria espaço para array
    H->array = (int*) malloc((max_elements+1)*sizeof(int));

    if(H->array == NULL)
        printf("\nERRO NA ALOCAÇÃO!\n");

    H->max_heap_size = max_elements;
    H->size = 0;
    H->elements[0] = MIN_DATA;

    return H;

}

void insert (int x, struct priority_queue* H){

unsigned int i;

if(H->size+1 == H->max_heap_size)
    printf("Fila de prioridade esta cheia!\n");
else{
    i = ++H->size;

    while(H->array[i/2]>x){

        H->array[i] = H->array[i/2];
        i/=2;
    }
    H->elements[i]=x;
}

int delete_min(struct priority_queue* H){

unsigned int i, child;
int min_element, last_element;

if(H->size == 0)
    printf("Lista de prioridade esta vazia!\n");

    min_element = H->array[1];
    last_element = H->array[H->size--];

    for(i=1;i*2<=H->size;i=child){

        child = i*2;

        if((child!=H->size) && (H->array[child+1] < H->array[child])) 
            child++;

        // percolade? 1 nivel abaixo

        if(last_element > H->array[child]){
            H->array[i] = H->array[child];
        }else{
            break;
        }
    }

    H->array[i] = last_element;

    return min_element;


}






