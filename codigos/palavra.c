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
    P->qtd = 1;

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
    if ((arq < 1) || (arq > ((P->qtd)+1))) {
        return;
    }
    if ((arq > P->qtd)) {
        adicionaArquivo (posicao, P);
        return;
    }
    else {
        int *nova;
        nova = (int*) malloc ((P->arq[arq-1].ocorrencias + 1) * sizeof (int));
        for (int i = 0; i < P->arq[arq-1].ocorrencias; i ++) {
            nova[i] = P->arq[arq-1].posicao[i];
            printf("%d: ", arq-1);
            printf("%d\n", nova[i]);
        }
        nova[P->arq[arq-1].ocorrencias] = posicao;
        free (P->arq[arq-1].posicao);
        P->arq[arq-1].posicao = nova;
        P->arq[arq-1].ocorrencias ++;
    }
}

void adicionaArquivo (int posicao, tPalavra *P) {
    if (P == NULL) {
        return;
    }
    tArquivo *novo;
    novo = (tArquivo*) malloc ((P->qtd + 1) * sizeof (tArquivo));
    for (int i = 0; i < P->qtd; i ++) {
        novo[i] = P->arq[i];
    }
    free (P->arq);
    P->arq = novo;
    P->qtd ++;

    P->arq[P->qtd].posicao = (int*) malloc (sizeof (int));
    P->arq[P->qtd].posicao[0] = posicao;
    P->arq[0].ocorrencias = 1;
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
    for (int i = 0; i < P->qtd; i ++) {
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
