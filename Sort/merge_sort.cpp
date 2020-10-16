#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10

using namespace std;

void imprimeVetor(int vetor[]){
    int i;
    cout << "\n";
    for(i = 0; i < TAM; i++){
        cout << " |" << vetor[i] << "| ";
    }
}

void merge_sort(int vetor[TAM]){

}

int main(){

    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};

    merge_sort(vetor, 0, TAM);

    imprimeVetor(vetor);

    return 0;
}
