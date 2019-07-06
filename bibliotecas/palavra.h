#ifndef PALAVRA_H
#define PALAVRA_H

#define PALAVRAMAX 46

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct tArquivo tArquivo;
struct tArquivo {
    int id;
    int *posicao;
    int ocorrencias;
};

typedef struct tPalavra tPalavra;
struct tPalavra {
    char *palavra;
    tArquivo *arq;
    int qtd;
};


tPalavra *criaPalavra (char *palavra, int posicao, int arq);

void liberaPalavra (tPalavra *P);

void colocaPosicao (int posicao, int arq, tPalavra *P);

void adicionaArquivo (int posicao, int arq, tPalavra *P);

void imprimePalavra (tPalavra *P);

void imprimeBusca (tPalavra *P, char *palavra, char **arqs, int n);

#endif
