#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/leitura.h"
#include "bibliotecas/arvore.h"

int main ( ) {
    tEstruturas *E;

	E = inicializaEstrutura ( );
    alocaEstrutura (E, 5);
    int m =leituraArquivo ("lorem.txt", E, 5);
    imprimeEstrutura (E, 5);
    liberaEstrutura (E, 5);
    finalizaEstrutura (E);

    return (0);
}
