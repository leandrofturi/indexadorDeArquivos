#ifndef LEITURA_H
#define LEITURA_H

#include "palavra.h"
#include "encadeada.h"
#include "arvore.h"
#include "balanceada.h"

typedef struct tEstruturas tEstruturas;
struct tEstruturas {
	tEncadeada *encadeada;
    tArvore *arvore;
    tBalanceada *balanceada;
    int alocados[5];
};


int leituraArquivo (char *caminhoArq, tEstruturas *E, int estrutura);

tEstruturas *inicializaEstrutura ( );

void alocaEstrutura (tEstruturas *E, int estrutura);

void liberaEstrutura (tEstruturas *E, int estrutura);

void insereEstrutura (char *palavra, int posicao, tEstruturas *E, int estrutura);

void imprimeEstrutura (tEstruturas *E, int estrutura);

void finalizaEstrutura (tEstruturas *E);

#endif
