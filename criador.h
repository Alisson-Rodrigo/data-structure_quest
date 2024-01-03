typedef struct criador Criador;

Criador *criarListaDuplaCriadores();
Criador *cadastrar(Criador *criadores);
Criador *remover(Criador *criadores, int id);//nao é permitido remover criador com fazendas cadastradas
int buscar(Criador *criadores);

/*
Desenvolva funçoes para:
- Retornar o patrimonio do criador (esse valor deve sempre estar atualizado)
- Funcao para mostrar cada criador e todos os seus respectivos atributos
- Funcao para liberar a memoria
*/