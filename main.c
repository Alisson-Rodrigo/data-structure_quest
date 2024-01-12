#include <stdio.h>
#include <stdlib.h>

#include "criador.h"
#include "criador.c"
#include "fazenda.h"

int main() {
    Criador *criadores = criarListaDuplaCriadores();
    Criador *criadorSelecionado = NULL;
    int idFazenda, opcao;

    do {
        printf("\n---------------------------------------------\n");
        printf("1 - Cadastrar Criador\n"); //ok
        printf("2 - Cadastrar Fazenda\n"); //ok
        printf("3 - Cadastrar Animal\n"); //ok
        printf("4 - Mostrar Criadores\n"); //ok
        printf("5 - Mostrar Animais por Sexo\n"); //ok
        printf("6 - Mostrar Animais por Status\n");//ok 
        printf("7 - Calcular Total de Arrobas\n");
        printf("8 - Calcular Valor Total da Fazenda\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criadores = cadastrarCriador(criadores);
                break;
            case 2:
                criadorSelecionado = buscarCriador(criadores);
                if (criadorSelecionado != NULL) {
                    criadorSelecionado->fazendas = criarListaEncadeadaCircularFazendas();
                    criadorSelecionado->fazendas = cadastrarFazenda(criadorSelecionado->fazendas);
                } else {
                    printf("Criador nao encontrado.\n");
                }
                break;
            case 3:
                if (criadorSelecionado != NULL) {
                    idFazenda = buscarFazenda(criadorSelecionado->fazendas);
                    if (idFazenda) {
                        Fazenda *fazendaSelecionada = getFazenda(criadorSelecionado->fazendas, idFazenda);
                        if (fazendaSelecionada != NULL) {
                            if (fazendaSelecionada->rebanho == NULL) {
                                fazendaSelecionada->rebanho = criaListaEncadeadaSimplesAnimais();
                            }
                            fazendaSelecionada->rebanho = cadastrarAnimal(fazendaSelecionada->rebanho);
                        } else {
                            printf("Fazenda inexistente.\n");
                        }
                    } else {
                        printf("Fazenda inexistente.\n");
                    }
                } else {
                    printf("Criador nao selecionado.\n");
                }
                break;
            case 4:
                mostrarCriadores(criadores);
                break;
            case 5:
                if (criadorSelecionado != NULL) {
                    mostrarAnimalSexo(criadorSelecionado->fazendas);
                } else {
                    printf("Criador nao selecionado.\n");
                }
                break;
            case 6:
                if (criadorSelecionado != NULL) {
                    mostrarAnimalStatus(criadorSelecionado->fazendas);
                } else {
                    printf("Criador nao selecionado.\n");
                }
                break;
            case 7:
                if (criadorSelecionado != NULL) {
                    arrobaTotal(criadorSelecionado->fazendas);
                } else {
                    printf("Criador nao selecionado.\n");
                }
                break;
            case 8:
                if (criadorSelecionado != NULL) {
                    valorTotal(criadorSelecionado->fazendas);
                } else {
                    printf("Criador nao selecionado.\n");
                }
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    // Libere a mem�ria alocada antes de encerrar o programa...

    return 0;
}

