#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/leituraArquivo.h"

int leituraArquivo (char *caminhoArq, int estrutura)
{
    int nC, nP;
    char c, palavraMax[189819], *palavra;
    FILE *arq;

    arq = fopen (caminhoArq, "r");
    if (arq == NULL)
        return (1);
    else
    {
        nC = nP = 0;
        while ((c = fgetc (arq)) != EOF)
        {
		nP ++;
            if (((c >= 'a') && (c <= 'z')) ||
                ((c >= 'A') && (c <= 'Z')) ||
                ((c >= '0') && (c <= '9')))
            {
                palavraMax[nC] = c;
                nC ++;
            }
            else
            {
                palavraMax[nC] = '\0';
                palavra = (char*) malloc ((nC + 1) * sizeof (char));
                strcpy (palavra, palavraMax);
                nC = 0;
                switch (estrutura)
                {
                    case 1:                                                     // Lista encadeada

                    break;

                    case 2:                                                     // Arvore binaria nao balanceada

                    break;

                    case 3:                                                     // Arvore binaria balanceada (AVL)

                    break;

                    case 4:                                                     // Arvores de prefixo (TRIE)

                    break;

                    case 5:                                                     // Tabela Hash

                    break;

                    default:
                        return (1);
                }
            }
        }
    }

    fclose (arq);
    return (0);
}
