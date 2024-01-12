typedef struct fazenda Fazenda;
typedef struct endereco Endereco;


Fazenda *criarListaEncadeadaCircularFazendas(); //ok
Fazenda *cadastrarFazenda(Fazenda *fazendas); //ok
Fazenda *removerFazenda(Fazenda *fazendas, int id);//nao permitir remover fazenda se houver animais cadastrados //ok
int buscarFazenda(Fazenda *fazendas); //ok
Fazenda *getFazenda(Fazenda *fazendas, int id);//ok

/*
Desenvolva funcoes que, dado uma FAZENDA, informar:
- Quantidade de animais por sexo;//ok
- Peso total em arroba (isto é, a cada 15 KG)//ok
- Valor total da fazenda considerando o preço da arroba de R$ 235//ok
- lista de animais por tipo de status// ok
- Funcao para liberar a memoria //falta
*/

void mostrarAnimalSexo(Fazenda *rebanho); 
void mostrarAnimalStatus(Fazenda *rebanho);
void arrobaTotal(Fazenda *fazendas);
void valorTotal(Fazenda *fazendas);

void liberarFazendas(Fazenda *fazendas);
