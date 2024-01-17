#include <stdio.h>
#include <stdlib.h> 

#include "animal.h"
#include "criador.h"
#include "fazenda.h"


struct animal {
	int id_animal, id_fazenda;
	char sexo; // M ou F
	float peso; // em KG
	int status; // 1 - Nascimento na própria fazenda | 2 - venda | 3 - troca 
	struct animal *prox;
};

//cria Lista de animais
Animal *criaListaEncadeadaSimplesAnimais() {
	printf("Animal Criar.");
	return NULL;
}

//Cadastra um novo animal na lista
Animal *cadastrarAnimal(Animal *rebanho) {
    Animal *novo = (Animal *)malloc(sizeof(Animal));

    printf("Informe o id do animal: ");
    scanf("%d", &novo->id_animal);

    printf("Informe o sexo do animal (M ou F): ");
    scanf(" %c", &novo->sexo);
    while (novo->sexo != 'M' && novo->sexo != 'F') {
        printf("Sexo invalido. Utilize 'M' ou 'F'.\n");
        scanf(" %c", &novo->sexo);
    }

    printf("Informe o peso do animal: ");
    scanf("%f", &novo->peso);

    printf("Informe o status do animal:\n");
    printf("1 - Nascimento na propria fazenda.\n");
    printf("2 - Venda.\n");
    printf("3 - Troca\n");
    scanf("%d", &novo->status);
    while (novo->status != 1 && novo->status != 2 && novo->status != 3) {
        printf("Status invalido. Utilize 1, 2 ou 3.\n");
        printf("Informe o status do animal:\n");
        printf("1 - Nascimento na propria fazenda.\n");
        printf("2 - Venda.\n");
        printf("3 - Troca\n");
        scanf("%d", &novo->status);
    }

    if (rebanho == NULL || rebanho->id_animal > novo->id_animal) {
        novo->prox = rebanho;
        rebanho = novo;
    } else {
        Animal *aux = rebanho;
        while (aux->prox != NULL && aux->prox->id_animal < novo->id_animal) {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    return rebanho;
}

//Busca se exitem animais na lista
Animal *buscarAnimal(Animal *rebanho)
{
	Animal *aux;
	int id;
	printf("Informe o id do animal: ");
	scanf("%d", &id);
	for(aux = rebanho ; aux != NULL ; aux = aux->prox)
	{
		if(aux->id_animal == id)
		{
			printf("---------------------------------------\n");
			printf("Id da fazenda: %d\n", rebanho->id_fazenda);
			printf("Id do animal: %d\n", rebanho->id_animal);
			printf("Sexo: %c", rebanho->sexo);
			printf("Peso: %.2f", rebanho->peso);
			if (rebanho->status == 1)
			{
				printf("Status: Nascimento na propria fazenda.\n");
			}
			if (rebanho->status == 2)
			{
				printf("Status: Vendido.\n");
			}
			if (rebanho->status == 3)
			{
				printf("Status: Troca.\n");
			}
			return aux;
		}
	}

	return NULL;
}

//Remove um animal da fazenda
Animal *removerAnimal(Fazenda *fazenda, int id_animal)
{
	Animal *remover_animal = fazenda->rebanho;
	Animal *anterior = NULL;
	while (remover_animal != NULL && remover_animal->id_animal != id_animal)
	{
		anterior = remover_animal;
		remover_animal = remover_animal->prox;
	}
	if (remover_animal == NULL)
	{
		return fazenda->rebanho;
	}
	if (anterior == NULL)
	{
		fazenda->rebanho = remover_animal->prox;
	}else
	{
		anterior->prox = remover_animal->prox;
	}
	free(remover_animal);

	return fazenda->rebanho;	
}

//faz a permuta de animais entre fazendas
Animal* permutasAnimais(Fazenda* origem, Fazenda* destino, int id_animal) {
    
}
//retorna quantos animais de cada sexo tem na fazenda
void contAnimaisSexo(Fazenda *fazenda){
	int countF = 0, countM = 0;
	Animal *aux = fazenda->rebanho; 
	while (aux) {
		if (aux->sexo == 'F') {
			countF++;
		}
		if (aux->sexo == 'M') {
			countM++;
		}
		aux = aux->prox; 
	}
	
	printf("Masculino: %d\nFeminino: %d\n", countM, countF);
}
//mostra o status do anima,de qual fazenda ele e ,peso,sexo e etc
void MostrarStatus(Fazenda *fazenda, int sts) {
    Animal *aux = fazenda->rebanho;
    while (aux) {
        if (aux->status == sts) {
            printf("---------------------------------------\n");
            printf("Id da fazenda: %d\n", fazenda->id_fazenda);
            printf("Id do animal: %d\n", aux->id_animal);
            printf("Sexo: %c\n", aux->sexo);
            printf("Peso: %.2f\n", aux->peso);
        }

        aux = aux->prox;
    }
}

//calcula quantos arrobas os animais daquela fazwnda tem
int contArroba(Fazenda *fazenda){
	float soma=0;
	Animal *aux = fazenda->rebanho;
	while(aux){

		soma += aux->peso;

		aux = aux->prox;
	}
	return soma/15;
}


//Libera a lista animal
void liberarRebanho(struct animal* rebanho) {
    struct animal* atual = rebanho;
    struct animal* proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

