#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "deque.h"

#ifdef _WIN32
#define LIMPAR "cls"
#else
#define LIMPAR "clear"
#endif

a_elemento *criar_elemento(char *companhia, int combustivel)
{
    // Alocando Elemento
    a_elemento *ptr = (a_elemento*) malloc(sizeof(a_elemento));

    // Verificando se foi corretamente alocado
    if(ptr == NULL)
    {
        printf("ERRO DE ALOCACAO DINAMICA DE MEMORIA\n");
        exit(-1);
    }

    // Alocando Caracteristicas do Elemento
    ptr->atual = (nave*) malloc(sizeof(nave));

    // Verificando se foi corretamente alocado
    if(ptr->atual == NULL)
    {
        printf("ERRO DE ALOCACAO DINAMICA DE MEMORIA\n");
        exit(-1);
    }

    // Atribuindo valores ao elemento
    ptr->atual->companhia = (char*) malloc(sizeof(char) * (strlen(companhia)+1));
    strcpy(ptr->atual->companhia, companhia);
    ptr->atual->combustivel = combustivel;
    ptr->atual->desviado = 0;
    ptr->anterior = NULL;
    ptr->proximo = NULL;

    // Retornando endereco do elemento alocado
    return ptr;
}

void apagar_elemento(a_elemento *elemento)
{
    if(elemento != NULL)
    {
        // Apagando do Mais interno para o mais externo
        free(elemento->atual->companhia);
        free(elemento->atual);
        free(elemento);
    }
}

a_deque *cria_deque()
{
    a_deque *deque = (a_deque*) malloc(sizeof(a_deque));

    //Verificando se foi corretamente
    if(deque == NULL)
    {
        printf("ERRO DE ALOCACAO DINAMICA DE MEMORIA\n");
        exit(-1);
    }

    //Atribuindo valores ao deque
    deque->prioriodade = NULL;
    deque->final = NULL;
    deque->quantidade = 0;

    return deque;
}

void inserir_prioridade(a_deque *deque, char *companhia, int combustivel)
{
    //Criando elemento
    a_elemento *aviao = criar_elemento(companhia, combustivel);

    if(deque->quantidade == 0)
    {
        deque->prioriodade = aviao;
        deque->final = aviao;
    }

    else {
        a_elemento *aviao2 = deque->prioriodade;

        aviao->proximo = aviao2;
        aviao2->anterior = aviao;
        deque->prioriodade = aviao;
    }

    deque->quantidade++;
}

void inserir_final(a_deque *deque,char *companhia, int combustivel)
{
    //Criando elemento
    a_elemento *aviao = criar_elemento(companhia, combustivel);

    if(deque->quantidade == 0)
    {
        deque->prioriodade = aviao;
        deque->final = aviao;
    }

        //Se o aviao tiver mais combustivel que o mais prioritário
    else
    {
        a_elemento *aviao2 = deque->final;

        aviao2->proximo = aviao;
        aviao->anterior = aviao2;

        deque->final = aviao;
    }

    deque->quantidade++;
}

void remover_prioridade(a_deque *deque)
{
    if(deque != NULL && deque->quantidade > 0)
    {
        a_elemento *prioridade = deque->prioriodade;

        deque->prioriodade = prioridade->proximo;

        if(prioridade->proximo!=NULL)
            prioridade->proximo->anterior = NULL;

        apagar_elemento(prioridade);

        deque->quantidade--;
    }
}

void remover_final(a_deque *deque)
{
    if(deque != NULL && deque->quantidade > 0)
    {
        a_elemento *final = deque->final;

        //Se final for diferente do inicio
        if(deque->prioriodade != final) {
            deque->final = final->anterior;
            final->anterior->proximo = NULL;
        }

        apagar_elemento(final);

        deque->quantidade--;
    }
}

void apagar_deque(a_deque *deque)
{
    if(deque != NULL)
    {
        if(deque->quantidade > 0)
        {
            int i, quantia = deque->quantidade;
            a_elemento *aviao = deque->prioriodade;

            // apagando todos os elementos
            for(i = 0; i<quantia;i++)
            {
                deque->prioriodade = aviao;
                aviao = aviao->proximo;
                remover_prioridade(deque);
            }
        }

        // Apagando deque
        free(deque);
    }
}

