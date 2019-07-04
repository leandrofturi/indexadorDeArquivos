#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecas/encadeada.h"

tEncadeada *criaEncadeada ( ) {
	tEncadeada *E;
	E = (tEncadeada*) malloc (sizeof (tEncadeada));
    E->cabeca = E->rabo = NULL;
	E->n = 0;

    return (E);
}

void liberaCelula (tCelula *C) {
	liberaPalavra (C->P);
	free (C);
}

void liberaEncadeada (tEncadeada *E) {
	if (E == NULL) {
		return;
	}
	tCelula *aux1, *aux2;
	for (aux1 = E->cabeca; aux1 != NULL; aux1 = aux2) {
		aux2 = aux1->prox;
		liberaCelula (aux1);
	}
	free (E);
}

tCelula *insereCelula (char *palavra, int posicao, int arq) {
	tCelula *C;
	C = (tCelula*) malloc (sizeof (tCelula));
	C->P = criaPalavra (palavra, posicao, arq);
	C->prox = NULL;
	return (C);
}

void insereEncadeada (char *palavra, int posicao, int arq, tEncadeada *E) {
	if (E == NULL) {
		return;
	}
	if (E->n == 0) {
		E->cabeca = insereCelula (palavra, posicao, arq);
		E->rabo = E->cabeca;
		E->n ++;
	}
	else {
		tPalavra *busca;
		busca = buscaPalavraEncadeada (palavra, E);
		if (busca == NULL) {
			E->rabo->prox = insereCelula (palavra, posicao, arq);
			E->rabo = E->rabo->prox;
			E->n ++;
		}
		else {
			colocaPosicao (posicao, arq, busca);
		}
	}
}

tPalavra *buscaPalavraEncadeada (char *palavra, tEncadeada *E) {
	if (E == NULL) {
		return (NULL);
	}
	tCelula *aux;
	for (aux = E->cabeca; aux != NULL; aux = aux->prox) {
		if ((strcmp (aux->P->palavra, palavra)) == 0) {
			return (aux->P);
		}
	}
	return (NULL);
}

void imprimeEncadeada (tEncadeada *E) {
	if (E == NULL) {
		return;
	}
	tCelula *aux;
	for (aux = E->cabeca; aux != NULL; aux = aux->prox) {
		imprimePalavra (aux->P);
	}
}

int nElementosEncadeada (tEncadeada *E) {
	if (E == NULL) {
		return (0);
	}
	else {
		return (E->n);
	}
}
