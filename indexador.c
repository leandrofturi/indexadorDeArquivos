#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecas/leitura.h"

int main (int argc, char *argv[]) {
    int m;
    char *caminho;

    tEstruturas *E;
	E = inicializaEstrutura ( );

    if (argc < 1) {
        return (0);
    }
    for (int i = 1; i < argc; i ++) {
        caminho = argv[i];

        if (caminho == NULL) {
            printf ("ERRO! Arquivo não encontrado!\n");
            return (0);
        }
        /*
        alocaEstrutura (E, 1);
        m = leituraArquivo (caminho, E, 1);
        //imprimeEstrutura (E, 1);
        liberaEstrutura (E, 1);

        alocaEstrutura (E, 2);
        m = leituraArquivo (caminho, E, 2);
        //imprimeEstrutura (E, 2);
        liberaEstrutura (E, 2);

        alocaEstrutura (E, 3);
        m = leituraArquivo (caminho, E, 3);
        //imprimeEstrutura (E, 3);
        liberaEstrutura (E, 3);

        alocaEstrutura (E, 4);
        m = leituraArquivo (caminho, E, 4);
        //imprimeEstrutura (E, 4);
        liberaEstrutura (E, 4);
*/
        alocaEstrutura (E, 5);
        m = leituraArquivo (caminho, E, 5);
        m = buscaPalavraEstrutura (E, 5, "Lorem");
        m = buscaPalavraEstrutura (E, 5, "Holy");
        //imprimeEstrutura (E, 5);
        liberaEstrutura (E, 5);
    }
    finalizaEstrutura (E);

    return (0);
}
