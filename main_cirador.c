#include <stdio.h>
#include "criador.c"

int main() {
    Criador *criadores = criarListaDuplaCriadores();

    criadores = cadastrar(criadores);
    imprimir(criadores);

    return 0;
}
