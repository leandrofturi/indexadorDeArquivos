#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecas/trie.h"

tCorpo *criaCorpo ( ) {
    tCorpo *C;
    C = (tCorpo*) malloc (sizeof (tCorpo));
    C->P = NULL;
    if (C != NULL) {
        for (int i = 0; i < R; i ++) {
    		C->prox[i] = NULL;
    	}
    }
    return (C);
}

tTrie *criaTrie ( ) {
    tTrie *T;
	T = (tTrie*) malloc (sizeof (tTrie));
    if (T != NULL) {
        for (int i = 0; i < R; i ++) {
    		(*T)[i] = NULL;
    	}
    }
    return (T);
}

void liberaCorpo (tCorpo *C) {
    if (C == NULL) {
        return;
    }
    for (int i = 0; i < R; i ++) {
        liberaCorpo (C->prox[i]);
    }
    if (C->P != NULL) {
        liberaPalavra (C->P);
    }
    free (C);
}

void liberaTrie (tTrie *T) {
    if (T == NULL) {
        return;
    }
    for (int i = 0; i < R; i ++) {
		liberaCorpo ((*T)[i]);
	}
    free (T);
}

int chave (char letra) {
    if ((letra >= 'a') && (letra <= 'z')) {
        return (letra - 97 + 10 + 26);
    }
    else if ((letra >= 'A') && (letra <= 'Z')) {
        return (letra - 65 + 10);
    }
    else if ((letra >= '0') && (letra <= '9')) {
        return (letra - 48);
    }
    else {
        return (-1);
    }
}

void caminhaTrie (char *palavra, int posicao, int c, int arq, tTrie *T) {
    if (c == strlen (palavra)) {
        return;
    }
    if ((*T)[chave (palavra[c])] == NULL) {
        (*T)[chave (palavra[c])] = criaCorpo ( );
    }
    if ((c+1) == strlen (palavra)) {
        if ((*T)[chave (palavra[c])]->P == NULL) {
            (*T)[chave (palavra[c])]->P = criaPalavra (palavra, posicao, arq);
        }
        else {
            colocaPosicao (posicao, arq, (*T)[chave (palavra[c])]->P);
        }
    }
    else {
        caminhaTrie (palavra, posicao, (c+1), arq, &(((*T)[chave (palavra[c])])->prox));
    }
}

void insereTrie (char *palavra, int posicao, int arq, tTrie *T) {
    if (T == NULL) {
        return;
    }
    if (palavra == NULL) {
        return;
    }
    caminhaTrie (palavra, posicao, 0, arq, T);
}

tPalavra *buscaPalavraTrie (char *palavra, tTrie *T) {
    if (T == NULL) {
        return (NULL);
    }
    for (int i = 0; i < R; i ++) {
        if ((*T)[i] != NULL) {
            if ((*T)[i]->P != NULL) {
                if ((strcmp ((*T)[i]->P->palavra, palavra)) == 0) {
                    return ((*T)[i]->P);
                }
            }
            return (buscaPalavraTrie (palavra, &(((*T)[i]->prox))));
        }
    }
    return (NULL);
}

void imprimeTrie (tTrie *T) {
    if (T == NULL) {
        return;
    }
    for (int i = 0; i < R; i ++) {
        if ((*T)[i] != NULL) {
            if ((*T)[i]->P != NULL) {
                imprimePalavra ((*T)[i]->P);
            }
            imprimeTrie (&(((*T)[i]->prox)));
        }
    }
}

void contadorTrie (int *c, tTrie *T) {
    if (T == NULL) {
        return;
    }
    for (int i = 0; i < R; i ++) {
        if ((*T)[i] != NULL) {
            if ((*T)[i]->P != NULL) {
                (*c) ++;
            }
            contadorTrie (c, &(((*T)[i]->prox)));
        }
    }
}

int nElementosTrie (tTrie *T) {
    int c;
    c = 0;
    contadorTrie (&c, T);
    return (c);
}
