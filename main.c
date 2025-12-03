#include <stdlib.h>
#include <stdio.h>
#include "interface.h"
#include "jogadas.h"

int main()
{
    char *nomes[12];
    int n = leitura_jogadores(nomes);
    for(int i = 0; i < n; ++i)
    {
        printf("\n%s", nomes[i]);
    }
    return 0;
}