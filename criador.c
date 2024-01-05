#include <stdio.h>
#include <stdlib.h>

#include "criador.h"
#include "fazenda.h"

struct criador{
	int id_criador;
	char nome[100];
	Fazenda *fazendas;			// Esse ponteiro e uma lista circular (atentem-se)
	float patrimonio;			// esse valor deve ser constantemente modificado para que o valor esteja atualizado
	struct criador *prox, *ant; // lista dupla encadeada, nao é necessário ser circular
};

Criador *criarListaDuplaCriadores(){
	return NULL;
}

Criador *cadastrar(Criador *criadores){
	Criador *novo = (Criador *)malloc(sizeof(Criador));
	if (novo == NULL)
	{
		printf("Erro ao alocar memoria\n");
		exit(1);
	}
	printf("Informe o id do criador: ");
	scanf("%d", &novo->id_criador);
	// printf("Informe o nome do criador: ");
	// scanf("%s",novo->nome);

	if (criadores == NULL || criadores->id_criador > novo->id_criador){
		novo->prox = criadores;
		novo->ant = criadores;
		criadores = novo;
	}
	else{
		Criador *aux = criadores;
		while (aux->prox != NULL && aux->prox->id_criador < novo->id_criador){
			aux = aux->prox;
		}
		novo->prox = aux->prox;

		if (aux->prox != NULL){
			aux->prox->ant = novo;
		}

		aux->prox = novo;
		novo->ant = aux;
	}

	return criadores;
}

void imprimir(Criador *criadores){
	Criador *aux = criadores;
	while (aux != NULL){
		printf("id: %d\n", aux->id_criador);
		// printf("nome da fazenda: %s\n", aux->nome);
		aux = aux->prox;
	}
}

Criador *remover(Criador *criadores) {
    Criador *aux = criadores;
    int id;

    if (criadores == NULL) {
        printf("Lista vazia.");
        return criadores; // Retorna a lista original, pois não há nada para remover
    }

    printf("Informe o id a ser removido: ");
    scanf("%d", &id);

    while (aux != NULL && id != aux->id_criador) {
        aux = aux->prox;
    }

    if (aux->ant == NULL) {
        criadores = aux->prox;
    } else {
        aux->ant->prox = aux->prox;
    }

    if (aux->prox != NULL) {
        aux->prox->ant = aux->ant;
    }

    free(aux);

    return criadores;
}
