#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecas/balanceada.h"

tBalanceada *criaBalanceada ( ) {
	tBalanceada *B;
	B = (tBalanceada*) malloc (sizeof (tBalanceada));
	if (B != NULL) {
    	*B = NULL;
	}

	return (B);
}

void liberaGalhoAVL (tGalhoAVL *G) {
	if (G == NULL) {
		return;
	}
	liberaGalhoAVL (G->dir);
	liberaGalhoAVL (G->esq);
	liberaPalavra (G->P);
    free (G);
    G = NULL;
}

void liberaBalanceada (tBalanceada *B) {
	if ((*B) == NULL) {
		return;
	}
	liberaGalhoAVL (*B);
	free (B);
}

void insereBalanceada (char *palavra, int posicao, tBalanceada *B) {
	if ((*B) == NULL) {
		*B = (tGalhoAVL*) malloc (sizeof (tGalhoAVL));
		(*B)->P = criaPalavra (palavra, posicao);
        (*B)->esq = NULL;
        (*B)->dir = NULL;
	}
	else if (strcmp ((*B)->P->palavra, palavra) < 0) {
        insereBalanceada (palavra, posicao, &(*B)->esq);
    }
    else if (strcmp ((*B)->P->palavra, palavra) > 0) {
        insereBalanceada (palavra, posicao, &(*B)->dir);
    }
	else {
		colocaPosicao (posicao, buscaPalavraBalanceada (palavra, B));
	}
	if (((alturaBalanceamento (&(*B)->esq)) - (alturaBalanceamento (&(*B)->dir))) > 1) {
		//rotacaoEsq (B);
	}
	else if (((alturaBalanceamento (&(*B)->esq)) - (alturaBalanceamento (&(*B)->dir))) < -1) {
		//rotacaoDir (B);
	}
}

int alturaBalanceamento (tBalanceada *B) {
	if ((*B) == NULL) {
		return (0);
	}
	else {
		return (MAX (alturaBalanceamento (&((*B)->esq)), (alturaBalanceamento (&((*B)->dir)))));
	}
}

void rotacaoEsq (tBalanceada *B) {
	((*B)->esq)->dir = (*B);
	B = &((*B)->esq);
}

void rotacaoDir (tBalanceada *B) {
	((*B)->dir)->esq = (*B);
	B = &((*B)->dir);
}

void rotacaoDuplaEsq (tBalanceada *B) {
	rotacaoDir (&(*B)->esq);
	rotacaoEsq (B);
}

void rotacaoDuplaDir (tBalanceada *B) {
	rotacaoEsq (&(*B)->dir);
	rotacaoDir (B);
}

tPalavra *buscaPalavraBalanceada (char *palavra, tBalanceada *B) {
	if ((*B) == NULL) {
		return (NULL);
	}
	else if ((strcmp ((*B)->P->palavra, palavra)) < 0) {
		return (buscaPalavraBalanceada (palavra, &(*B)->esq));
	}
	else if ((strcmp ((*B)->P->palavra, palavra)) > 0) {
		return (buscaPalavraBalanceada (palavra, &(*B)->dir));
	}
	else {
		return ((*B)->P);
	}
}

void imprimeBalanceada (tBalanceada *B) {
	if ((*B) == NULL) {
		return;
	}
	else if ((*B) != NULL) {
        printf ("%s ", (*B)->P->palavra);
        imprimeBalanceada (&(*B)->esq);
        imprimeBalanceada (&(*B)->dir);
    }
}
