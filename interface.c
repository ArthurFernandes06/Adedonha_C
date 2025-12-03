#include "interface.h"

int leitura_jogadores(char *nomes[])
{
    char buffer[128];
    int d;
    int n = 0;
    do{
        printf("\nQuantos Jogadores irao participar? ");
        scanf("%d",&d);
        //Limpar o buffer
        while(getchar() != '\n');
        if(d<2 || d>12)
        {
            printf("\nNumero de jogadores invalido!!");
        }
        
    }while(d<2 || d>12);

    for(int i =0; i < d; ++i)
    {
        do
        {
            printf("\nDigite o nome do jogador %d: ", i+1);
            scanf("%127s",buffer);
            //Limpar as entradas no terminal
            while(getchar() != '\n');

            if(strlen(buffer) > 12 || strlen(buffer) < 1)
            {
                printf("\nTamanho de nome invalido!!!");
            }
            
        }while(strlen(buffer) > 12 || strlen(buffer) < 1);

        nomes[i] = malloc(strlen(buffer) + 1);
        if(nomes[i] == NULL) {
            printf("Erro de memoria!\n");
            return - 1;
        }
        n++;
        strcpy(nomes[i],buffer);
    }
    for(int i = d; i < 12; ++i)
    {
        nomes[i] = NULL;
    }
    return n;
}