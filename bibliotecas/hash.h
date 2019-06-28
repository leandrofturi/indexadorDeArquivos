#ifndef HASH_H
#define HASH_H

#define M 16381

#include "encadeada.h"

typedef tEncadeada* tHash[M];


tHash* criaHash ( );

void liberaHash (tHash *H);

int hash (char *palavra);

void insereHash (char *palavra, int posicao, tHash *H);

tPalavra *buscaPalavraHash (char *palavra, tHash *H);

void imprimeHash (tHash *H);

void medidasHash (tHash *H);

#endif
