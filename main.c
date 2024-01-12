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
        printf("9 - Realizar Permuta de Animais\n");
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
			        if (criadorSelecionado->fazendas == NULL) {
			            criadorSelecionado->fazendas = criarListaEncadeadaCircularFazendas();
			        }
			        
			        // Adiciona a nova fazenda à lista existente
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
            case 9:
			    if (criadorSelecionado != NULL) {
			        idFazenda = buscarFazenda(criadorSelecionado->fazendas);
			        if (idFazenda) {
			            Fazenda *fazendaOrigem = getFazenda(criadorSelecionado->fazendas, idFazenda);
			            if (fazendaOrigem != NULL) {
			                int idAnimal;
			                printf("Informe o ID do animal a ser permutado: ");
			                scanf("%d", &idAnimal);
			
			                Fazenda *fazendaDestino = NULL;
			                int tentativas = 0;
			
			                do {
			                    if (tentativas > 0) {
			                        printf("Fazenda de destino inexistente. Tente novamente.\n");
			                    }
			
			                    printf("Informe o ID da fazenda de destino: ");
			                    scanf("%d", &idFazenda);
			                    fazendaDestino = getFazenda(criadorSelecionado->fazendas, idFazenda);
			
			                    tentativas++;
			                } while (fazendaDestino == NULL);
			
			                fazendaOrigem->rebanho = permutasAnimais(fazendaOrigem, fazendaDestino, idAnimal);
			            } else {
			                printf("Fazenda de origem inexistente.\n");
			            }
			        } else {
			            printf("Fazenda inexistente.\n");
			        }
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

    // Libere a memï¿½ria alocada antes de encerrar o programa...

    return 0;
}

