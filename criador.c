#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "criador.h"
#include "fazenda.h"
#include "fazenda.c"
#include "animal.h"
#include "animal.c"


struct criador
{
	int id_criador;
	char nome[100];
	Fazenda *fazendas;// Esse ponteiro e uma lista circular (atentem-se)
	float patrimonio; // esse valor deve ser constantemente modificado para que o valor esteja atualizado
	struct criador *prox, *ant; // lista dupla encadeada, nao é necessário ser circular
};


//Cria lista de  criadores
Criador *criarListaDuplaCriadores(){
	return NULL;
}

//Cadastra um novo criador
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

//Retorna o numero de criadores na lista
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

//Verfica se tem criadores na lista
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
//verifica se existem fazendas
int temFazenda(Fazenda *fazenda){
	if(fazenda){
		return 1;
	}

	return 0;
}


//exibe os atributos dos criadores
void mostrarCriadores(Criador *criadores) {
    Criador *auxCriador = criadores;

    if (criadores == NULL) {
        printf("Lista de criadores vazia.\n");
        return;
    }

    printf("\n** Dados dos Criadores **\n");

    while (auxCriador != NULL) {
        printf("********************************************\n");
        printf("ID: %d\n", auxCriador->id_criador);
        printf("Nome: %s\n", auxCriador->nome);

      
        if (auxCriador->fazendas != NULL) {
            printf("Fazendas: ");
            
            Fazenda *auxFazenda = auxCriador->fazendas;
            do {
                printf("%d ", auxFazenda->id_fazenda);

                auxFazenda = auxFazenda->prox;
            } while (auxFazenda != auxCriador->fazendas);

            printf("\n");
        }

        auxCriador = auxCriador->prox;
    }

    printf("********************************************\n");
}

//remove o criador
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


//calcula o patrinmonio total do criador
float calculaPatrimonioTotal(Criador *criador) {
    float patrimonioFazendas = 0.0;

   
    if (temFazenda(criador->fazendas)) {
        Fazenda *auxFazenda = criador->fazendas;

      
        do {
            
            patrimonioFazendas += contArroba(auxFazenda) * 267.5;

            auxFazenda = auxFazenda->prox;
        } while (auxFazenda != criador->fazendas);
    }


    printf("Patrimonio Total do Criador %s: %.2f\n", criador->nome, patrimonioFazendas);

  
    return patrimonioFazendas;
}

//percorre a lista de criadores e aplica o calculo para cada criador exixtente na lista
void patrimonioTotal(Criador *criadores) {
    Criador *auxCriador = criadores;

  
    while (auxCriador != NULL) {
        
        calculaPatrimonioTotal(auxCriador);

        auxCriador = auxCriador->prox;
    }
}

//libera a lista de criadores
void liberarCriadores(Criador* criadores) {
    Criador* aux = criadores;
    Criador* prox;

    while (aux != NULL) {
      
        liberarFazenda(aux->fazendas);

      
        prox = aux->prox;

       
        free(aux);

      
        aux = prox;
    }
}
