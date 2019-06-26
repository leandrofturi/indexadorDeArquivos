#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/leitura.h"
#include "bibliotecas/arvore.h"

#define MIN (a, b) (((a) < (b)) ? (a) : (b))
#define MAX (a, b) (((a) > (b)) ? (a) : (b))

int main ( ) {
    tEstruturas *E;
	E = inicializaEstrutura ( );
    alocaEstrutura (E, 2);
    int l = leituraArquivo ("lorem.txt", E, 2);
    imprimeEstrutura (E, 2);
    liberaEstrutura (E, 2);
    finalizaEstrutura (E);

	E = inicializaEstrutura ( );
    alocaEstrutura (E, 3);
    int m =leituraArquivo ("lorem.txt", E, 3);
    imprimeEstrutura (E, 3);
    liberaEstrutura (E, 3);
    finalizaEstrutura (E);

    return (0);
}
