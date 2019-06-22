#ifndef LEITURA_H
#define LEITURA_H

typedef struct tPalavra tPalavra;
struct tPalavra {
    char *palavra;
    int *posicao;
    int ocorrencias;
};

#include "arvore.h"

typedef struct tEstruturas tEstruturas;
struct tEstruturas {
    tArvore *arvore;
    int alocados[5];
};


int leituraArquivo (char *caminhoArq, tEstruturas *E, int estrutura);

tPalavra *criaPalavra (char *palavra, int posicao);

void liberaPalavra (tPalavra *P);

void colocaPosicao (int novaPosicao, tPalavra *P);

tEstruturas *inicializaEstrutura ( );

void alocaEstrutura (tEstruturas *E, int estrutura);

void liberaEstrutura (tEstruturas *E, int estrutura);

void insereEstrutura (char *palavra, int posicao, tEstruturas *E, int estrutura);

void imprimeEstrutura (tEstruturas *E, int estrutura);

void finalizaEstrutura (tEstruturas *E);

#endif
