#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecas/balanceada.h"

tBalanceada *criaBalanceada ( ) {
	return (criaArvore ( ));
}

void liberaGalhoAVL (tGalhoAVL *G) {
	liberaGalho (G);
}

void liberaBalanceada (tBalanceada *B) {
	liberaArvore (B);
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

		if ((ABS ((alturaBalanceamento (&(*B)->esq)) - (alturaBalanceamento (&(*B)->dir)))) > 1) {
			if (strcmp ((*B)->esq->P->palavra, palavra) > 0) {
				rotacaoEsq (B);
			}
			else {
				rotacaoDuplaEsq (B);
			}
		}
    }
    else if (strcmp ((*B)->P->palavra, palavra) > 0) {
        insereBalanceada (palavra, posicao, &(*B)->dir);

		if ((ABS ((alturaBalanceamento (&(*B)->esq)) - (alturaBalanceamento (&(*B)->dir)))) > 1) {
			if (strcmp ((*B)->dir->P->palavra, palavra) > 0) {
				rotacaoDir (B);
			}
			else {
				rotacaoDuplaDir (B);
			}
		}
    }
	else {
		colocaPosicao (posicao, buscaPalavraBalanceada (palavra, B));
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

void rotacaoEsq (tBalanceada *B) {
	tGalhoAVL *aux;
	aux = (*B)->esq;
	(*B)->esq = aux->dir;
	aux->dir = (*B);
	(*B) = aux;
}

void rotacaoDir (tBalanceada *B) {
	tGalhoAVL *aux;
	aux = (*B)->dir;
	(*B)->dir = aux->esq;
	aux->esq = (*B);
	(*B) = aux;
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
	return (buscaPalavraArvore (palavra, B));
}

void imprimeBalanceada (tBalanceada *B) {
	if ((*B) == NULL) {
        return;
    }
    else if ((*B) != NULL) {
        printf ("%s ", (*B)->P->palavra);
		//printf ("%s %d \n", (*B)->P->palavra, alturaBalanceamento (B));
        imprimeBalanceada (&(*B)->esq);
        imprimeBalanceada (&(*B)->dir);
    }
}
