#ifndef AVALIACAO_H
#define AVALIACAO_H

// Funcoes para avaliacao de desempenho das TADs.

#include "leitura.h"

// Valor de probabilidade de uma determinada palavra ser escolhida para ser buscada.
#define PROBABILIDADE 25


// Reabertura do arquivo com nova busca de palavras aletaórias.
// caminhosArq represennta um vetor contendo os caminhos dos arquivos a serem carregados.
char **buscaPalavrasAleatorias (char **caminhosArq, int qtd, int n);

// Busca de um vetor de palavras.
// palavras representa um vetor contendo n palavras a serem pesquisadas.
void buscaPalavraAnalise (tEstruturas *E, int estrutura, char **palavras, int n);

/* Seu programa deverá ter uma função chamada AvaliaDesempenho, que carrega todos as palavras,
seleciona N palavras entre as carregadas aleatoriamente,
busca essas palavras na Estrutura e gera como saída um relatório de desempenho. */
// Essa e a funcao.
void avaliaDesempenho (char **caminhosArq, int qtd, int n);

// Limpar as flags do Valgrind
// *SEMPRE QUE USAR VALGRIND DEVE USAR ESSA FUNCAO*
void limpaValgrind (char **caminhos, int *qtd, int *n);

#endif
