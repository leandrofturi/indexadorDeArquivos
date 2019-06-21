#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/leitura.h"
#include "../bibliotecas/arvore.h"

int leituraArquivo (char *caminhoArq, int estrutura) {
    int nC, nP;
    char c, palavraMax[189819];
    FILE *arq;
    tArvore *A;
    A = criaArvore ( );

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
                switch (estrutura) {
                    case 1:                                                     // Lista encadeada

                    break;

                    case 2:                                                     // Arvore binaria nao balanceada
                        insereArvore (palavraMax, nP, A);
                    break;

                    case 3:                                                     // Arvore binaria balanceada (AVL)

                    break;

                    case 4:                                                     // Arvores de prefixo (TRIE)

                    break;

                    case 5:                                                     // Tabela Hash

                    break;
                }
            }
        }
    }

    fclose (arq);
    imprimeArvore (A);
    liberaArvore (A);
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
