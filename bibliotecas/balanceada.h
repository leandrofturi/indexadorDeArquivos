#ifndef BALANCEADA_H
#define BALANCEADA_H

#include "palavra.h"
#include "arvore.h"

typedef tGalho tGalhoAVL;

typedef tGalhoAVL* tBalanceada;


tBalanceada *criaBalanceada ( );

void liberaGalhoAVL (tGalhoAVL *G);

void liberaBalanceada (tBalanceada *B);

void insereBalanceada (char *palavra, int posicao, tBalanceada *B);

int alturaBalanceamento (tBalanceada *B);

void rotacaoEsq (tBalanceada *B);

void rotacaoDir (tBalanceada *B);

void rotacaoDuplaEsq (tBalanceada *B);

void rotacaoDuplaDir (tBalanceada *B);

tPalavra *buscaPalavraBalanceada (char *palavra, tBalanceada *B);

void imprimeBalanceada (tBalanceada *B);

#endif
