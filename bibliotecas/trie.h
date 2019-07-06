#ifndef TRIE_H
#define TRIE_H

// Funcoes opacas da TAD Arvore Trie implementadas recursivamente.

#include "palavra.h"

// Tamanho do alfabeto = {a .. z} U {A ... Z} U {0 ... 9}
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

// Funcao auxiliar criada para manter o padrao do prototipo de insercao.
void caminhaTrie (char *palavra, int posicao, int c, int arq, tTrie *T);

void insereTrie (char *palavra, int posicao, int arq, tTrie *T);

tPalavra *buscaPalavraTrie (char *palavra, tTrie *T);

void imprimeTrie (tTrie *T);

void contadorTrie (int *c, tTrie *T);

int nElementosTrie (tTrie *T);

#endif
