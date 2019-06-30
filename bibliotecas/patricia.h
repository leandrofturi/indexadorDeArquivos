#ifndef PATRICIA_H
#define PATRICIA_H

#include "palavra.h"

#define R 62

typedef struct tCorpo tCorpo;
struct tCorpo {
    tPalavra *P;
    tCorpo* prox[R];
};

typedef tCorpo* tPatricia[R];


tCorpo *criaCorpo ( );

tPatricia *criaPatricia ( );

void liberaCorpo (tCorpo *C);

void liberaPatricia (tPatricia *T);

int chave (char letra);

char letra (int chave);

char *caminhaPalavra (char *palavra);

tPalavra *criaCaminhoPatricia (char *palavra, tCorpo *C);

void inserePatricia (char *palavra, int posicao, tPatricia *T);

tPalavra *buscaPalavraPatricia (char *palavra, tPatricia *T);

void imprimeCorpo (tCorpo *C);

void imprimePatricia (tPatricia *T);

int nElementosCorpo (tCorpo *C);

int nElementosPatricia (tPatricia *T);

#endif
