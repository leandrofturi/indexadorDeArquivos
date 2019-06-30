#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecas/leitura.h"
#include "bibliotecas/arvore.h"

int main ( ) {
    tEstruturas *E;
	E = inicializaEstrutura ( );
    alocaEstrutura (E, 4);
    int m =leituraArquivo ("numeros.txt", E, 4);
    //imprimeEstrutura (E, 4);
    liberaEstrutura (E, 4);
    finalizaEstrutura (E);

    return (0);
}
