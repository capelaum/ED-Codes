

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define MAX 100

int main() {
  
  setlocale(LC_CTYPE,"pt_BR.UTF-8"); 
  FILE *arq = fopen("teams.txt", "r"); // abri o arquivo teams.txt
  
  int i = 0,j = 0;
  int nome_tam = 0;
  
  int linhas = MAX;
  char str[linhas][MAX];                            //matriz maxima str[100][100];
    
  for(int i = 1; i <= linhas; i++){   
    //Busca as  linhas do arquivo     
    if (fgets (str[i], sizeof(str[i]), arq) == NULL){ // leitura da i-ésima linha e condição para continuar o loop;
      linhas = i;                                     // Atualiza o número de times que foi possível ler;
      break;                                          // Verifica se é possível ler a próxima linha;
    }
  }  
  
  int k = 0;
  
  char nome[30]; // string que guarda o nome dos times para alocação na lista dupla
  
  int atq = 0, def = 0, res = 0, vel = 0; // guardam os atributos para alocação na lista dupla

  char str_numeros[30];

for(int i = 1; i < linhas; i++){ // loop que percorre todas as linhas do arquivo
  
  /* evita que o programa continue a leitura dos times acima 
  do numero de linhas disponiveis do arquivo. 
  if(i==linhas) { // condição de parada
    printf("STOP!\n"); 
    break;
  }
  */

  printf("=====================\n");  
  printf("%s", str[i]);

  while(str[i][j] != ','){
    
    nome[k++] = str[i][j++];

  }
  printf("TIME [%d]\n", i);
  nome[k] = '\0';
  printf("NOME = %s\n", nome);
  
  int n = 0;

  for(n = 0,j=k; str[i][j] != '\n'; j++) { // loop para pegar parte da string que contem apenas os atributos (numeros inteiros) 
    str_numeros[n++] = str[i][j];
  }
  
  str_numeros[n]= '\0';

  int conta_numeros;

  conta_numeros = sscanf(str_numeros, ",%d, %d, %d, %d\n", &atq, &def, &res, &vel);

  if(conta_numeros != 4) 
    printf("Erro na leitura dos atributos!\n");

  printf ("atq  - %d \n", atq);
  printf ("def  - %d \n", def);
  printf ("res  - %d \n", res);
  printf ("vel  - %d \n", vel);
  
  k=0,j=0;

}

  fclose(arq);
  return 0;
}
