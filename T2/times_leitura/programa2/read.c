


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 100

int main (){

    int linhas = MAX;                                //Número de times(será atualizado);
    setlocale(LC_CTYPE,"pt_BR.UTF-8");              //codificação UTF8;
    FILE * teams = fopen ("teams.txt", "r");        //arquivo dos times;
                
    if(!teams)
        return 0;
    
    char str[linhas][MAX];                            //matriz maxima str[100][100];
    
    for(int i = 0; i < linhas; i++){   
        //Busca as  linhas do arquivo     
		if (fgets (str[i], sizeof(str[i]), teams) == NULL){ // leitura da i-ésima linha e condição para continuar o loop;
			linhas = i;                                     // Atualiza o número de times que foi possível ler;
            break;                                          // Verifica se é possível ler a próxima linha;
        }
    }  
    
    printf ("LINHAS = %d\n", linhas);
    for(int i = 0; i < linhas; i++){
        printf("%s", str[i]);                       //Imprime caractere a caracte no arquivo de saída;   
    }
    

    fclose(teams);                                  //Fecha o arquivo de times;
    return 0;
}