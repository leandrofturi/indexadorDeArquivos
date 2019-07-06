#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/palavra.h"

tPalavra *criaPalavra (char *palavra, int posicao, int arq) {
    tPalavra *P;
    P = (tPalavra*) malloc (sizeof (tPalavra));
    P->palavra = (char*) malloc ((strlen (palavra) + 1) * (sizeof (char)));
    P->arq = (tArquivo*) malloc (sizeof (tArquivo));
    strcpy (P->palavra, palavra);
    P->qtd = 1;

    P->arq[0].posicao = (int*) malloc (sizeof (int));
    P->arq[0].id = arq;
    P->arq[0].posicao[0] = posicao;
    P->arq[0].ocorrencias = 1;

    return (P);
}

void liberaPalavra (tPalavra *P) {
    if (P == NULL) {
        return;
    }
    free (P->palavra);
    for (int i = 0; i < P->qtd; i ++) {
        free (P->arq[i].posicao);
    }
    free (P->arq);
    free (P);
}

void colocaPosicao (int posicao, int arq, tPalavra *P) {
    if (P == NULL) {
        return;
    }
    for (int i = 0; i < P->qtd; i ++) {
        if (P->arq[i].id == arq) {
            int *nova;
            nova = (int*) malloc ((P->arq[i].ocorrencias + 1) * sizeof (int));
            for (int j = 0; j < P->arq[i].ocorrencias; j ++) {
                nova[j] = P->arq[i].posicao[j];
            }
            nova[P->arq[i].ocorrencias] = posicao;
            free (P->arq[i].posicao);
            P->arq[i].posicao = nova;
            P->arq[i].ocorrencias ++;

            return;
        }
    }
    adicionaArquivo (posicao, arq, P);
}

void adicionaArquivo (int posicao, int arq, tPalavra *P) {
    if (P == NULL) {
        return;
    }
    tArquivo *novo;
    novo = (tArquivo*) malloc ((P->qtd + 1) * sizeof (tArquivo));
    for (int i = 0; i < P->qtd; i ++) {
        novo[i] = P->arq[i];
    }
    novo[P->qtd].posicao = (int*) malloc (sizeof (int));
    novo[P->qtd].posicao[0] = posicao;
    novo[P->qtd].ocorrencias = 1;
    novo[P->qtd].id = arq;

    free (P->arq);
    P->arq = novo;
    P->qtd ++;
}

void imprimePalavra (tPalavra *P) {
    printf ("%s ", P->palavra);
}

void imprimeBusca (tPalavra *P, char *palavra, char **arqs, int n) {
    if (P == NULL) {
        printf ("\n################################################\n");
        printf("%s", palavra);
        printf ("\n################################################\n");
        printf ("PALAVRA NÃO ENCONTRADA!\n\n");
        return;
    }
    printf ("\n################################################\n");
    imprimePalavra (P);
    for (int i = 0; i < n; i ++) {
        printf ("\n################################################\n");
        for (int j = 0; j < P->qtd; j ++) {
            if (P->arq[j].id == arqs[i]) {
                printf ("%s\n", arqs[i]);
                printf ("\n");
                printf ("QUANTIDADE DE OCORRENCIAS: %d\n", P->arq[i].ocorrencias);
                if (P->arq[i].ocorrencias > 0) {
                    printf ("POSICOES: ");
                    for (int k = 0; k < P->arq[i].ocorrencias; k ++) {
                        printf("%d ", P->arq[i].posicao[k]);
                    }
                }
                printf ("\n\n");
            }
        }
    }
}
