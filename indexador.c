/*
    Função principal para o trabalho 2 de Estruturas de dados I, ministrada por Vinicius Fernandes Soares Mota.
    Autores: Leandro Furlam Turi
             Isauflania Suellen Ribeiro Timoteo
    06 de julho de 2019.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecas/leitura.h" // Leitura dos arquivos.
#include "bibliotecas/avaliacao.h" // Avaliacao das TADs.

int main (int argc, char *argv[]) {
    int n, qtd;
    char **caminhos;
    caminhos = (char**) malloc ((argc-2)*(sizeof (char*)));

    n = atoi (argv[argc-1]); // Quantidade a ser buscada
    qtd = argc-2; // Quantidade de arquivos
    for (int i = 1; i < qtd; i ++) {
        caminhos[i-1] = argv[i];
    }

    limpaValgrind (caminhos, &qtd, &n); // Limpar flags do valgrind
    if (argc >= 3) {
        avaliaDesempenho (caminhos, qtd, n);
    }

    if (argc > 1) {
        buscaPalavra (caminhos, qtd); // Funcao que funciona sozinha.
    }
    free (caminhos);
    
    return (0);
}

/*
POR FAVOR NOS DE NOTA
00000000______0000000000______00000000
000000___0____000000000________0000000
00000___00____00000000____00____000000
0000___000____0000000____0000____00000
000___0000____000000____000000____0000
0000000000____000000____000000____0000
0000000000____000000____000000____0000
0000000000____0000000____0000____00000
0000000000____00000000____00____000000
0000000000____000000000________0000000
*/
