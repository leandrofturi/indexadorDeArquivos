#ifndef ENCADEADA_H
#define ENCADEADA_H

#include "palavra.h"

typedef struct tCelula tCelula;
struct tCelula {
    tPalavra *P;
    tCelula *prox;
};

typedef struct tEncadeada tEncadeada;
struct tEncadeada {
    tCelula *cabeca;
	tCelula *rabo;
	int n;
};


tEncadeada *criaEncadeada ( );

void liberaCelula (tCelula *C);

void liberaEncadeada (tEncadeada *E);

tCelula *insereCelula (char *palavra, int posicao);

void insereEncadeada (char *palavra, int posicao, tEncadeada *E);

tPalavra *buscaPalavraEncadeada (char *palavra, tEncadeada *E);

void imprimeEncadeada (tEncadeada *E);

int nElementosEncadeada (tEncadeada *E);

#endif
