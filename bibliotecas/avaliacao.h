#ifndef AVALIACAO_H
#define AVALIACAO_H

#include "leitura.h"

#define PROBABILIDADE 5


char **buscaPalavrasAleatorias (char **caminhosArq, int qtd, int n);

void buscaPalavraAnalise (tEstruturas *E, int estrutura, char **palavras, int n);

void avaliaDesempenho (char **caminhosArq, int qtd, int n);

#endif
