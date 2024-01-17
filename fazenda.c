#include <stdio.h>
#include <stdlib.h>

#include "animal.h"
#include "criador.h"
#include "fazenda.h"

struct endereco
{
	char cidade[50], estado[2], logradouro[200];
};

struct fazenda
{
	int id_criador, id_fazenda;
	char nome[100];
	Endereco localizacao;
	float valor_fazenda; // lembrar de atualizar o valor sempre que houver alterações no rebanho
	Animal *rebanho;	 // ponteiro para uma lista (verificar no .h do animal que lista é)
	// ponteiro para permitir o apontamento para o proximo elemento da lista (deve ser circular)
	struct fazenda *prox;
};

// cria a lista de fazenda
Fazenda *criarListaEncadeadaCircularFazendas()
{
	return NULL;
}
// cadastra uma nova fazenda
Fazenda *cadastrarFazenda(Fazenda *fazendas)
{
	Fazenda *novo = (Fazenda *)malloc(sizeof(Fazenda));
	Fazenda *aux = fazendas;

	// novo->id_fazenda = rand() % 100 + 10;
	printf("\nInsira o ID da fazenda: ");
	scanf("%d", &novo->id_fazenda);
	printf("\nInsira novamente seu ID de criador: ");
	scanf("%d", &novo->id_criador);
	printf("Insira o nome da fazenda: ");
	scanf("%s", novo->nome);
	printf("Insira a cidade: ");
	scanf("%s", novo->localizacao.cidade);
	printf("Insira o estado: ");
	scanf("%s", novo->localizacao.estado);
	printf("Insira o logradouro: ");
	scanf("%s", novo->localizacao.logradouro);

	if (fazendas == NULL)
	{
		novo->prox = novo;
		return novo;
	}

	while (aux->prox != fazendas)
	{
		aux = aux->prox;
	}

	aux->prox = novo;
	novo->prox = fazendas;

	return fazendas;
}

// verifica se existem fazendas na lista
int buscarFazenda(Fazenda *fazendas)
{
	Fazenda *aux = fazendas;
	int id;
	printf("Informe o id da fazenda a buscar\n");
	scanf("%d", &id);

	if (fazendas == NULL)
	{
		printf("\nSem fazendas registradas!\n");
		return 0;
	}

	if (aux->id_fazenda == id)
	{
		return aux->id_fazenda;
	}

	while (aux->prox != fazendas && aux->prox->id_fazenda != id)
	{
		aux = aux->prox;
	}

	return aux->prox == fazendas ? 0 : aux->prox->id_fazenda;
}
// retorna a fazenda escolhjida por meio de id
Fazenda *getFazenda(Fazenda *fazendas, int id)
{

	Fazenda *aux = fazendas;

	if (fazendas == NULL)
	{
		printf("\nSem fazendas registradas!\n");
		return fazendas;
	}

	if (aux->id_fazenda == id)
	{
		return aux;
	}

	while (aux->prox != fazendas && aux->prox->id_fazenda != id)
	{
		aux = aux->prox;
	}

	return aux->prox == fazendas ? NULL : aux->prox;
}

// mostra o sexo dos animais exixtentes na fazenda
void mostrarAnimalSexo(Fazenda *fazendas)
{
	Animal *aux;
	int id;
	printf("\nInsira o ID da fazenda: ");
	scanf("%d", &id);
	Fazenda *fazenda = getFazenda(fazendas, id);
	if (fazenda)
	{
		contAnimaisSexo(fazenda);
	}
	else
	{
		printf("\nFazenda inexistente\n");
	}
}

// mostra o status do anima,de qual fazenda ele e ,peso,sexo e etc
void mostrarAnimalStatus(Fazenda *fazendas)
{

	int sts, id;
	printf("\nInsira o ID da fazenda: \n");
	scanf("%d", &id);
	Fazenda *fazenda = getFazenda(fazendas, id);
	printf("Informe o tipo de status do animal que queira listar: \n");
	printf("1 - Nascimento no propria fazenda\n2 - Vendido\n3 - Troca\n");
	scanf("%d", &sts);

	if (fazenda)
	{
		MostrarStatus(fazenda, sts);
	}
	else
	{
		printf("\nFazenda inexistente\n");
	}
}

// remove uma fazenda da lista
Fazenda *removerFazenda(Fazenda *fazendas, int id)
{
	Fazenda *aux = fazendas, *aux2;

	if (fazendas == NULL)
	{
		printf("\nLista vazia\n");
		return fazendas;
	}

	if (!(getFazenda(fazendas, id)))
	{
		printf("\nFazenda nao cadastrada!\n");
		return fazendas;
	}

	if (aux->id_fazenda == id)
	{

		if (aux->rebanho != NULL)
		{
			printf("\nNao eh possivel remover fazenda com rebanho!\n");
			return fazendas;
		}

		if (aux->prox == aux)
		{
			return NULL;
		}

		while (aux->prox != fazendas)
		{
			aux = aux->prox;
		}

		aux->prox = fazendas;
		free(fazendas);

		return aux->prox;
	}

	while (aux->prox != fazendas && aux->prox->id_fazenda != id)
	{
		aux = aux->prox;
	}

	if (aux->prox == fazendas)
	{
		printf("\nFazenda nao cadastrada!\n");
		return fazendas;
	}

	if (aux->rebanho != NULL)
	{
		printf("\nNao eh possivel remover fazenda com rebanho!\n");
		return fazendas;
	}

	aux2 = aux->prox;
	aux->prox = aux->prox->prox;
	free(aux2);

	return fazendas;
}

// calcula o toal de arrobas dda fazenda
void arrobaTotal(Fazenda *fazendas)
{
	int id;
	float arrobas = 0;

	printf("\nInsira o ID da fazenda: ");
	scanf("%d", &id);
	Fazenda *fazenda = getFazenda(fazendas, id);

	if (fazenda)
	{
		arrobas = contArroba(fazenda);
		printf("Total de arrobas: %.2f\n", arrobas);
	}
	else
	{
		printf("\nFazenda inexistente\n");
	}
}
// calcula o valor da fazenda
void valorTotal(Fazenda *fazendas)
{
	int id;
	float arrobas = 0;

	printf("\nInsira o ID da fazenda: ");
	scanf("%d", &id);
	Fazenda *fazenda = getFazenda(fazendas, id);

	if (fazenda)
	{
		arrobas = contArroba(fazenda);
		printf("Valor total da fazenda: %.2f\n", arrobas * 235);
	}
	else
	{
		printf("\nFazenda inexistente\n");
	}
}

// libera a lsita de fazendas
void liberarFazenda(Fazenda *fazendas)
{
	if (fazendas == NULL)
	{
		return;
	}

	Fazenda *atual = fazendas;
	Fazenda *proxima;

	do
	{

		liberarRebanho(atual->rebanho);

		proxima = atual->prox;
		free(atual);
		atual = proxima;

	} while (atual != fazendas);
}
