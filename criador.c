#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "criador.h"
#include "fazenda.h"
#include "fazenda.c"
#include "animal.h"
#include "animal.c"
// #include "fazenda.c"

struct criador
{
	int id_criador;
	char nome[100];
	Fazenda *fazendas;// Esse ponteiro e uma lista circular (atentem-se)
	float patrimonio; // esse valor deve ser constantemente modificado para que o valor esteja atualizado
	struct criador *prox, *ant; // lista dupla encadeada, nao é necessário ser circular
};

Criador *criarListaDuplaCriadores(){
	return NULL;
}
Criador *cadastrarCriador(Criador *criadores) {
    Criador *novo = (Criador*)malloc(sizeof(Criador));
    printf("Informe o ID do criador: ");
    scanf("%d", &novo->id_criador);
    printf("Informe o nome do criador: ");
    scanf("%s", novo->nome);
    novo->ant = NULL;
    novo->prox = NULL;

    if (criadores == NULL || criadores->id_criador > novo->id_criador) {
        novo->prox = criadores;
        if (criadores != NULL) {
            criadores->ant = novo;
        }
        criadores = novo;
    } else {
        Criador *aux = criadores;
        while (aux->prox != NULL && aux->prox->id_criador < novo->id_criador) {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        if (aux->prox != NULL) {
            aux->prox->ant = novo;
        }
        aux->prox = novo;
        novo->ant = aux;
    }

    return criadores;
}


int size(Criador *c){
	Criador *aux;
	int count = 0;

	aux = c;
	while(aux){
		count++;
		aux = aux->prox;
	}

	return count;
}

Criador *buscarCriador(Criador *criadores){
	Criador *aux = criadores;
	int id;
	printf("Informe o id do criador: ");
	scanf("%d", &id);

	while(aux){
		if(id == aux->id_criador){
			printf("Criador encontrado.\n");
			return aux;
		}

		aux = aux->prox;
	}

	printf("Criador nao encontrado.\n");
	return NULL;
}

int temFazenda(Fazenda *fazenda){
	if(fazenda){
		return 1;
	}

	return 0;
}

void mostrarCriadores(Criador *criadores) {
    Criador *aux = criadores;  

    printf("\nLista de Criadores:\n");
    while (aux != NULL) {
        printf("ID: %d\n", aux->id_criador);
        printf("Nome: %s\n", aux->nome);
        printf("--------------------\n");
        aux = aux->prox;
    }
}

Criador *removerCriador(Criador *criadores) {
    Criador *aux = buscarCriador(criadores);

    if (aux == NULL) {
        printf("Criador nao encontrado.\n");
        return criadores;
    }

    if (temFazenda(aux->fazendas) != 0) {
        printf("Nao eh possivel excluir esse criador, pois possui fazendas.\n");
        return criadores;
    }

    if (aux->ant != NULL) {
        aux->ant->prox = aux->prox;
    } else {
        criadores = aux->prox;
    }

    if (aux->prox != NULL) {
        aux->prox->ant = aux->ant;
    }

    free(aux);
    printf("Criador removido com sucesso.\n");

    return criadores;
}

void liberarMemoria(Criador *criadores) {
    Criador *aux = criadores;
    Criador *prox;
    while (aux != NULL) {
        liberarFazendas(aux->fazendas);
        prox = aux->prox;
        free(aux);
        aux = prox;
    }
}
