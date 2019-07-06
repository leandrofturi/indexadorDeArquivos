#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "../bibliotecas/leitura.h"


int leituraArquivo (char *caminhoArq, int arq, tEstruturas *E, int estrutura) {
    int nC, nP;
    char c, palavraMax[PALAVRAMAX];
    FILE *arquivo;

    arquivo = fopen (caminhoArq, "r");
    if ((arquivo == NULL) ||
        (estrutura < 1) || (estrutura > 5)) {
        return (1);
    }
    else {
        nC = nP = 0;
        while ((c = fgetc (arquivo)) != EOF) {
		nP ++;
            if (((c >= 'a') && (c <= 'z')) ||
                ((c >= 'A') && (c <= 'Z')) ||
                ((c >= '0') && (c <= '9'))) {
                palavraMax[nC] = c;
                nC ++;
            }
            else if (nC > 0) {
                palavraMax[nC] = '\0';
                nC = 0;
                insereEstrutura (palavraMax, nP, arq, E, estrutura);
            }
        }
    }
    fclose (arquivo);

    return (0);
}

tEstruturas *inicializaEstrutura ( ) {
    tEstruturas *E;
    E = (tEstruturas*) malloc (sizeof (tEstruturas));
    for (int i = 0; i < 5; i ++) {
        E->alocados[i] = 0;
    }
    return (E);
}

void alocaEstrutura (tEstruturas *E, int estrutura) {
    if (E->alocados[estrutura-1] != 0) {
        return;
    }
    switch (estrutura) {
        case 1:                                                                 // Lista encadeada
			E->encadeada = criaEncadeada ( );
        break;

        case 2:                                                                 // Arvore binaria nao balanceada
            E->arvore = criaArvore ( );
        break;

        case 3:                                                                 // Arvore binaria balanceada (AVL)
			E->balanceada = criaArvore ( );
        break;

        case 4:                                                                 // Arvores de prefixo (TRIE)
            E->trie = criaTrie ( );
        break;

        case 5:                                                                 // Tabela Hash
			E->hash = criaHash ( );
        break;
    }
	E->alocados[estrutura-1] = 1;
}

void liberaEstrutura (tEstruturas *E, int estrutura) {
    if (E->alocados[estrutura-1] == 1) {
        switch (estrutura) {
            case 1:                                                             // Lista encadeada
				liberaEncadeada (E->encadeada);
            break;

            case 2:                                                             // Arvore binaria nao balanceada
                liberaArvore (E->arvore);
            break;

            case 3:                                                             // Arvore binaria balanceada (AVL)
				liberaArvore (E->balanceada);
            break;

            case 4:                                                             // Arvores de prefixo (TRIE)
                liberaTrie (E->trie);
            break;

            case 5:                                                             // Tabela Hash
				liberaHash (E->hash);
            break;
        }
		E->alocados[estrutura-1] = 0;
    }
}

void insereEstrutura (char *palavra, int posicao, int arq, tEstruturas *E, int estrutura) {
    if (E->alocados[estrutura-1] == 0) {
        return;
    }
    switch (estrutura) {
        case 1:                                                                 // Lista encadeada
			insereEncadeada (palavra, posicao, arq, E->encadeada);
        break;

        case 2:                                                                 // Arvore binaria nao balanceada
            insereArvore (palavra, posicao, arq, E->arvore);
        break;

        case 3:                                                                 // Arvore binaria balanceada (AVL)
			insereBalanceada (palavra, posicao, arq, E->balanceada);
        break;

        case 4:                                                                 // Arvores de prefixo (TRIE)
            insereTrie (palavra, posicao, arq, E->trie);
        break;

        case 5:                                                                 // Tabela Hash
			insereHash (palavra, posicao, arq, E->hash);
        break;
    }
}

