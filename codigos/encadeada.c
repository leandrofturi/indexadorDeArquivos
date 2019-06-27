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

void liberaEncadeada (tEncadeada *E) {
	tCelula *aux1, *aux2;
	for (aux1 = E->cabeca; aux1 != NULL; aux1 = aux2) {
		aux2 = aux1->prox;
		liberaPalavra (aux1->P);
		free (aux1);
	}
	free (E);
}

void insereEncadeada (char *palavra, int posicao, tEncadeada *E) {
	if (E->n == 0) {
		E->cabeca = (tCelula*) malloc (sizeof (tCelula));
		E->cabeca->P = criaPalavra (palavra, posicao);
		E->rabo = E->cabeca;
	}
	else {
		E->rabo->prox = (tCelula*) malloc (sizeof (tCelula));
		E->rabo->prox->P = criaPalavra (palavra, posicao);
		E->rabo = E->rabo->prox;
		E->rabo->prox = NULL;
	}
	E->n ++;
}

tPalavra *buscaPalavraEncadeada (char *palavra, tEncadeada *E) {
	tCelula *aux;
	for (aux = E->cabeca; aux != NULL; aux = aux->prox) {
		if ((strcmp (aux->P->palavra, palavra)) == 0) {
			return (aux->P);
		}
	}
	return (NULL);
}

void imprimeEncadeada (tEncadeada *E) {
	tCelula *aux;
	for (aux = E->cabeca; aux != NULL; aux = aux->prox) {
		printf ("%s ", aux->P->palavra);
	}
}
