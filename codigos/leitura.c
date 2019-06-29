#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/leitura.h"


int leituraArquivo (char *caminhoArq, tEstruturas *E, int estrutura) {
    int nC, nP;
    char c, palavraMax[189819];
    FILE *arq;

    arq = fopen (caminhoArq, "r");
    if ((arq == NULL) ||
        (estrutura < 1) || (estrutura > 5)) {
        return (1);
    }
    else {
        nC = nP = 0;
        while ((c = fgetc (arq)) != EOF) {
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
                insereEstrutura (palavraMax, nP, E, estrutura);
            }
        }
    }
    fclose (arq);

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

            break;

            case 5:                                                             // Tabela Hash
				liberaHash (E->hash);
            break;
        }
		E->alocados[estrutura-1] = 0;
    }
}

void insereEstrutura (char *palavra, int posicao, tEstruturas *E, int estrutura) {
    if (E->alocados[estrutura-1] == 0) {
        return;
    }
    switch (estrutura) {
        case 1:                                                                 // Lista encadeada
			insereEncadeada (palavra, posicao, E->encadeada);
        break;

        case 2:                                                                 // Arvore binaria nao balanceada
            insereArvore (palavra, posicao, E->arvore);
        break;

        case 3:                                                                 // Arvore binaria balanceada (AVL)
			insereBalanceada (palavra, posicao, E->balanceada);
        break;

        case 4:                                                                 // Arvores de prefixo (TRIE)

        break;

        case 5:                                                                 // Tabela Hash
			insereHash (palavra, posicao, E->hash);
        break;
    }
}

void imprimeEstrutura (tEstruturas *E, int estrutura) {
    if (E->alocados[estrutura-1] == 0) {
        return;
    }
    switch (estrutura) {
        case 1:                                                                 // Lista encadeada
			imprimeEncadeada (E->encadeada);
            printf ("Quantidade de elementos: %d\n", nElementosEncadeada (E->encadeada));
        break;

        case 2:                                                                 // Arvore binaria nao balanceada
            imprimeArvore (E->arvore);
            printf ("Quantidade de elementos: %d\n", nElementosArvore (E->arvore));
        break;

        case 3:                                                                 // Arvore binaria balanceada (AVL)
			imprimeBalanceada (E->balanceada);
            printf ("Quantidade de elementos: %d\n", nElementosArvore (E->balanceada));
        break;

        case 4:                                                                 // Arvores de prefixo (TRIE)

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
