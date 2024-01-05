#include <stdio.h>
#include <stdlib.h>

#include "animal.c"
#include "criador.h"
#include "fazenda.h"

struct endereco{
	char cidade[50], estado[2], logradouro[200];
	// logradouro: lugar, como praças, jardins, hortos, passeios etc., mantidos pelas municipalidades para desfrute da população.
};

struct fazenda
{
	int id_criador, id_fazenda;
	char nome[100];
	Endereco localizacao;
	float valor_fazenda;//lembrar de atualizar o valor sempre que houver alterações no rebanho
	Animal *rebanho; // ponteiro para uma lista (verificar no .h do animal que lista é)
	struct fazenda *prox; //ponteiro para permitir o apontamento para o proximo elemento da lista (deve ser circular)

};

Fazenda *criarListaCircularFazendas() {
	return NULL;
}

Fazenda *cadastrar(Fazenda *fazendas) {
	Fazenda *novo = (Fazenda *) malloc(sizeof(Fazenda));
	if (novo == NULL) {
		printf("Erro ao alocar memoria\n");
		exit(1);
	}

	printf("Digite o id do criador: ");
	scanf("%d",novo->id_criador);
	printf("Digite o id da fazenda: ");
	scanf("%d",novo->id_fazenda);
	printf("Digite o nome: ");
	scanf("%s",novo->nome);
	printf("Digite a cidade: ");
	scanf("%s",novo->localizacao.cidade);
	printf("Digite o estado: ");
	scanf("%s",novo->localizacao.estado);
	printf("Digite o logradouro: ");
	scanf("%s",novo->localizacao.logradouro);
	printf("Digite o valor da fazenda: ");
	scanf("%f",novo->valor_fazenda);

	novo->rebanho->id_animal = 1;
	

}
