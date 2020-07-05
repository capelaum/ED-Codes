#include "heaps.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, num, sair;
    t_heaps *heaps;
    int vet[10];
    char res;

    printf("Digite um número de elementos de sua fila de prioridade, maximo 10: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    
    heaps = heaps_S_init(n, 1000, vet);
    printf("\nHeaps por largura:\n");
    heaps_S_imprime(heaps);
    printf("\n");

    sair = 0;
    while(!sair){
        printf("1 - inserir\n");
        printf("2 - apagar\n");
        printf("3 - destruir\n");
        scanf(" %c", &res);
        printf("\n");
        switch(res){
            case '1':
                printf("Digite um numero: ");
                scanf("%d", &num);
                heaps_S_inserir(heaps, num);
                printf("\nHeaps por largura:\n");
                heaps_S_imprime(heaps);
                printf("\n");
            break;
            case '2':
                printf("Elemento removido eh %d\n", heaps_S_apaga(heaps));
                printf("\nHeaps por largura:\n");
                heaps_S_imprime(heaps);
                printf("\n");
            break;
            case '3':
                heaps_S_destroi(heaps);
                printf("Heaps destruida\n");
                sair = 1;
            break;
        }
    }
    
    return 0;
}