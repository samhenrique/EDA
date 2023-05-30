#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int valor;
  struct no *proximo;
} No;

void enfileirar(No **cabeca, No **cauda, int numero) {
  No *novo = malloc(sizeof(No));
  novo->proximo = NULL;
  novo->valor = numero;
  if (novo) {
    if (*cabeca == NULL) {
      novo->proximo = *cabeca;
      *cabeca = novo;
      *cauda = novo;
    } else {
      (*cauda)->proximo = novo;
      *cauda = novo;
    }
  }
}

void desenfileirar(No **cabeca) {
  No *remove = NULL;
  if (*cabeca != NULL) {
    remove = *cabeca;
    *cabeca = (*cabeca)->proximo;
    free(remove);
  } else {
    printf("A fila está vazia.\n");
  }
}

void imprimir(No **cabeca) {
  if (*cabeca != NULL) {
    No *aux = (*cabeca);
    printf("Fila: ");
    while (aux != NULL) {
      printf("%d ", aux->valor);
      aux = aux->proximo;
    }
    printf("\n");
  } else {
    printf("A fila está vazia.\n");
  }
}

void liberar_memoria(No **cabeca) {
  int qtd_nos = 0;
  No *aux = (*cabeca);
  while (aux != NULL) {
    No *remove = aux;
    aux = aux->proximo;
    free(remove);
    qtd_nos++;
  }
  printf("%d nós foram excluídos.\n", qtd_nos);
}

int main() {
  No *cabeca = NULL;
  No *cauda = NULL;
  int opcao, numero;
  do {
    printf("\nEscolha uma opção:\n");
    printf("1 - Verificar se a fila está vazia\n");
    printf("2 - Criar fila unitária\n");
    printf("3 - Enfileirar um número\n");
    printf("4 - Desenfileirar um número\n");
    printf("5 - Mostrar os elementos da fila\n");
    printf("0 - Sair\n");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
      if (cabeca == NULL) {
        printf("A fila está vazia.\n");
      } else {
        printf("A fila não está vazia.\n");
      }
      break;
    case 2:
      if (cabeca == NULL) {
        printf("Digite o número da fila unitária: ");
        scanf("%d", &numero);
        enfileirar(&cabeca, &cauda, numero);
        printf("Fila unitária criada com sucesso.\n");
      } else {
        printf("A fila já contém elementos. Não é possível criar uma fila "
               "unitária.\n");
      }
      break;
    case 3:
      printf("Digite o número a ser enfileirado: ");
      scanf("%d", &numero);
      enfileirar(&cabeca, &cauda, numero);
      printf("Número enfileirado com sucesso.\n");
      break;
    case 4:
      desenfileirar(&cabeca);
      break;
    case 5:
      imprimir(&cabeca);
      break;
    case 0:
      liberar_memoria(&cabeca);
    default:
      printf("opcao invalida");
    }
  } while (opcao != 0);

  return 0;
}
