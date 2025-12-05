#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "interface.h"

int read_categorias(Pilha **p,char categorias[][32], int max)
{
    FILE *fin = fopen("categorias.txt","r");
    if(fin == NULL)
    {
        return -1;
    }
    char buffer[128];
    int cont =0;

    while (fgets(buffer, sizeof(buffer), fin) && cont < max)
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        strncpy(categorias[cont], buffer, 31);
        categorias[cont][31] = '\0';

        cont++;
    }
    fclose(fin);

    //Embaralhar as categorias
    for (int i = cont - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);

        char aux[32];
        strcpy(aux, categorias[i]);
        strcpy(categorias[i], categorias[j]);
        strcpy(categorias[j], aux);
    }
    for(int i = 0; i <cont; ++i)
    {
        to_upper(categorias[i]);
        push_pilha(p,categorias[i]);
    }
    return cont;
}

int main()
{
    srand(time(NULL));
    Pilha *p_jogadores = NULL;
    Pilha *p_categorias;
    ListaJogadores jogadores[12];
    char letras[] = "ABCDEFGHIJLMNOPQRTUVXZ";
    int total_jogadores = leitura_jogadores(jogadores);
    char categorias[23][32];
    int total_categorias = read_categorias(&p_categorias,categorias,23);
    char categoria_atual[32];
    for(int i = 0; i < total_categorias; ++i)
    {
        char *ps = pop_pilha(&p_categorias);
        strcpy(categoria_atual,ps);
        free(ps);
        get_respostas(jogadores,total_jogadores,letras,&p_jogadores,categoria_atual);
        ordena_lista(jogadores,total_jogadores);
    }

    return 0;
}