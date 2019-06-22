#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/leitura.h"
#include "bibliotecas/arvore.h"

int main ( ) {
    tEstruturas *E = inicializaEstrutura ( );
    alocaEstrutura (E, 2);
    int l = leituraArquivo ("lorem.txt", E, 2);
    imprimeEstrutura (E, 2);
    liberaEstrutura (E, 2);
    finalizaEstrutura (E);
    return (0);
}
