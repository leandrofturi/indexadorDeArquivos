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

char *caminhaPalavra (char *palavra);

void caminhaPatricia (char *palavra, int posicao, int c, tPatricia *T);

void inserePatricia (char *palavra, int posicao, tPatricia *T);

tPalavra *buscaPalavraPatricia (char *palavra, tPatricia *T);

void imprimePatricia (tPatricia *T);

void contadorPatricia (int *c, tPatricia *T);

int nElementosPatricia (tPatricia *T);

#endif
