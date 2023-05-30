#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int valor;
  struct no *proximo;
  struct no *anterior;
} No;

void imprimirListaProximo(No **cabeca) {
  if (*cabeca != NULL) {
    printf("----> LISTA EM ORDEM CRESCENTE <----\n");
    No *aux = malloc(sizeof(No));
    aux = *cabeca;
    while (aux->proximo != NULL) {
      printf("%d - ", aux->valor);
      aux = aux->proximo;
    }
    printf("%d \n", aux->valor);
  } else {
    printf("a lista esta vazia\n");
  }
}
void insereOrdenado(No **cabeca, int numero) {
  No *novo = malloc(sizeof(No));
  novo->valor = numero;

  if (*cabeca == NULL) {
    novo->proximo = NULL;
    novo->anterior = NULL;
    *cabeca = novo;
  } else if (novo->valor < (*cabeca)->valor) {
    novo->proximo = *cabeca;
    novo->anterior = NULL;
    (*cabeca)->anterior = novo;
    *cabeca = novo;
  } else {
    No *aux = malloc(sizeof(No));
    aux = *cabeca;
    while (aux->proximo != NULL && novo->valor > (aux->proximo)->valor) {
      aux = aux->proximo;
    }
    novo->proximo = aux->proximo;
    novo->anterior = aux;
    if (aux->proximo != NULL) {
      (aux->proximo)->anterior = novo;
    }
    aux->proximo = novo;
  }
}
int inedito(No **cabeca, int numero) {
  if (*cabeca != NULL) {
    No *aux = malloc(sizeof(No));
    No *auxNum = malloc(sizeof(No));
    auxNum->valor = numero;
    aux = *cabeca;
    while (aux->proximo != NULL) {
      if (aux->valor == auxNum->valor) {
        return 0;
      }
      aux = aux->proximo;
    }
    if (aux->valor == auxNum->valor) { // verifica o ultimo elemento.
      return 0;
    }
    return 1;
  } else {
    return 1;
  }
}
void removeNumeroInformado(No **cabeca, int numeroInformado) {
  if (*cabeca != NULL) {
    No *aux = *cabeca;
    No *auxNum = malloc(sizeof(No));
    auxNum->valor = numeroInformado;

    if ((*cabeca)->valor == auxNum->valor) { // remove no início
      if ((*cabeca)->proximo == NULL) {
        free(*cabeca);
        *cabeca = NULL;
      } else {
        *cabeca = (*cabeca)->proximo;
        free((*cabeca)->anterior);
        (*cabeca)->anterior = NULL;
      }
    } else {
      while (aux != NULL) {
        if (aux->valor == auxNum->valor) {
          if (aux->proximo != NULL) {
            aux->anterior->proximo = aux->proximo;
            aux->proximo->anterior = aux->anterior;
          } else { // remove no final
            aux->anterior->proximo = NULL;
          }
          free(aux);
          break;
        }
        aux = aux->proximo;
      }
    }
  }
}
int procuraNumero(No **cabeca, int numeroInformado) {
  if (*cabeca != NULL) {
    No *aux = malloc(sizeof(No));
    No *auxNum = malloc(sizeof(No));
    auxNum->valor = numeroInformado;
    aux = *cabeca;
    while (aux->proximo != NULL) {
      if (aux->valor == auxNum->valor) {
        return 1;
      }
      aux = aux->proximo;
    }
    if (auxNum->valor == aux->valor) {
      return 1;
    }
    return 0;

  } else {
    return 0;
  }
}
void imprimeListaAnterior(No **cabeca) {
  if (*cabeca != NULL) {
    No *aux = malloc(sizeof(No));
    aux = *cabeca;
    while (aux->proximo != NULL) { // procura o ultimo nó
      aux = aux->proximo;
    }
    printf("----> LISTA EM ORDEM DECRESCENTE <----\n");
    while (aux->anterior != NULL) {
      printf("%d - ", aux->valor);
      aux = aux->anterior;
    }
    printf("%d \n", aux->valor);
  } else {
    printf("a lista esta vazia\n");
  }
}
void removeTodosNos(No **cabeca) {
  No *atual = *cabeca;
  No *proximo;

  while (atual != NULL) {
    proximo = atual->proximo;
    free(atual);
    atual = proximo;
  }
  *cabeca = NULL;
}

int main() {
    No *cabeca = NULL;
    int opcao = 0;
    int valor;
    
    do {
        printf("\nEscolha uma opção:\n");
        printf("1 - Verificar se a lista está vazia\n");
        printf("2 - Criar uma lista unitária (se estiver vazia)\n");
        printf("3 - inserir um número\n");
        printf("4 - remover um número\n");
        printf("5 - Mostrar a lista ordem cresente\n");
        printf("6 - Mostrar a lista ordem decresente\n");
        printf("7 - Finalizar programa (liberando a memória alocada)\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (cabeca == NULL) {
                    printf("A lista está vazia.\n");
                } else {
                    printf("A lista não está vazia.\n");
                }
                break;
            case 2:
                if (cabeca == NULL) {
                    printf("Digite o valor da lista unitária: ");
                    scanf("%d", &valor);
                    insereOrdenado(&cabeca, valor);
                } else {
                    printf("A lista já contém elementos.\n");
                }
                break;
            case 3:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                if(inedito(&cabeca, valor)){
                  insereOrdenado(&cabeca, valor);
                }else{
                  printf("numero ja esta na lista");
                }
                break;
            case 4:
                printf("numero a ser removido: ");
                scanf("%d",&valor);
                removeNumeroInformado(&cabeca, valor);
                break;
            case 5:
                imprimirListaProximo(&cabeca);
                break;
            case 6:
                imprimeListaAnterior(&cabeca);
                break;
            case 7:
                removeTodosNos(&cabeca);
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 7);

    return 0;
}
