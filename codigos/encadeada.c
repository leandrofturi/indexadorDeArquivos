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

tCelula *insereCelula (char *palavra, int posicao) {
	tCelula *C;
	C = (tCelula*) malloc (sizeof (tCelula));
	C->P = criaPalavra (palavra, posicao);
	C->prox = NULL;
	return (C);
}

void insereEncadeada (char *palavra, int posicao, tEncadeada *E) {
	if (E == NULL) {
		return;
	}
	if (E->n == 0) {
		E->cabeca = insereCelula (palavra, posicao);
		E->rabo = E->cabeca;
		E->n ++;
	}
	else {
		tPalavra *busca;
		busca = buscaPalavraEncadeada (palavra, E);
		if (busca == NULL) {
			E->rabo->prox = insereCelula (palavra, posicao);
			E->rabo = E->rabo->prox;
			E->n ++;
		}
		else {
			colocaPosicao (posicao, busca);
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
		printf ("%s ", aux->P->palavra);
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
