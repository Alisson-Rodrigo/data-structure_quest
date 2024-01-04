#include <stdio.h>
#include <stdlib.h>

#include "animal.c"
#include "fazenda.h"
#include "criador.c"

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

Criador *criarListaCircularFazendas() {
	return NULL;
}

Fazenda *cadastrar(Fazenda *fazendas) {
	Fazenda *novo = (Fazenda *) malloc(sizeof(Fazenda));
	if (novo == NULL) {
		printf("Erro ao alocar memoria\n");
		exit(1);
	}
	printf("Informe o estado onde fica a fazenda: ");
	scanf("%s",novo->localizacao.estado);
	printf("Informe a cidade onde fica a fazenda: ");
	scanf("%s",novo->localizacao.cidade);
	printf("Informe o estado onde fica a fazenda: ");
	scanf("%s",novo->localizacao.estado);
	printf("Informe o logradouro proximo a fazenda: ");
	scanf("%s",novo->localizacao.logradouro);
	printf("Informe o id da fazenda: ");
	scanf("%d",&novo->id_criador);

}
