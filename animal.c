#include <stdio.h>
#include <stdlib.h>

#include "animal.h"

struct animal{
	int id_animal, id_fazenda;
	char sexo; // M ou F
	float peso; //em KG
	int status; // 1 - Nascimento na propria fazenda | 2 - venda | 3 - troca 
	struct animal *prox;
};


Animal *criaListaEncadeadaSimplesAnimais(){
	return NULL;
}


Animal *cadastrar(Animal *rebanho){

	Animal *novo = (Animal *) malloc(sizeof(Animal));
	if (novo == NULL) {
		printf("Erro ao alocar memoria\n");
		exit(1);
	}

	printf("Digite o id: ");
	scanf("%d",&novo->id_animal);
	printf("Digite o id da fazenda: ");
	scanf("%d",&novo->id_fazenda);
	printf("Digite o sexo: ");
	scanf("%c",&novo->sexo);
	printf("Digite o peso: ");
	scanf("%f",&novo->peso);
	printf("Digite o status: ");
	scanf("%d",&novo->status);

	if (rebanho == NULL || rebanho->id_animal > novo->id_animal){
		novo->prox = rebanho;
		rebanho = novo;
	} else{
		Animal *aux = rebanho;
		while (aux->prox != NULL && aux->prox->id_animal < novo->id_animal){
			aux = aux->prox;
		}
		novo->prox = aux->prox;
		aux->prox = novo;
	}

	return rebanho;
}