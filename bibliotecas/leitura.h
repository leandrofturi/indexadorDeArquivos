#ifndef LEITURA_H
#define LEITURA_H

// Funcoes opacas para leitura de arquivos e agrupamento de estruturas.

#include "palavra.h"
#include "encadeada.h"
#include "arvore.h"
#include "balanceada.h"
#include "trie.h"
#include "hash.h"

// Definicao de uma estrutura global.
typedef struct tEstruturas tEstruturas;
struct tEstruturas {
	tEncadeada *encadeada; // estrutura = 1
    tArvore *arvore; // estrutura = 2
    tBalanceada *balanceada; // estrutura = 3
	tTrie *trie; // estrutura = 4
	tHash *hash; // estrutura = 5

    int alocados[5];
};


int leituraArquivo (char *caminhoArq, int arq, tEstruturas *E, int estrutura);

tEstruturas *inicializaEstrutura ( );

void alocaEstrutura (tEstruturas *E, int estrutura);

void liberaEstrutura (tEstruturas *E, int estrutura);

tPalavra *buscaPalavraEstrutura (tEstruturas *E, int estrutura, char *palavra);

void buscaPalavra (char **caminhosArq, int qtd);

void insereEstrutura (char *palavra, int posicao, int arq, tEstruturas *E, int estrutura);

void imprimeEstrutura (tEstruturas *E, int estrutura);

void finalizaEstrutura (tEstruturas *E);

#endif