void imprimir_deque(a_deque *deque)
{
    if(deque != NULL && deque->quantidade > 0)
    {
        system(LIMPAR);
        a_elemento *ptr = deque->prioriodade;
        int i;

        printf("\n\t\tFila de Prioridade para Pouso\n\n");

        //Correndo pelo deque
        for(i = 0;i<deque->quantidade && ptr != NULL; i++)
        {
            //Se foi desviado
            if(ptr->atual->desviado == 0) {

                //Aviao caindo por falta de combustivel
                if(ptr->atual->combustivel == 0) {
                    printf("\t%d- [AVIAO EM QUEDA] %s | Combustivel: %d\n", i + 1, ptr->atual->companhia, ptr->atual->combustivel);
                }

                    //Aviao explodiu em queda
                else if(ptr->atual->combustivel < 0)
                {
                    printf("\t%d- [CAIU] %s | Mortes com Desaparecimento: %d\n", i + 1, ptr->atual->companhia, (i+1)*100+32);
                }

                    //Aviao em estado crítico
                else if(ptr->atual->combustivel < (i+3)*100) {
                    printf("\t%d- [CRITICO] %s | Combustivel: %d\n", i+1, ptr->atual->companhia, ptr->atual->combustivel);
                }

                    //Aviao normal
                else
                    printf("\t%d- %s | Combustivel: %d\n", i + 1, ptr->atual->companhia, ptr->atual->combustivel);
            }

                //Aviao desviado
            else
                printf("\t%d- \b[DESVIADO] %s\n", i, ptr->atual->companhia);
            ptr = ptr->proximo;
        }

        getchar();
        getchar();

        //Remove aqueles que foram desviados ou cairam
        remover_inativos(deque);
    }
    else if(deque != NULL && deque->quantidade == 0)
    {
        printf("NENHUM AVIAO ESTA CHEGANDO PARA POUSAR NESTE MOMENTO.");
        getchar();
        getchar();
    }
}

void reduzir_combustao(a_deque *deque)
{
    //Reduz combustivel em 100 a cada click
    if(deque != NULL && deque->quantidade > 0) {
        a_elemento *ptr = deque->prioriodade;

        int i;
        for (i = 0; i < deque->quantidade && ptr != NULL; i++) {

            if(ptr->atual->combustivel == 0)
                mover_final(deque,ptr);

            else if(ptr->atual->combustivel < 0)
            {
                //Se nao estiver no final
                if(deque->final != ptr)
                    mover_final(deque, ptr);

                remover_inativos(deque);
            }

            ptr->atual->combustivel -= 100;
            ptr = ptr->proximo;
        }
    }
}

int alternar_destino(a_deque *deque)
{
    int i, desvios = 0;

    if(deque != NULL && deque->quantidade > 0) {
        a_elemento *ptr = deque->prioriodade;

        //Percorrendo deque
        for (i = 0; i < deque->quantidade && ptr != NULL; i++) {

            //Se considerado critico a situacao de acordo com a posicao no deque
            if(ptr->atual->combustivel < (i+3)*100 && ptr->atual->desviado == 0
               && ptr->atual->combustivel > 0) {
                desvios++;
                ptr->atual->desviado = 1;

                //Colocando elemento em ultimo lugar
                mover_final(deque, ptr);

                // Reiniciando loop para nao perder referencias
                i=0;
                ptr = deque->prioriodade;
            }
            ptr = ptr->proximo;
        }
    }

    return desvios;
}

void mover_final(a_deque *deque, a_elemento *ptr)
{
    //Se for inicial
    if(deque->prioriodade == ptr && deque->quantidade > 1)
    {
        deque->prioriodade = ptr->proximo;
        deque->final->proximo = ptr;
        ptr->anterior = deque->final;
        ptr->proximo = NULL;
        deque->final = ptr;
    }
        //Se estiver no meio
    else if(deque->prioriodade != ptr && deque->final != ptr)
    {
        deque->final->proximo = ptr;
        ptr->anterior->proximo = ptr->proximo;
        ptr->proximo->anterior = ptr->anterior;
        ptr->anterior = deque->final;
        ptr->proximo = NULL;
        deque->final = ptr;
    }
}

void remover_inativos(a_deque *deque)
{
    if(deque != NULL)
    {
        //Enquanto existir desviados ou sem combustivel
        while((deque->quantidade > 0) && (deque->final->atual->desviado == 1
                                          || deque->final->atual->combustivel < 0)){
            remover_final(deque);
        }
    }
}