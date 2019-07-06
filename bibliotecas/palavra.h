#ifndef PALAVRA_H
#define PALAVRA_H

// Funcoes opacas para manusear as palavras.

// Tamanho de palavra maximo na Lingua Portuguesa.
#define PALAVRAMAX 46

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

// Estrutura para guardar ocorrencias de uma palavra em um determinado arquivo.
typedef struct tArquivo tArquivo;
struct tArquivo {
    int id; // Identificador do arquivo.
    int *posicao; // Posicoes de ocorrencia.
    int ocorrencias; // Quantidades de ocorrencias.
};

// Estrutura para receber a palavra.
typedef struct tPalavra tPalavra;
struct tPalavra {
    char *palavra;
    tArquivo *arq;
    int qtd; // Quantidade de arquivos.
};


tPalavra *criaPalavra (char *palavra, int posicao, int arq);

void liberaPalavra (tPalavra *P);

void colocaPosicao (int posicao, int arq, tPalavra *P);

void adicionaArquivo (int posicao, int arq, tPalavra *P);

void imprimePalavra (tPalavra *P);

void imprimeBusca (tPalavra *P, char *palavra, char **caminhosArq, int qtd);

#endif
