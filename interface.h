#ifndef INTERFACE_H
#define INTERFACE_H
    #include<time.h>
    #include<stdlib.h>
    #include<stdio.h>
    #include<string.h>
    #include"estrutura_de_dados.h"

    int leitura_jogadores(char *nomes[]);
    void sorteia_jogadores(Pilha **p, char *nomes[],int jogadores);
    char sorteia_letra(char letras[]);
#endif
