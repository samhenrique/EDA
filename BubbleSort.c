#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int vetor[],int tamanho);
void imprimeVetor(int vetor[],int tamanho);
int main(void) {

  int vetor[10] = {10,3,7,8,6,4,9,2,5,1};
  int tamanho = sizeof(vetor)/sizeof(int);
  bubbleSort(vetor,tamanho);
  imprimeVetor(vetor,tamanho);
}

void bubbleSort(int vetor[], int tamanho){
  int auxiliar;
  int contador = 0;
  bool troca = true;
  while(troca == true){
    troca = false;
    for(int i = 0; i < tamanho - 1 ; i++){
      contador++;
      if(vetor[i] > vetor[i+1]){
        auxiliar = vetor[i];
        vetor[i] = vetor[i+1];
        vetor[i+1]= auxiliar;
        troca = true;
      }      
    }
    if(!troca) break;
  }
  printf("passos: %d \ntamanho do vetor: %d \nvetor ordenado: ",contador,(tamanho+1));
}

void imprimeVetor(int vetor[],int tamanho){
  for(int i = 0; i<tamanho;i++){
    printf("%d ",vetor[i]);
  }  
}
