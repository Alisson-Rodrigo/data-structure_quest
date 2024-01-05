typedef struct animal Animal;

Animal *criaListaEncadeadaSimplesAnimais();
Animal *cadastrar(Animal *rebanho);
//Animal *permutasAnimais(Fazenda *origem, Fazenda *destino, int id_animal);//obervar para atualizar o status do animal na fazenda de destino
//Animal *remover(Fazenda *fazenda, int id_animal);
void imprimir(Animal *rebanho);
void liberar(Animal *rebanho);

/*
Desenvolva funcoes que:

- Funcao para liberar a memoria
*/