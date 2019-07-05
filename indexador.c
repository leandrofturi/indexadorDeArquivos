#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecas/leitura.h"
#include "bibliotecas/avaliacao.h"

int main (int argc, char *argv[]) {
    if (argc < 3) {
        return (0);
    }

    char **caminhos;
    caminhos = (char**) malloc ((argc-1)*(sizeof (char*)));

    for (int i = 2; i < argc; i ++) {
        caminhos[i-2] = argv[i];
    }
    //avaliaDesempenho (caminhos, (argc-2), *(argv[1]));
    tEstruturas *E;

    E = inicializaEstrutura ( );

    alocaEstrutura (E, 1);
    alocaEstrutura (E, 2);
    alocaEstrutura (E, 3);
    alocaEstrutura (E, 4);
    alocaEstrutura (E, 5);

int m = leituraArquivo (caminhos[0], 1, E, 1);
    m = leituraArquivo (caminhos[1], 2, E, 1);
    free (caminhos);

    liberaEstrutura (E, 1);
    liberaEstrutura (E, 2);
    liberaEstrutura (E, 3);
    liberaEstrutura (E, 4);
    liberaEstrutura (E, 5);

    finalizaEstrutura (E);

    return (0);
}
