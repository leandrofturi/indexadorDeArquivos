#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/arvore.h"


tArvore *criaArvore ( ) {
    tArvore *A;
    A = (tArvore*) malloc (sizeof (tArvore));
	if (A != NULL) {
    	*A = NULL;
	}

    return (A);
}

void liberaGalho (tGalho *G) {
    if (G == NULL) {
        return;
    }
    liberaGalho (G->esq);
    liberaGalho (G->dir);
    liberaPalavra (G->P);
    free (G);
    G = NULL;
}

void liberaArvore (tArvore *A) {
    if (A == NULL) {
        return;
    }
    liberaGalho (*A);
    free (A);
}

void insereArvore (char *palavra, int posicao, tArvore *A) {
    if ((*A) == NULL) {
        *A = (tGalho*) malloc (sizeof (tGalho));
        (*A)->P = criaPalavra (palavra, posicao);
        (*A)->esq = NULL;
        (*A)->dir = NULL;
    }
    else if (strcmp ((*A)->P->palavra, palavra) < 0) {
        insereArvore (palavra, posicao, &(*A)->esq);
    }
    else if (strcmp ((*A)->P->palavra, palavra) > 0) {
        insereArvore (palavra, posicao, &(*A)->dir);
    }
    else {
        colocaPosicao (posicao, buscaPalavraArvore (palavra, A));
    }
}

tPalavra *buscaPalavraArvore (char *palavra, tArvore *A) {
	if ((*A) == NULL) {
		return (NULL);
	}
    else if (strcmp ((*A)->P->palavra, palavra) < 0) {
        return (buscaPalavraArvore (palavra, &(*A)->esq));
    }
    else if (strcmp ((*A)->P->palavra, palavra) > 0) {
        return (buscaPalavraArvore (palavra, &(*A)->dir));
    }
    else {
        return ((*A)->P);
    }
}

void imprimeArvore (tArvore *A) {
    if ((*A) == NULL) {
        return;
    }
    else if ((*A) != NULL) {
        printf ("%s ", (*A)->P->palavra);
        imprimeArvore (&(*A)->esq);
        imprimeArvore (&(*A)->dir);
    }
}
