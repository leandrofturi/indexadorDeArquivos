#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/palavra.h"

tPalavra *criaPalavra (char *palavra, int posicao, int arq) {
    tPalavra *P;
    P = (tPalavra*) malloc (sizeof (tPalavra));
    P->palavra = (char*) malloc ((strlen (palavra) + 1) * sizeof (char));
    strcpy (P->palavra, palavra);
    P->arq = (tArquivo*) malloc (sizeof (tArquivo));
    P->n = 1;

    P->arq[0].posicao = (int*) malloc (sizeof (int));
    P->arq[0].posicao[0] = posicao;
    P->arq[0].ocorrencias = 1;

    return (P);
}

void liberaPalavra (tPalavra *P) {
    if (P == NULL) {
        return;
    }
    free (P->palavra);
    for (int i = 0; i < P->n; i ++) {
        free (P->arq[i].posicao);
    }
    free (P->arq);
    free (P);
}

void colocaPosicao (int posicao, int arq, tPalavra *P) {
    if (P == NULL) {
        return;
    }
    if ((arq < 0) || (arq > P->n)) {
        return;
    }
    if ((arq == P->n) && (arq > 0)) {
        adicionaArquivo (P);
    }
    int *nova;
    nova = (int*) malloc ((P->arq[arq].ocorrencias + 1) * sizeof (int));
    for (int i = 0; i < P->arq[arq].ocorrencias; i ++) {
        nova[i] = P->arq[arq].posicao[i];
    }
    nova[P->arq[arq].ocorrencias] = posicao;
    free (P->arq[arq].posicao);
    P->arq[arq].posicao = nova;
    P->arq[arq].ocorrencias ++;
}

void adicionaArquivo (tPalavra *P) {
    if (P == NULL) {
        return;
    }
    tArquivo *novo;
    novo = (tArquivo*) malloc ((P->n + 1) * sizeof (tArquivo));
    for (int i = 0; i < P->n; i ++) {
        novo[i] = P->arq[i];
    }
    free (P->arq);
    P->arq = novo;
    P->n ++;
}

void imprimePalavra (tPalavra *P) {
    printf ("%s ", P->palavra);
}

void imprimeBusca (tPalavra *P, char *palavra, char **arqs) {
    if (P == NULL) {
        printf ("\n################################################\n");
        printf("%s", palavra);
        printf ("\n################################################\n");
        printf ("PALAVRA NÃO ENCONTRADA!\n\n");
        return;
    }
    printf ("\n################################################\n");
    imprimePalavra (P);
    for (int i = 0; i < P->n; i ++) {
        printf ("\n################################################\n");
        printf ("%s\n", arqs[i]);
        printf ("\n");
        printf ("QUANTIDADE DE OCORRENCIAS: %d\n", P->arq[i].ocorrencias);
        if (P->arq[i].ocorrencias > 0) {
            printf ("POSICOES: ");
            for (int j = 0; j < P->arq[i].ocorrencias; j ++) {
                printf("%d ", P->arq[i].posicao[j]);
            }
        }
        printf ("\n\n");
    }
}
