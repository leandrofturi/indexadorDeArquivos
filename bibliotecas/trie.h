#ifndef TRIE_H
#define TRIE_H

#include "palavra.h"

#define R 62

typedef struct tCorpo tCorpo;
struct tCorpo {
    tPalavra *P;
    tCorpo* prox[R];
};

typedef tCorpo* tTrie[R];


tCorpo *criaCorpo ( );

tTrie *criaTrie ( );

void liberaCorpo (tCorpo *C);

void liberaTrie (tTrie *T);

int chave (char letra);

void caminhaTrie (char *palavra, int posicao, int c, int arq, tTrie *T);

void insereTrie (char *palavra, int posicao, int arq, tTrie *T);

tPalavra *buscaPalavraTrie (char *palavra, tTrie *T);

void imprimeTrie (tTrie *T);

void contadorTrie (int *c, tTrie *T);

int nElementosTrie (tTrie *T);

#endif
