#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecas/leitura.h"
#include "bibliotecas/avaliacao.h"

int main (int argc, char *argv[]) {
    int n;
    char **caminhos;

    n = 20;
    caminhos = (char**) malloc (sizeof (char*));
    caminhos[0] = "lorem.txt";
    avaliaDesempenho (caminhos, 1, n);

    //free (*caminhos);
    /*
    if (argc < 1) {
        return (0);
    }


    caminhos = (char**) malloc ((argc-2) * sizeof (char*));
    n = *(argv[1]);
    for (int i = 0; i < (argc-2); i ++) {
        caminhos[i] = (char*) malloc (((strlen (argv[i+2]))+1)*(sizeof (char)));
        printf("%s\n", caminhos[i]);
        strcpy (caminhos[i], argv[i+2]);
    }
    avaliaDesempenho (caminhos, (argc-2), n);
    free (caminhos);
    */
    //buscaPalavra (argv[argc-1]);

    return (0);
}