tPalavra *buscaPalavraEstrutura (tEstruturas *E, int estrutura, char *palavra) {
    if (E->alocados[estrutura-1] == 0) {
        return (0);
    }
    switch (estrutura) {
        case 1:                                                                 // Lista encadeada
			return (buscaPalavraEncadeada (palavra, E->encadeada));
        break;

        case 2:                                                                 // Arvore binaria nao balanceada
            return (buscaPalavraArvore (palavra, E->arvore));
        break;

        case 3:                                                                 // Arvore binaria balanceada (AVL)
			return (buscaPalavraArvore (palavra, E->balanceada));
        break;

        case 4:                                                                 // Arvores de prefixo (TRIE)
            return (buscaPalavraTrie (palavra, E->trie));
        break;

        case 5:                                                                 // Tabela Hash
			return (buscaPalavraHash (palavra, E->hash));
        break;
    }
    return (NULL);
}

// Prototipo de algoritmo de busca.
// Apos o arquivo ser passado como parametro, e perguntado ao usuario qual palavra ele deseja buscar.
// Como resposta, e dado a palavra com suas ocorrencias.
void buscaPalavra (char **caminhosArq, int qtd) {

    printf ("\n\n");
    printf ("▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄ \n");
    printf ("░░░░ ░░░░▀█▄▀▄▀██████░▀█▄▀▄▀████▀ \n");
    printf ("░░░ ░░░░░░░▀█▄█▄███▀░░░▀██▄█▄█▀\n" );
    printf ("INDEXADOR DE ARQUIVOS\n\n");

    char estrutura, sair, palavra[PALAVRAMAX];
    tPalavra *P;
    tEstruturas *E;

    E = inicializaEstrutura ( );
    estrutura = sair = '0';

    printf ("Estrutura de armazenamento:\n");
    printf ("    1: Lista Encadeada\n");
    printf ("    2: Arvore binaria\n");
    printf ("    3: Arvore binaria balanceada\n");
    printf ("    4: Arvore Trie\n");
    printf ("    5: Tabela Hash\n");
    printf ("\n");
    while (((estrutura-48) < 1) || ((estrutura-48) > 5)) {
        scanf (" %c", &estrutura);
    }
    printf ("\n");
    alocaEstrutura (E, (estrutura-48));
    printf ("\nCarregando arquivos...\n");
    for (int i = 0; i < qtd; i ++) {
        if (leituraArquivo (caminhosArq[i], (i+1), E, (estrutura-48))) {
            printf ("ERRO! Problema na abertura do arquivo %d.\n", (i+1));
        }
    }

    while (sair != 'S') {
        printf ("Palavra a ser buscada: ");
        scanf (" %s", palavra);
        printf ("\n");
        P = buscaPalavraEstrutura (E, (estrutura-48), palavra);
        imprimeBusca (P, palavra, caminhosArq, qtd);
        printf ("Sair? (S/n)\n");
        scanf (" %c", &sair);
    }
    liberaEstrutura (E, (estrutura-48));
    finalizaEstrutura (E);
}

void imprimeEstrutura (tEstruturas *E, int estrutura) {
    if (E->alocados[estrutura-1] == 0) {
        return;
    }
    switch (estrutura) {
        case 1:                                                                 // Lista encadeada
			imprimeEncadeada (E->encadeada);
            printf ("\nQuantidade de elementos: %d\n", nElementosEncadeada (E->encadeada));
        break;

        case 2:                                                                 // Arvore binaria nao balanceada
            imprimeArvore (E->arvore);
            printf ("\nQuantidade de elementos: %d\n", nElementosArvore (E->arvore));
        break;

        case 3:                                                                 // Arvore binaria balanceada (AVL)
			imprimeBalanceada (E->balanceada);
            printf ("\nQuantidade de elementos: %d\n", nElementosArvore (E->balanceada));
        break;

        case 4:                                                                 // Arvores de prefixo (TRIE)
            imprimeTrie (E->trie);
            printf ("\nQuantidade de elementos: %d\n", nElementosTrie (E->trie));
        break;

        case 5:                                                                 // Tabela Hash
			imprimeHash (E->hash);
            medidasHash (E->hash);
        break;
    }
}

void finalizaEstrutura (tEstruturas *E) {
    for (int i = 0; i < 5; i ++) {
        if (E->alocados[i] == 1) {
            liberaEstrutura (E, i + 1);
        }
    }
    free (E);
}
