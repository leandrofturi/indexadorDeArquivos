#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/leitura.h"
#include "bibliotecas/arvore.h"

int main ( ) {
    tEstruturas *E;

	E = inicializaEstrutura ( );
    alocaEstrutura (E, 3);
    int m =leituraArquivo ("numeros.txt", E, 3);
    imprimeEstrutura (E, 3);
    liberaEstrutura (E, 3);
    finalizaEstrutura (E);

    return (0);
}
