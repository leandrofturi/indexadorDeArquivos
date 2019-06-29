#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/leitura.h"
#include "bibliotecas/arvore.h"

int main ( ) {
    tEstruturas *E;

	E = inicializaEstrutura ( );
    alocaEstrutura (E, 5);
    alocaEstrutura (E, 3);
    alocaEstrutura (E, 2);
    alocaEstrutura (E, 1);
    int m =leituraArquivo ("lorem.txt", E, 1);
    m =leituraArquivo ("lorem.txt", E, 2);
    m =leituraArquivo ("lorem.txt", E, 3);
    m =leituraArquivo ("lorem.txt", E, 5);
    imprimeEstrutura (E, 1);
    liberaEstrutura (E, 1);
    imprimeEstrutura (E, 2);
    liberaEstrutura (E, 2);
    imprimeEstrutura (E, 3);
    liberaEstrutura (E, 3);
    imprimeEstrutura (E, 5);
    liberaEstrutura (E, 5);
    finalizaEstrutura (E);

    return (0);
}
