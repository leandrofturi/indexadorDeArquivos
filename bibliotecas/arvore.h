#ifndef ARVORE_H
#define ARVORE_H

#include "palavra.h"

typedef struct tGalho tGalho;
struct tGalho {
    tPalavra *P;
    tGalho *esq;
    tGalho *dir;
};

typedef tGalho* tArvore;


tArvore *criaArvore ( );

void liberaGalho (tGalho *G);

void liberaArvore (tArvore *A);

void insereArvore (char *palavra, int posicao, int arq, tArvore *A);

tPalavra *buscaPalavraArvore (char *palavra, tArvore *A);

void imprimeArvore (tArvore *A);

int nElementosArvore (tArvore *A);

#endif
