//Essde programa exemplifica uma implementação de Bubble Sort para inteiros.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data[100],i,n,step,temp;
    printf("Entre o tamanho de elementos a ser processado: ");			//define o tamanho do vetor a ser ordenado
    scanf("%d",&n);				
    for(i=0;i<n;++i)								//obtém do usuário os números a serem ordenados
    {
        printf("%d. Insira um elemento: ",i+1);
        scanf("%d",&data[i]);
    }

    for(step=0;step<n-1;++step)							//percorre o vetor
    for(i=0;i<n-step-1;++i)
    {		
        if(data[i]>data[i+1])   						//determina se o par adjacênte é ordenado entre si
        {
            temp=data[i];
            data[i]=data[i+1];
            data[i+1]=temp;
        }
    }
    system("clear");
    printf("Em ordem crescente: ");
    for(i=0;i<n;++i)
         printf("%d  ",data[i]);
    printf("\n\n");	
    return 0;
}
