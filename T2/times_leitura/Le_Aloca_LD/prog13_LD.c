


#include "LD_Header.h"

#include <locale.h> // biblioteca da função setlocale

#define MAX 100

t_lista* cria_lista_times () {
  
/* define a localização da via de comunicação relacionado a 
codificação dos mesmos, facilita os caracteres multibytes*/
setlocale(LC_CTYPE,"pt_BR.UTF-8");   
  
FILE *arq = fopen("teams.txt", "r");
  
int i = 0; 
int linhas = MAX;
char str[linhas][MAX]; //matriz maxima str[100][100]
    
for(i = 1; i <= linhas; i++){   // loop que percorre 
    
    //Busca as  linhas do arquivo     
    if (fgets (str[i], sizeof(str[i]), arq) == NULL){ // leitura da i-ésima linha com condição para terminar o loop
      linhas = i; // Atualiza o número de times que foi possível ler e atribui para variavel 'linhas'
      break;                                        
    }
  
}  
  
int k = 0,j = 0,n = 0; // usados para indices
char nome[30]; // string que guarda o nome dos times para alocação na lista dupla
int atq = 0, def = 0, res = 0, vel = 0; // guardam os atributos para alocação na lista dupla
char str_numeros[30];


t_lista* lista = aloca_lista ();

// loop principal que percorre todas as linhas do arquivo
for(int i = 1; i < linhas; i++){ 

    // loop utilizado para guardar os nomes do times, sendo ',' condição de parada
    while(str[i][j] != ','){
        
        nome[k++] = str[i][j++]; // atribui os nomes para a string nome

    }
    
    nome[k] = '\0'; // sinalizador de parada no final da string nome
    
    // loop começa a partir do index de parada do loop while anterior
    for(n = 0,j = k; str[i][j] != '\n'; j++,n++) { // loop para pegar parte da string que contem apenas os atributos (numeros inteiros) 
        str_numeros[n] = str[i][j];
    }
    
    str_numeros[n]= '\0'; // sinalisador no final da string dos atributos

    int conta_numeros; // variavel criada apenas para checar a leitura dos atributos
    conta_numeros = sscanf(str_numeros, ",%d, %d, %d, %d\n", &atq, &def, &res, &vel);
    if(conta_numeros != 4) 
        printf("Erro na leitura dos atributos!\n");


    // Inserindo nome,atq,def,res,vel elemento a elemento na Lista Duplamente encadeada
    inserir_final (nome, atq, def, res, vel, lista); 
        
    k=0,j=0; // indices voltam para o inicio para nova leitura e alocação

}

fclose(arq);// Fecha o arquivo de leitura

    // exlusão aleatoria de 16 times da lista, utiliza lista->qtd 
    while (lista->qtd > 16){

        int pos = rand()%100; 
        remove_pos (pos ,lista);
   
    }

/*
printf("=====================================================================\n");
printf("Lista apos exclusões: \n");
imprime_lista (lista);
printf("=====================================================================\n");
*/


//apaga_lista (lista);

    return lista;
}
//===========================================================================
void imprime_lista_times (t_lista* lista){
	
    int i;
    
    t_elemento* ptr = lista->primeiro;
	
	if(esta_vazia(lista)){
		printf("LISTA VAZIA!\n");
		return ;
	}

    printf("\n\n->Escolha seu time\n");

    int aleatory = rand()%4;

    int cont = 1;

	for( i=0 ; i < lista->qtd; i++, ptr = ptr->proximo){
		
        aleatory = rand()%3;
        

        if(aleatory == 0){
            printf("\nTime %d:\n", cont++);

            printf("Ataque: %d, ", ptr->team->ataque);
            printf("Defesa: ??, ");
            printf("Resistencia: ??, ");
            printf("Velocidade:  ??. \n");

        }else if(aleatory == 1){

            printf("\nTime %d:\n", cont++);

            printf("Ataque: ??, ");
            printf("Defesa: %d, ", ptr->team->defesa);
            printf("Resistencia: ??, ");
            printf("Velocidade:  ??. \n");

        }else if(aleatory == 2){

            printf("\nTime %d:\n", cont++);

            printf("Ataque: ??, ");
            printf("Defesa: ??, ");
            printf("Resistencia: %d, ", ptr->team->resistencia);
            printf("Velocidade:  ??. \n");

        }else if(aleatory == 3){

            printf("\nTime %d:\n", cont++);
            printf("Ataque: ??, ");
            printf("Defesa: ??, ");
            printf("Resistencia: ??, ");
            printf("Velocidade:  %d. \n", ptr->team->velocidade);

        }else{
            printf("QUE PORRA EH ESSA?..i = %d\n", i);
        }
	}
	
}
//==========================================================================

