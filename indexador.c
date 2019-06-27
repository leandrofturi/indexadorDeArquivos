#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/leitura.h"
#include "bibliotecas/arvore.h"

int main ( ) {
    tEstruturas *E;

	E = inicializaEstrutura ( );
    alocaEstrutura (E, 1);
    int m =leituraArquivo ("lorem.txt", E, 1);
    imprimeEstrutura (E, 1);
    liberaEstrutura (E, 1);
    finalizaEstrutura (E);

    return (0);
}
