typedef struct animal Animal;

Animal *criaListaEncadeadaSimplesAnimais(); // ok
Animal *cadastrarAnimal(Animal *rebanho);   // ok
Animal *buscarAnimal(Animal *rebanho);      // ok

Animal *removerAnimal(Fazenda *fazenda, int id_animal); // ok

Animal *permutasAnimais(Fazenda *origem, Fazenda *destino, int id_animal); // obervar para atualizar o status do animal na fazenda de destino //ok
Animal *removerAnimal(Fazenda *fazenda, int id_animal);                    // ok

void contAnimaisSexo(Fazenda *fazenda);        // ok
void MostrarStatus(Fazenda *fazenda, int sts); // ok
int contArroba(Fazenda *fazenda);              // ok
void liberarRebanho(Animal *rebanho);

/*
Desenvolva funcoes que:

- Funcao para liberar a memoria
*/
