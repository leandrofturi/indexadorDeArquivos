#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/leitura.h"


int leituraArquivo (char *caminhoArq, tEstruturas *E, int estrutura) {
    int nC, nP;
    char c, palavraMax[189819];
    FILE *arq;

    arq = fopen (caminhoArq, "r");
    if ((arq == NULL) ||
        (estrutura < 1) || (estrutura > 5)) {
        return (1);
    }
    else {
        nC = nP = 0;
        while ((c = fgetc (arq)) != EOF) {
		nP ++;
            if (((c >= 'a') && (c <= 'z')) ||
                ((c >= 'A') && (c <= 'Z')) ||
                ((c >= '0') && (c <= '9'))) {
                palavraMax[nC] = c;
                nC ++;
            }
            else if (nC > 0) {
                palavraMax[nC] = '\0';
                nC = 0;
                insereEstrutura (palavraMax, nP, E, estrutura);
            }
        }
    }
    fclose (arq);

    return (0);
}

tPalavra *criaPalavra (char *palavra, int posicao) {
    tPalavra *P;
    P = (tPalavra*) malloc (sizeof (tPalavra));
    P->palavra = (char*) malloc ((strlen (palavra) + 1) * sizeof (char));
    strcpy (P->palavra, palavra);
    P->posicao = (int*) malloc (sizeof (int));
    P->posicao[0] = posicao;
    P->ocorrencias = 1;

    return (P);
}

void liberaPalavra (tPalavra *P) {
    free (P->palavra);
    free (P->posicao);
    free (P);
}

void colocaPosicao (int novaPosicao, tPalavra *P) {
    int *nova;
    nova = (int*) malloc ((P->ocorrencias + 1) * sizeof (int));
    for (int i = 0; i < P->ocorrencias; i ++) {
        nova[i] = P->posicao[i];
    }
    nova[P->ocorrencias] = novaPosicao;
    free (P->posicao);
    P->posicao = nova;
    P->ocorrencias ++;
}

tEstruturas *inicializaEstrutura ( ) {
    tEstruturas *E;
    E = (tEstruturas*) malloc (sizeof (tEstruturas));
    for (int i = 0; i < 5; i ++) {
        E->alocados[i] = 0;
    }
    return (E);
}

void alocaEstrutura (tEstruturas *E, int estrutura) {
    if (E->alocados[(estrutura-1)] != 1) {
        switch (estrutura) {
            case 1:                                                             // Lista encadeada

            break;

            case 2:                                                             // Arvore binaria nao balanceada
                E->arvore = criaArvore ( );
                E->alocados[estrutura-1] = 1;
            break;

            case 3:                                                             // Arvore binaria balanceada (AVL)

            break;

            case 4:                                                             // Arvores de prefixo (TRIE)

            break;

            case 5:                                                             // Tabela Hash

            break;
        }
    }
}

void liberaEstrutura (tEstruturas *E, int estrutura) {
    if (E->alocados[estrutura-1] == 1) {
        switch (estrutura) {
            case 1:                                                             // Lista encadeada

            break;

            case 2:                                                             // Arvore binaria nao balanceada
                liberaArvore (E->arvore);
                E->alocados[estrutura-1] = 0;
            break;

            case 3:                                                             // Arvore binaria balanceada (AVL)

            break;

            case 4:                                                             // Arvores de prefixo (TRIE)

            break;

            case 5:                                                             // Tabela Hash

            break;
        }
    }
}

void insereEstrutura (char *palavra, int posicao, tEstruturas *E, int estrutura) {
    switch (estrutura) {
        case 1:                                                                 // Lista encadeada

        break;

        case 2:                                                                 // Arvore binaria nao balanceada
            insereArvore (palavra, posicao, E->arvore);
        break;

        case 3:                                                                 // Arvore binaria balanceada (AVL)

        break;

        case 4:                                                                 // Arvores de prefixo (TRIE)

        break;

        case 5:                                                                 // Tabela Hash

        break;
    }
}

void imprimeEstrutura (tEstruturas *E, int estrutura) {
    switch (estrutura) {
        case 1:                                                                 // Lista encadeada

        break;

        case 2:                                                                 // Arvore binaria nao balanceada
            imprimeArvore (E->arvore);
        break;

        case 3:                                                                 // Arvore binaria balanceada (AVL)

        break;

        case 4:                                                                 // Arvores de prefixo (TRIE)

        break;

        case 5:                                                                 // Tabela Hash

        break;
    }
}

void finalizaEstrutura (tEstruturas *E) {
    for (int i = 0; i < 5; i ++) {
        if (E->alocados[i] == 1) {
            liberaEstrutura (E, i + 1);
        }
    }
    free (E);
}
