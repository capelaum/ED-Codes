#ifndef HEAPS_H
#define HEAPS_H

typedef struct{
    int *vet;
    int tam;
    int tamMax;
} t_heaps;

t_heaps *heaps_S_init(int n, int m, int *vet);

void heaps_S_inserir(t_heaps* heap, int n);

int heaps_S_apaga(t_heaps* heaps);

void heaps_S_imprime(t_heaps* heap);

void heaps_S_destroi(t_heaps* heaps);


#endif