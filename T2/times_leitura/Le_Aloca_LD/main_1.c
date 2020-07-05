

#include "LD_Header.h"

int main (){



    printf("[1] Iniciar Copa \n");
    printf("[2] Sair \n");

    t_lista* lista = cria_lista_times ();

   
    printf("==============================\n");
    imprime_lista (lista);
    printf("==============================\n");
    imprime_lista_times (lista);


    int x;
    printf("\nTIME--> ");
    scanf(" %d", &x);


/*
    switch (x){

        case 1:
            printf("Time 1:\n");
            printf("Ataque: %d Defesa: %d Resistencia: %d Velocidade: %d");

        case 2:
            printf("Time 2:\n");
            printf("Ataque: %d Defesa: %d Resistencia: %d Velocidade: %d");

        case 3:
            printf("Time 3:\n");
            printf("Ataque: %d Defesa: %d Resistencia: %d Velocidade: %d");

        case 4:
            printf("Time 4:\n");
            printf("Ataque: %d Defesa: %d Resistencia: %d Velocidade: %d");

        case 5:
            printf("Time 5:\n");
            printf("Ataque: %d Defesa: %d Resistencia: %d Velocidade: %d");

        case 6:
            printf("Time 6:\n");
            printf("Ataque: %d Defesa: %d Resistencia: %d Velocidade: %d");

        case 7:
            printf("Time 7:\n");
            printf("Ataque: %d Defesa: %d Resistencia: %d Velocidade: %d");

        case 8:
            printf("Time 8:\n");
            printf("Ataque: %d Defesa: %d Resistencia: %d Velocidade: %d");

        case 9: 
            printf("Time 9:\n");
            printf("Ataque: %d Defesa: %d Resistencia: %d Velocidade: %d");

        case 10:
            printf("Time 10:\n");
            printf("Ataque: %d Defesa: %d Resistencia: %d Velocidade: %d");

        case 11:
            printf("Time 11:\n");
            printf("Ataque: %d Defesa: %d Resistencia: %d Velocidade: %d");

        case 12:
            printf("Time 12:\n");
            printf("Ataque: %d Defesa: %d Resistencia: %d Velocidade: %d");

        case 13:
            printf("Time 13:\n");
            printf("Ataque: %d Defesa: %d Resistencia: %d Velocidade: %d");

        case 14:
            printf("Time 14:\n");
            printf("Ataque: %d Defesa: %d Resistencia: %d Velocidade: %d");

        case 15:
            printf("Time 15:\n");
            printf("Ataque: %d Defesa: %d Resistencia: %d Velocidade: %d");

        case 16:
            printf("Time 16:\n");
            printf("Ataque: %d Defesa: %d Resistencia: %d Velocidade: %d");

        default:
            printf("Escolha inválida\n");
            return;

    }
*/

    return 0;
}