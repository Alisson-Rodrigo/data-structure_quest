typedef struct animal Animal; 

Animal *criaListaEncadeadaSimplesAnimais(); //ok
Animal *cadastrarAnimal(Animal *rebanho); //ok
Animal *buscarAnimal(Animal *rebanho); //ok
//void mostrarAnimalSexo(Animal *rebanho);
//Animal *mostrarAnimalStatus(Animal *rebanho);
//void mostrarAnimalStatus(Animal *rebanho);
Animal *removerAnimal(Fazenda *fazenda, int id_animal);// ok

Animal *permutasAnimais(Fazenda *origem, Fazenda *destino, int id_animal);//obervar para atualizar o status do animal na fazenda de destino //ok
Animal *removerAnimal(Fazenda *fazenda, int id_animal); //ok
/*
Desenvolva funcoes que:

- Funcao para liberar a memoria
*/
void contAnimaisSexo(Fazenda *fazenda);//ok
void MostrarStatus(Fazenda *fazenda, int sts);//ok
int contArroba(Fazenda *fazenda);//ok

