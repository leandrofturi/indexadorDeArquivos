#ifndef PALAVRA_H
#define PALAVRA_H

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct tArquivo tArquivo;
struct tArquivo {
    int *posicao;
    int ocorrencias;
};

typedef struct tPalavra tPalavra;
struct tPalavra {
    char *palavra;
    tArquivo *arq;
    int n;
};


tPalavra *criaPalavra (char *palavra, int posicao, int arq);

void liberaPalavra (tPalavra *P);

void colocaPosicao (int posicao, int arq, tPalavra *P);

void adicionaArquivo (tPalavra *P);

void imprimePalavra (tPalavra *P);

void imprimeBusca (tPalavra *P, char *palavra, char **arqs);

#endif
