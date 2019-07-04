#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecas/balanceada.h"


void insereBalanceada (char *palavra, int posicao, int arq, tBalanceada *B) {
	if ((*B) == NULL) {
		(*B) = (tGalho*) malloc (sizeof (tGalho));
		(*B)->P = criaPalavra (palavra, posicao, arq);
        (*B)->esq = NULL;
        (*B)->dir = NULL;
	}
	else if (strcmp ((*B)->P->palavra, palavra) > 0) {
        insereBalanceada (palavra, posicao, arq, &(*B)->esq);
    }
    else if (strcmp ((*B)->P->palavra, palavra) < 0) {
        insereBalanceada (palavra, posicao, arq, &(*B)->dir);
    }
	else {
		colocaPosicao (posicao, arq, buscaPalavraArvore (palavra, B));
	}
	balanceamento (B);
}

void balanceamento (tBalanceada *B) {
	if (fatorBalanceamento (B) > 1) {
		if (fatorBalanceamento (&(*B)->esq) > 0) {
			rotacaoDir (B);
		}
		else {
			rotacaoEsq (&(*B)->esq);
			rotacaoDir (B);
		}
	}
	else if (fatorBalanceamento (B) < -1) {
		if (fatorBalanceamento (&(*B)->dir) < 0) {
			rotacaoEsq (B);
		}
		else {
			rotacaoDir (&(*B)->dir);
			rotacaoEsq (B);
		}
	}
}

int alturaBalanceamento (tBalanceada *B) {
	if ((*B) == NULL) {
		return (0);
	}
	else {
		return ((MAX ((1 + (alturaBalanceamento (&((*B)->esq)))), (1 + (alturaBalanceamento (&((*B)->dir)))))));
	}
}

int fatorBalanceamento (tBalanceada *B) {
	return ((alturaBalanceamento (&(*B)->esq)) - (alturaBalanceamento (&(*B)->dir)));
}

void rotacaoEsq (tBalanceada *B) {
	tGalho *aux;
	aux = (*B)->dir;
	(*B)->dir = aux->esq;
	aux->esq = (*B);
	(*B) = aux;
}

void rotacaoDir (tBalanceada *B) {
	tGalho *aux;
	aux = (*B)->esq;
	(*B)->esq = aux->dir;
	aux->dir = (*B);
	(*B) = aux;
}

void imprimeBalanceada (tBalanceada *B) {
	if ((*B) == NULL) {
        return;
    }
    else if ((*B) != NULL) {
        imprimePalavra ((*B)->P);
        imprimeBalanceada (&(*B)->esq);
        imprimeBalanceada (&(*B)->dir);
    }
}
