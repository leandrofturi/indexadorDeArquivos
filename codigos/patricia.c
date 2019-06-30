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
    liberaPalavra (C->P);
    free (C);
    C = NULL;
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

char letra (int chave) {
    if ((chave >= 0) && (chave <= 9)) {
        return (chave + 58);
    }
    else if ((chave >= 10) && (chave <= 35)) {
        return (chave + 65);
    }
    else if ((chave >= 36) && (chave <= 61)) {
        return (chave + 97);
    }
    else {
        return ('#');
    }
}

char *caminhaPalavra (char *palavra) {
    return (palavra + 1);
}

tPalavra *criaCaminhoPatricia (char *palavra, tCorpo *C) {
    if (palavra == NULL) {
        return (NULL);
    }
    if (C == NULL) {
        C = criaCorpo ( );
    }
    if (strlen (palavra) == 1) {
        return (C->P);
    }
    else {
        char *aux;
        aux = caminhaPalavra (palavra);
        return (criaCaminhoPatricia (aux, C->prox[chave (aux[0])]));
    }
}

void inserePatricia (char *palavra, int posicao, tPatricia *T) {
    if (palavra == NULL) {
        return;
    }
    tPalavra *P;
    P = criaCaminhoPatricia (palavra, (*T)[chave (palavra[0])]);
    if (P == NULL) {
        P = criaPalavra (palavra, posicao);
    }
    else {
        colocaPosicao (posicao, P);
    }
}

tPalavra *buscaPalavraPatricia (char *palavra, tPatricia *T) ;

void imprimeCorpo (tCorpo *C) {
    if (C == NULL) {
        return;
    }
    printf ("%s ", C->P->palavra);
    for (int i = 0; i < R; i ++) {
        imprimeCorpo (C->prox[i]);
    }
}

void imprimePatricia (tPatricia *T) {
    if ((*T) == NULL) {
        return;
    }
    for (int i = 0; i < R; i ++) {
        imprimeCorpo ((*T)[i]);
    }
    printf("\n");
}

int nElementosCorpo (tCorpo *C) {
    if (C != NULL) {
        for (int i = 0; i < R; i ++) {
            if (C->P != NULL) {
                return (1 + (nElementosCorpo (C->prox[i])));
            }
        }
    }
    return (0);
}

int nElementosPatricia (tPatricia *T) {
    if ((*T) == NULL) {
        return (0);
    }
    int aux = 0;
    for (int i = 0; i < R; i ++) {
        aux += nElementosCorpo ((*T)[i]);
    }
    return (aux);
}
