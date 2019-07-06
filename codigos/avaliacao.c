#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "../bibliotecas/avaliacao.h"


// Reabertura do arquivo para buscar palavras aleatorias
char **buscaPalavrasAleatorias (char **caminhosArq, int qtd, int n) {
    int nC, i;
    char c, palavraMax[PALAVRAMAX];
    char **encontradas;
    FILE *arquivo;

    struct timeval semente;
    gettimeofday (&semente, NULL);
    srand ((int) (semente.tv_sec + 1000000 * semente.tv_usec));

    if ((qtd < 0) || (n < 0)) {
        return (NULL);
    }

    limpaValgrind (caminhosArq, &qtd, &n);
    encontradas = (char**) malloc (n * sizeof (char*));
    if (encontradas == NULL) {
        return (NULL);
    }
    for (int i = 0; i < n; i++) {
        encontradas[i] = NULL;
    }

    i = 0;
    // A busca e realizada em todos os arquivos.
    for (int j = 0; j < qtd; j ++) {
        arquivo = NULL;
        arquivo = fopen (caminhosArq[j], "r");
        if (arquivo == NULL) {
            return (encontradas);
        }
        nC = 0;
        while ((c = fgetc (arquivo)) != EOF) {
            if (((c >= 'a') && (c <= 'z')) ||
                ((c >= 'A') && (c <= 'Z')) ||
                ((c >= '0') && (c <= '9'))) {
                palavraMax[nC] = c;
                nC ++;
            }
            else if (nC > 0) {
                palavraMax[nC] = '\0';
                // Caso ocorra uma variavel aleatoria abaixo da probabilidade esperada, ela e escolhida.
                if (((rand ( )) % 100) < PROBABILIDADE) {
                    encontradas[i] = (char*) malloc ((nC+1) * sizeof (char));
                    strcpy (encontradas[i], palavraMax);
                    i ++;
                    // Caso complete a quantidade de palavras.
                    if (i == n) {
                        fclose (arquivo);
                        return (encontradas);
                    }
                }
                nC = 0;
            }
        }
        fclose (arquivo);
    }

    return (encontradas);
}
// Funcao sem prints.
void buscaPalavraAnalise (tEstruturas *E, int estrutura, char **palavras, int n) {
    tPalavra *P;
    for (int i = 0; i < n; i++) {
        P = buscaPalavraEstrutura (E, estrutura, palavras[i]);
    }
    if (P == NULL) {
        return;
    }
    else {
        return;
    }
}
// Funcao primaria do trabalho.
void avaliaDesempenho (char **caminhosArq, int qtd, int n) {
    int leitura[5];
    char **palavras;
    clock_t t;
    double tempoCarregamento[5], tempoBusca[5];
    tEstruturas *E;

    if ((qtd < 0) || (n < 0)) {
        return;
    }
    for (int i = 0; i < 5; i ++) {
        tempoCarregamento[i] = 0;
        tempoBusca[i] = 0;
    }

    E = inicializaEstrutura ( );

    alocaEstrutura (E, 1);
    alocaEstrutura (E, 2);
    alocaEstrutura (E, 3);
    alocaEstrutura (E, 4);
    alocaEstrutura (E, 5);

    for (int i = 0; i < qtd; i ++) {
        for (int j = 1; j <= 5; j ++) {
            t = clock ( );
            leitura[j-1] = leituraArquivo (caminhosArq[i], i, E, j);
            t = clock ( ) - t;
            tempoCarregamento[j-1] += ((double) t) / CLOCKS_PER_SEC;
            if (leitura[j-1]) {
                // Caso ocorram erros na abertura do arquivo, o tempo de carregamento deve ser nulo.
                tempoCarregamento[j-1] = 0;
            }
        }
    }

    palavras = buscaPalavrasAleatorias (caminhosArq, qtd, n);
    if (palavras != NULL) {
        for (int i = 1; i <= 5; i ++) {
            t = clock ( );
            buscaPalavraAnalise (E, i, palavras, n);
            t = clock ( ) - t;
            tempoBusca[i] += ((double) t) / CLOCKS_PER_SEC;
        }

        for (int i = 0; i < n; i ++) {
            if (palavras[i] != NULL) {
                free (palavras[i]);
            }
        }
        free (palavras);
    }

    liberaEstrutura (E, 1);
    liberaEstrutura (E, 2);
    liberaEstrutura (E, 3);
    liberaEstrutura (E, 4);
    liberaEstrutura (E, 5);

    finalizaEstrutura (E);

    printf ("\n");
    printf ("NUMERO DE BUSCAS: %d\n", n);
    printf ("                ENCADEADA   ARVORE      AVL         TRIE        HASH\n");
    printf ("CARREGAMENTO    ");
    for (int i = 0; i < 5; i ++) {
        printf ("%f    ", tempoCarregamento[i]);
    }
    printf ("\n");
    printf ("BUSCA           ");
    for (int i = 0; i < 5; i ++) {
        printf ("%f    ", tempoBusca[i]);
    }
    printf ("\n");
}

void limpaValgrind (char **caminhos, int *qtd, int *n) {
    for (int i = 1; i < (*qtd); i ++) {
        if ((caminhos[i][0] >= '0') && (caminhos[i][0] <= '9')) {
            *qtd = i;
            *n = atoi (caminhos[i]);
            return;
        }
    }
}
