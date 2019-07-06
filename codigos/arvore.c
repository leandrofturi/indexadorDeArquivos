#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/arvore.h"


tArvore *criaArvore ( ) {
    tArvore *A;
    A = (tArvore*) malloc (sizeof (tArvore));
	if (A != NULL) {
    	(*A) = NULL;
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

void insereArvore (char *palavra, int posicao, int arq, tArvore *A) {
    if ((*A) == NULL) {
        (*A) = (tGalho*) malloc (sizeof (tGalho));
        (*A)->P = criaPalavra (palavra, posicao, arq);
        (*A)->esq = NULL;
        (*A)->dir = NULL;
    }
    else if (strcmp ((*A)->P->palavra, palavra) < 0) {
        insereArvore (palavra, posicao, arq, &(*A)->esq);
    }
    else if (strcmp ((*A)->P->palavra, palavra) > 0) {
        insereArvore (palavra, posicao, arq, &(*A)->dir);
    }
    else {
        colocaPosicao (posicao, arq, buscaPalavraArvore (palavra, A));
    }
}

tPalavra *buscaPalavraArvore (char *palavra, tArvore *A) {
	if ((*A) == NULL) {
		return (NULL);
	}
    if (palavra == NULL) {
		return (NULL);
	}
    else if (strcmp ((*A)->P->palavra, palavra) > 0) {
        return (buscaPalavraArvore (palavra, &(*A)->esq));
    }
    else if (strcmp ((*A)->P->palavra, palavra) < 0) {
        return (buscaPalavraArvore (palavra, &(*A)->dir));
    }
    else {
        return ((*A)->P);
    }
}

// Impressao prefixa.
void imprimeArvore (tArvore *A) {
    if ((*A) == NULL) {
        return;
    }
    else if ((*A) != NULL) {
        imprimePalavra ((*A)->P);
        imprimeArvore (&(*A)->esq);
        imprimeArvore (&(*A)->dir);
    }
}

int nElementosArvore (tArvore *A) {
    if ((*A) != NULL) {
        return (1 + (nElementosArvore (&(*A)->esq)) + (nElementosArvore (&(*A)->dir)));
    }
    else {
        return (0);
    }
}
