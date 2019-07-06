#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecas/leitura.h"
#include "bibliotecas/avaliacao.h"

int main (int argc, char *argv[]) {
    if (argc < 3) {
        return (0);
    }

    int n;
    n = atoi (argv[1]);
    if (n < 0) {
        return (0);
    }
    char **caminhos;
    caminhos = (char**) malloc ((argc-2)*(sizeof (char*)));

    for (int i = 2; i < argc; i ++) {
        caminhos[i-2] = argv[i];
    }
    avaliaDesempenho (caminhos, (argc-2), n);
    free (caminhos);

    return (0);
}
