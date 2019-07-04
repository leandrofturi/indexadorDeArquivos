#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "../bibliotecas/avaliacao.h"

char **buscaPalavrasAleatorias (char **caminhosArq, int qtd, int *n) {
    int nC, nP, i, posicoes[(*n)];
    char c, palavraMax[46];
    char **encontradas;
    FILE *arquivo;

    struct timeval semente;
    gettimeofday (&semente, NULL);
    srand ((int) (semente.tv_sec + 1000000 * semente.tv_usec));
    for (i = 0; i < (*n); i ++) {
        posicoes[i] = (rand ( )) % 100000;
    }

    i = 0;
    for (int j = 0; j < qtd; j ++) {
        arquivo = fopen (caminhosArq[i], "r");
        nC = nP = 0;
        encontradas = (char**) malloc ((*n) * sizeof (char*));
        while ((c = fgetc (arquivo)) != EOF) {
            nP ++;
            if (((c >= 'a') && (c <= 'z')) ||
                ((c >= 'A') && (c <= 'Z')) ||
                ((c >= '0') && (c <= '9'))) {
                palavraMax[nC] = c;
                nC ++;
            }
            else if (nC > 0) {
                palavraMax[nC] = '\0';
                if (nP == posicoes[i]) {
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
        (*n) = i + 1;
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
    double tempoCarregamento[5], tempoBusca[5];

    tEstruturas *E;
	E = inicializaEstrutura ( );

    if (qtd < 1) {
        return;
    }

    alocaEstrutura (E, 1);
    alocaEstrutura (E, 2);
    alocaEstrutura (E, 3);
    alocaEstrutura (E, 4);
    alocaEstrutura (E, 5);

    for (int i = 0; i < qtd; i ++) {
        if (caminhosArq[i] == NULL) {
            printf ("ERRO! Arquivo não encontrado!\n");
            return;
        }

        for (int j = 0; j < 5; j ++) {
            t = clock ( );
            leitura[i] = leituraArquivo (caminhosArq[i], i, E, j);
            t = clock ( ) - t;
            tempoCarregamento[i] = ((double) t) / CLOCKS_PER_SEC;

            if (leitura[j]) {
                tempoCarregamento[j] = 0;
            }
        }
    }

    palavras = buscaPalavrasAleatorias (caminhosArq, qtd, &n);

    for (int i = 0; i < 5; i ++) {
        t = clock ( );
        buscaPalavraAnalise (E, i, palavras, n);
        t = clock ( ) - t;
        tempoBusca[i] = ((double) t) / CLOCKS_PER_SEC;
    }

    for (int i = 0; i < n; i ++) {
        //free (palavras[i]);
    }
    free (palavras);

    liberaEstrutura (E, 1);
    liberaEstrutura (E, 2);
    liberaEstrutura (E, 3);
    liberaEstrutura (E, 4);
    liberaEstrutura (E, 5);
    finalizaEstrutura (E);

    for (int i = 0; i < 5; i ++) {
        printf("%.f %f\n", tempoBusca[i], tempoCarregamento[i]);
    }
}
