#ifndef LEITURA_H
#define LEITURA_H

#include "palavra.h"
#include "encadeada.h"
#include "arvore.h"
#include "balanceada.h"
#include "trie.h"
#include "hash.h"

typedef struct tEstruturas tEstruturas;
struct tEstruturas {
	tEncadeada *encadeada;
    tArvore *arvore;
    tBalanceada *balanceada;
	tTrie *trie;
	tHash *hash;

    int alocados[5];
};


int leituraArquivo (char *caminhoArq, tEstruturas *E, int estrutura);

tEstruturas *inicializaEstrutura ( );

void alocaEstrutura (tEstruturas *E, int estrutura);

void liberaEstrutura (tEstruturas *E, int estrutura);

int buscaPalavraEstrutura (tEstruturas *E, int estrutura, char *palavra);

void insereEstrutura (char *palavra, int posicao, tEstruturas *E, int estrutura);

void imprimeEstrutura (tEstruturas *E, int estrutura);

void finalizaEstrutura (tEstruturas *E);

#endif
