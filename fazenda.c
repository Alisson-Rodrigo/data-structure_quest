#include <stdio.h>
#include <stdlib.h>

#include "animal.h"
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
	//ponteiro para permitir o apontamento para o proximo elemento da lista (deve ser circular)
	struct fazenda *prox;
};

Criador *criarListaEncadeadaCircularFazendas(){
	return NULL;
}