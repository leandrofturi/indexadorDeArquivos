#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "../bibliotecas/avaliacao.h"

char **buscaPalavrasAleatorias (char **caminhosArq, int qtd, int *n) {
    int nC, i;
    char c, palavraMax[PALAVRAMAX];
    char **encontradas;
    FILE *arquivo;

    struct timeval semente;
    gettimeofday (&semente, NULL);
    srand ((int) (semente.tv_sec + 1000000 * semente.tv_usec));

    i = 0;
    for (int j = 0; j < qtd; j ++) {
        arquivo = fopen (caminhosArq[i], "r");
        nC = 0;
        encontradas = (char**) malloc ((*n) * sizeof (char*));
        while ((c = fgetc (arquivo)) != EOF) {
            if (((c >= 'a') && (c <= 'z')) ||
                ((c >= 'A') && (c <= 'Z')) ||
                ((c >= '0') && (c <= '9'))) {
                palavraMax[nC] = c;
                nC ++;
            }
            else if (nC > 0) {
                palavraMax[nC] = '\0';
                if (((rand ( )) % 100) < PROBABILIDADE) {
                    encontradas[i] = (char*) malloc ((nC+1) * sizeof (char));
                    strcpy (encontradas[i], palavraMax);
                    i ++;
                    if (i == ((*n)-1)) {
                        return (encontradas);
                    }
                }
                nC = 0;
            }
        }
        fclose (arquivo);
    }

    if (i < (*n)) {
        (*n) = i;
    }
    return (encontradas);
}

void buscaPalavraAnalise (tEstruturas *E, int estrutura, char **palavras, int n) {
    tPalavra *P;
    switch (estrutura) {
        case 1:                                                                 // Lista encadeada
            for (int i = 0; i < n; i ++) {
                P = buscaPalavraEncadeada (palavras[i], E->encadeada);
            }
        break;

        case 2:                                                                 // Arvore binaria nao balanceada
            for (int i = 0; i < n; i ++) {
                P = buscaPalavraArvore (palavras[i], E->arvore);
            }
        break;

        case 3:                                                                 // Arvore binaria balanceada (AVL)
            for (int i = 0; i < n; i ++) {
                P = buscaPalavraArvore (palavras[i], E->balanceada);
            }
        break;

        case 4:                                                                 // Arvores de prefixo (TRIE)
            for (int i = 0; i < n; i ++) {
                P = buscaPalavraTrie (palavras[i], E->trie);
            }
        break;

        case 5:                                                                 // Tabela Hash
            for (int i = 0; i < n; i ++) {
                P = buscaPalavraHash (palavras[i], E->hash);
            }
        break;
    }
    return;
}

void avaliaDesempenho (char **caminhosArq, int qtd, int n) {
    int leitura[5];
    char **palavras;
    clock_t t;
    double tempoCarregamento[qtd][5], tempoBusca[5];
    tEstruturas *E;

    if (qtd < 0) {
        return;
    }

    E = inicializaEstrutura ( );

    alocaEstrutura (E, 1);
    alocaEstrutura (E, 2);
    alocaEstrutura (E, 3);
    alocaEstrutura (E, 4);
    alocaEstrutura (E, 5);

    for (int i = 0; i < qtd; i ++) {
        for (int j = 1; j <= 5; j ++) {
            t = clock ( );
            leitura[j-1] = leituraArquivo (caminhosArq[i], i, E, j);
            t = clock ( ) - t;
            tempoCarregamento[i][j-1] = ((double) t) / CLOCKS_PER_SEC;
            if (leitura[j-1]) {
                tempoCarregamento[i][j-1] = 0;
            }
        }
    }
    /*
    palavras = buscaPalavrasAleatorias (caminhosArq, qtd, &n);

    for (int i = 1; i <= 5; i ++) {
        t = clock ( );
        buscaPalavraAnalise (E, i, palavras, n);
        t = clock ( ) - t;
        tempoBusca[i] = ((double) t) / CLOCKS_PER_SEC;
        if (tempoBusca[i]) {
            tempoBusca[i] = 0;
        }
    }

    for (int i = 0; i < n; i ++) {
        free (palavras[i]);
    }
    free (palavras);
    */
    liberaEstrutura (E, 1);
    liberaEstrutura (E, 2);
    liberaEstrutura (E, 3);
    liberaEstrutura (E, 4);
    liberaEstrutura (E, 5);

    finalizaEstrutura (E);

    //for (int i = 0; i < 5; i ++) {
    //    printf ("%f %f\n", tempoBusca[i], tempoCarregamento[i]);
    //}
}
