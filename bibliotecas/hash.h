#ifndef HASH_H
#define HASH_H

#define M 16381
//127, 251, 509, 1021, 2039, 4093, 8191, 16381, 32749, 65521, 131071, 262139
#include "encadeada.h"

typedef tEncadeada* tDicionario[M];

typedef struct tHash tHash;
struct tHash {
    tDicionario D;
    int n;
};


tHash* criaHash ( );

void criaDicionario (tDicionario *D, int h);

void liberaHash (tHash *H);

int hash (char *palavra);

void insereHash (char *palavra, int posicao, tHash *H);

tPalavra *buscaPalavraHash (char *palavra, tHash *H);

void imprimeHash (tHash *H);

void medidasHash (tHash *H);

#endif
