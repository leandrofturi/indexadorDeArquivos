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

// Impressao da palavra buscada pela funcao buscaPalavra (char *caminhoArq).
// Funcao criada como diversao pelos autores do trabalho.
void imprimeBusca (tPalavra *P, char *palavra, char **caminhosArq, int qtd) {

    if (P == NULL) {
        printf ("\n################################################\n");
        printf("%s", palavra);
        printf ("\n################################################\n");
        printf ("PALAVRA NÃO ENCONTRADA!\n\n");
        return;
    }
    printf ("\n################################################\n");
    imprimePalavra (P);
    printf ("\n################################################\n");
    for (int j = 0; j < P->qtd; j ++) {
        for (int i = 1; i <= qtd; i ++) {
            if (P->arq[j].id == i) {
                printf ("ARQUIVO: %s\n", caminhosArq[i-1]);
                printf ("QUANTIDADE DE OCORRENCIAS: %d\n", P->arq[j].ocorrencias);
                if (P->arq[j].ocorrencias > 0) {
                    printf ("POSICOES: ");
                    for (int k = 0; k < P->arq[j].ocorrencias; k ++) {
                        printf ("%d ", P->arq[j].posicao[k]);
                    }
                    printf ("\n\n");
                }
            }
        }
    }
    printf ("\n\n");
}
