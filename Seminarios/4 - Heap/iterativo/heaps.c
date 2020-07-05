#include "heaps.h"
#include <stdlib.h>
#include <stdio.h>

void troca(int* a, int* b){
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

void heaps_S_corrigi_cima(t_heaps* heaps, int filho){
    int pai = (filho - 1)/2;
    while( filho > 0 && (heaps->vet[filho] > heaps->vet[pai])) {
        troca( &heaps->vet[filho], &heaps->vet[pai]);
        filho = pai;
        pai = (pai - 1)/2;
    }
}

void heaps_S_corrigi_baixo(t_heaps* heaps, int n){
    int filho1, filho2, pai;

    pai = n;
    filho1 = pai * 2 + 1;
    filho2 = pai * 2 + 2;

    
    while((pai < heaps->tam && (filho1 < heaps->tam || filho2 < heaps->tam))&&(heaps->vet[pai] < heaps->vet[filho1] || heaps->vet[pai] < heaps->vet[filho2])) {
        
        if(filho1 < heaps->tam && filho2 < heaps->tam){
            if(filho1 < heaps->tam && heaps->vet[filho1] >= heaps->vet[filho2]){
                troca(&heaps->vet[pai], &heaps->vet[filho1]);
                pai = filho1;
                filho1 = pai * 2 + 1;
                filho2 = pai * 2 + 2;
            } else if(filho2 < heaps->tam && heaps->vet[filho2] >= heaps->vet[filho1]){
                troca(&heaps->vet[pai], &heaps->vet[filho2]);
                pai = filho2;
                filho1 = pai * 2 + 1;
                filho2 = pai * 2 + 2;
            }
        } else{
            if(filho2 < heaps->tam){
                troca(&heaps->vet[pai], &heaps->vet[filho2]);
                pai = filho2;
                filho1 = pai * 2 + 1;
                filho2 = pai * 2 + 2;
            }else if(filho1 < heaps->tam){
                troca(&heaps->vet[pai], &heaps->vet[filho1]);
                pai = filho1;
                filho1 = pai * 2 + 1;
                filho2 = pai * 2 + 2;
            }
        }
    }
}

void heaps_S_nao_heaps(t_heaps *heaps){
    for(int i = (heaps->tam-1)/2; i >= 0; i--){
        heaps_S_corrigi_baixo(heaps, i);
    }
}

t_heaps *heaps_S_init(int n, int m, int *vet){
    t_heaps *retorno;

    retorno = (t_heaps*)malloc(sizeof(t_heaps));

    if(vet == NULL){
        if(retorno != NULL){
            retorno->tam = 0;
            retorno->tamMax = n;
            retorno->vet = (int*)calloc(n+m, sizeof(int));

            if(retorno->vet == NULL){
                free(retorno);
                retorno = NULL;
            }
        }       
    } else{
        if(retorno != NULL){
            retorno->tam = n;
            retorno->tamMax = n+m;
            retorno->vet = (int*)calloc(n+m, sizeof(int));
            for(int i = 0; i < n; i++){
                retorno->vet[i] = vet[i];
            }
            heaps_S_nao_heaps(retorno);
        }
    }
    return retorno;
}


void heaps_S_inserir(t_heaps *heaps, int n){
    if(heaps->tam == 0){
        heaps->vet[0] = n;
        heaps->tam++;
    } else if(heaps->tam <= heaps->tamMax){
        heaps->vet[heaps->tam] = n;
        heaps->tam++;
        if(heaps->vet[heaps->tam-1] > heaps->vet[(heaps->tam-1)/2]){
            heaps_S_corrigi_cima(heaps,heaps->tam-1);
        }   
    }  
}

int heaps_S_apaga(t_heaps* heaps){
    int retorno = heaps->vet[0];

    heaps->tam--;
    heaps->vet[0] = heaps->vet[heaps->tam];

    heaps_S_corrigi_baixo(heaps, 0);

    return retorno;
}

void heaps_S_imprime(t_heaps* heaps){
    for(int i = 0; i < heaps->tam; i++){
        /*printf("Valor do nó %d :%d\n", i+1, heaps->vet[i] );*/
        printf("%d ", heaps->vet[i] );
    }
    printf("\n");
}

void heaps_S_destroi(t_heaps* heaps){
    free(heaps->vet);
    free(heaps);
}


 


