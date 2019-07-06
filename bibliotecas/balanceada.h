#ifndef BALANCEADA_H
#define BALANCEADA_H

// Funcoes opacas da TAD Arvore Balanceada (AVL) implementadas recursivamente.

#include "palavra.h"
#include "arvore.h"

typedef tGalho* tBalanceada;


void insereBalanceada (char *palavra, int posicao, int arq, tBalanceada *B);

void balanceamento (tBalanceada *B);

int alturaBalanceamento (tBalanceada *B);

int fatorBalanceamento (tBalanceada *B);

void rotacaoEsq (tBalanceada *B);

void rotacaoDir (tBalanceada *B);

void imprimeBalanceada (tBalanceada *B);

#endif
