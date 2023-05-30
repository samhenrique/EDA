#include <stdbool.h>
#include <stdio.h>

void quickSort(int vetor[], int esquerda, int direita, int *comparacoes);
void imprimeVetor(int vetor[], int tamanho);
int main(void) {

  int vetor[7] = {1, 5, 2, 7, 3, 6, 4};
  int tamanho = sizeof(vetor) / sizeof(int);
  int comparacoes = 0;
  quickSort(vetor, 0, tamanho - 1, &comparacoes);
  imprimeVetor(vetor, tamanho);
  printf("\nNúmero de comparações: %d\n", comparacoes);
}

void quickSort(int vetor[], int esquerda, int direita, int *comparacoes) {
  int i = esquerda, j = direita;
  int temp, pivo = vetor[(esquerda + direita) / 2];

  while (i <= j) {
    while (vetor[i] < pivo) {
      i++;
      (*comparacoes)++;
    }
    while (vetor[j] > pivo) {
      j--;
      (*comparacoes)++;
    }
    if (i <= j) {
      temp = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = temp;
      i++;
      j--;
    }
  }

  if (esquerda < j)
    quickSort(vetor, esquerda, j, comparacoes);
  if (i < direita)
    quickSort(vetor, i, direita, comparacoes);
}

void imprimeVetor(int vetor[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  }
}
