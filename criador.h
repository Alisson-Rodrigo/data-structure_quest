typedef struct criador Criador;

Criador *criarListaDuplaCriadores(); //ok
Criador *cadastrarCriador(Criador *criadores);// ok
Criador *removerCriador(Criador *criadores); // nao é permitido remover criador com fazendas cadastradas //ok
Criador *buscarCriador(Criador *criadores); //ok
void mostrarCriadores(Criador *criadores); //ok
void liberarCriadores(Criador *criadores); //falta
void patrimonioTotal(Criador *criador);
float calculaPpatrimonioTotal(Criador *criador);
/*
Desenvolva funçoes para:
- Retornar o patrimonio do criador (esse valor deve sempre estar atualizado) //ok
- Funcao para mostrar cada criador e todos os seus respectivos atributos //ok
- Funcao para liberar a memoria //feito
*/
