#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecas/patricia.h"

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

tPatricia *criaPatricia ( ) {
    tPatricia *T;
	T = (tPatricia*) malloc (sizeof (tPatricia));
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

void liberaPatricia (tPatricia *T) {
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

void caminhaPatricia (char *palavra, int posicao, int c, tPatricia *T) {
    if (c == strlen (palavra)) {
        return;
    }
    if ((*T)[chave (palavra[c])] == NULL) {
        (*T)[chave (palavra[c])] = criaCorpo ( );
    }
    if ((c+1) == strlen (palavra)) {
        if ((*T)[chave (palavra[c])]->P == NULL) {
            (*T)[chave (palavra[c])]->P = criaPalavra (palavra, posicao);
        }
        else {
            colocaPosicao (posicao, (*T)[chave (palavra[c])]->P);
        }
    }
    else {
        caminhaPatricia (palavra, posicao, (c+1), &(((*T)[chave (palavra[c])])->prox));
    }
}

void inserePatricia (char *palavra, int posicao, tPatricia *T) {
    if (T == NULL) {
        return;
    }
    if (palavra == NULL) {
        return;
    }
    caminhaPatricia (palavra, posicao, 0, T);
}

tPalavra *buscaPalavraPatricia (char *palavra, tPatricia *T) {
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
            return (buscaPalavraPatricia (palavra, &(((*T)[i]->prox))));
        }
    }
    return (NULL);
}

void imprimePatricia (tPatricia *T) {
    if (T == NULL) {
        return;
    }
    for (int i = 0; i < R; i ++) {
        if ((*T)[i] != NULL) {
            if ((*T)[i]->P != NULL) {
                printf("%s ", (*T)[i]->P->palavra);
            }
            imprimePatricia (&(((*T)[i]->prox)));
        }
    }
}

void contadorPatricia (int *c, tPatricia *T) {
    if (T == NULL) {
        return;
    }
    for (int i = 0; i < R; i ++) {
        if ((*T)[i] != NULL) {
            if ((*T)[i]->P != NULL) {
                (*c) ++;
            }
            contadorPatricia (c, &(((*T)[i]->prox)));
        }
    }
}

int nElementosPatricia (tPatricia *T) {
    int c;
    c = 0;
    contadorPatricia (&c, T);
    return (c);
}
