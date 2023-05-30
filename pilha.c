#include <stdio.h>
#include <stdlib.h>

typedef struct no {        
    int valor;
    struct no *proximo;
} No;

void empilhar(No **topo, int valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = (*topo);
    *topo = novo;
}

void desempilhar(No **topo) {
    if (*topo == NULL) {
        printf("Erro: pilha vazia!\n");
    } else {
        No *remove = *topo;
        (*topo) = (*topo)->proximo;
        free(remove);
    }
}

void imprimir_pilha(No **topo) {
    printf("Pilha:\n");
    if (*topo == NULL) {
        printf("Pilha vazia.\n");
    } else {
        No *aux = *topo;
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            aux = aux->proximo;
        }
    }
}

void desempilhar_tudo(No **topo) {
    int cont = 0;
    while (*topo != NULL) {
        No *no_removido = *topo;
        *topo = (*topo)->proximo;
        free(no_removido);
        cont++;
    }
    printf("Foram excluídos %d nós.\n", cont);
}

int main() {
    No *topo = NULL;
    int opcao = 0;
    int valor;
    
    do {
        printf("\nEscolha uma opção:\n");
        printf("1 - Verificar se a pilha está vazia\n");
        printf("2 - Criar uma pilha unitária (se estiver vazia)\n");
        printf("3 - Empilhar um número\n");
        printf("4 - Desempilhar um número\n");
        printf("5 - Mostrar a pilha\n");
        printf("6 - Finalizar programa (liberando a memória alocada)\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (topo == NULL) {
                    printf("A pilha está vazia.\n");
                } else {
                    printf("A pilha não está vazia.\n");
                }
                break;
            case 2:
                if (topo == NULL) {
                    printf("Digite o valor da pilha unitária: ");
                    scanf("%d", &valor);
                    empilhar(&topo, valor);
                } else {
                    printf("A pilha já contém elementos.\n");
                }
                break;
            case 3:
                printf("Digite o valor a ser empilhado: ");
                scanf("%d", &valor);
                empilhar(&topo, valor);
                break;
            case 4:
                desempilhar(&topo);
                break;
            case 5:
                imprimir_pilha(&topo);
                break;
            case 6:
                desempilhar_tudo(&topo);
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}