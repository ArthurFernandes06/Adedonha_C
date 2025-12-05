#include <stdlib.h>
#include <stdio.h>
#include "interface.h"


int main()
{
    Pilha *p = NULL;
    char *nomes[12];
    int total_jogadores = leitura_jogadores(nomes);
    sorteia_jogadores(&p,nomes,total_jogadores);
    for(int i = 0; i < total_jogadores; ++i)
    {
        printf("\n%s", pop_pilha(&p));
    }
    return 0;
}