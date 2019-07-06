#ifndef ENCADEADA_H
#define ENCADEADA_H

// Funcoes opacas da TAD Lista Encadeada implementadas de forma procedural.

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

tCelula *insereCelula (char *palavra, int posicao, int arq);

void insereEncadeada (char *palavra, int posicao, int arq, tEncadeada *E);

tPalavra *buscaPalavraEncadeada (char *palavra, tEncadeada *E);

void imprimeEncadeada (tEncadeada *E);

int nElementosEncadeada (tEncadeada *E);

#endif
