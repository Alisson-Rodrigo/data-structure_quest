#include <stdio.h>
#include <stdlib.h>
#include "animal.c"


int main() {
    Animal *rebanho = criaListaEncadeadaSimplesAnimais();
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar novo animal\n");
        printf("2 - Imprimir lista de animais\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                rebanho = cadastrar(rebanho);
                break;
            case 2:
                imprimir(rebanho);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}