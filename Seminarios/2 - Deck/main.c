#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

#ifdef _WIN32
#define LIMPAR "cls"
#else
#define LIMPAR "clear"
#endif

/* Menu Principal */
void menu()
{
    int opcao = -1, combustivel = 0;
    char empresa[32];

    a_deque *deque = cria_deque();

    while(opcao != 0)
    {
        system(LIMPAR);
        printf("\t\tAeroporto IFB Pow\n\t\tSistema de Pouso\n\n");
        printf("1 - Sinalizar Aproximacao\n");
        printf("2 - Fila de Prioridade para Pouso\n");
        printf("3 - Pousar\n");
        printf("4 - Alternar Destino.\n");
        printf("0 - Encerrar Expediente\n");
        printf("\nDigite uma opcao: ");
        scanf("%d", &opcao);

        while(opcao < 0 && opcao > 4)
        {
            printf("Opcao Invalida, digite novamente: ");
            scanf("%d", &opcao);
        }

        if(opcao == 1)
        {
            printf("\nEmpresa: ");
            scanf("%s", empresa);
            printf("\nCombustivel: ");
            scanf("%d", &combustivel);

            if(deque->quantidade == 0)
            {
                inserir_prioridade(deque, empresa, combustivel);
            }
            else
            {
                nave *aviao = deque->prioriodade->atual;
                if(combustivel < aviao->combustivel)
                {
                    inserir_prioridade(deque, empresa, combustivel);
                }
                else
                {
                    inserir_final(deque, empresa, combustivel);
                }
            }

            printf("\nAviao identificado com sucesso.\n");
            getchar();
            getchar();
        }
        else if(opcao == 2)
        {
            imprimir_deque(deque);
        }
        else if(opcao == 3)
        {
            if(deque->quantidade > 0) {
                printf("O Aviao \"%s\" foi pousado com sucesso.", deque->prioriodade->atual->companhia);
                getchar();
                getchar();

                remover_prioridade(deque);
            }
        }
        else if(opcao == 4)
        {
            printf("Um total de %d voos foram desviados para outro Aeroporto por Conta da Lotacao\n", alternar_destino(deque));
            getchar();
            getchar();
        }

        reduzir_combustao(deque);
    }

    apagar_deque(deque);
}

int main() {
    menu();
    return 0;
}