#ifndef LEITURA_H
#define LEITURA_H

typedef struct tPalavra tPalavra;
struct tPalavra
{
    char *palavra;
    int *posicao;
    int ocorrencias;
};


int leituraArquivo (char *caminhoArq, int estrutura);

tPalavra *criaPalavra (char *palavra, int posicao);

void colocaPosicao (int novaPosicao, tPalavra *P);

#endif
