#ifndef PALAVRA_H
#define PALAVRA_H

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct tPalavra tPalavra;
struct tPalavra {
    char *palavra;
    int *posicao;
    int ocorrencias;
};


tPalavra *criaPalavra (char *palavra, int posicao);

void liberaPalavra (tPalavra *P);

void colocaPosicao (int novaPosicao, tPalavra *P);

#endif
