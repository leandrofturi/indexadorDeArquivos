#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/hash.h"

tHash* criaHash ( ) {
	tHash *H;
	H = (tHash*) malloc (sizeof (tHash));
	for (int i = 0; i < M; i ++) {
		(*(H))[i] = criaEncadeada ( );
	}
	return (H);
}

void liberaHash (tHash *H) {
	for (int i = 0; i < M; i ++) {
		liberaEncadeada ((*(H))[i]);
	}
	free (H);
}

int hash (char *palavra) {
	int h;
	h = 1;
	for (int i = 0; palavra[i] != '\0'; i ++) {
		h = (h * 251 + palavra[i]) % M;
	}
	return h;
}

void insereHash (char *palavra, int posicao, tHash *H) {
	insereEncadeada (palavra, posicao, (*(H))[hash (palavra)]);
}

tPalavra *buscaPalavraHash (char *palavra, tHash *H) {
	tPalavra *P;
	P = buscaPalavraEncadeada (palavra, (*(H))[hash (palavra)]);
	return (P);
}

void imprimeHash (tHash *H) {
	for (int i = 0; i < M; i ++) {
		printf ("%d: ", i);
		imprimeEncadeada ((*(H))[i]);
		printf ("\n");
	}
	medidasHash (H);
}

void medidasHash (tHash *H) {
	int nElementos, colisoes, n;
	float carga;
	nElementos = 0;
	colisoes = 0;

	for (int i = 0; i < M; i ++) {
	 	n = nElementosEncadeada ((*(H))[i]);
		nElementos += n;
		if (n != 0) {
			colisoes += n;
		}
	}
	carga = ((float) nElementos) / ((float) M);

	printf ("Quantidade de elementos: %d\n", nElementos);
	printf ("Quantidade de colisoes: %d\n", colisoes);
	printf ("Fator de carga: %.2f\n", carga);
}
