typedef struct criador Criador;

Criador *criarListaDuplaCriadores(); //ok
Criador *cadastrarCriador(Criador *criadores);// ok
Criador *removerCriador(Criador *criadores); // nao é permitido remover criador com fazendas cadastradas //ok
Criador *buscarCriador(Criador *criadores); //ok
void mostrarCriadores(Criador *criadores); //ok
void liberarCriadores(Criador *criadores); //falta
/*
Desenvolva funçoes para:
- Retornar o patrimonio do criador (esse valor deve sempre estar atualizado)
- Funcao para mostrar cada criador e todos os seus respectivos atributos
- Funcao para liberar a memoria
*/
