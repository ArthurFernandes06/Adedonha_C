#ifndef INTERFACE_H
#define INTERFACE_H
    #include<time.h>
    #include<stdlib.h>
    #include<stdio.h>
    #include<string.h>
    #include<ctype.h>
    #include"estrutura_de_dados.h"

    int leitura_jogadores(ListaJogadores jogadores[]);
    void sorteia_jogadores(Pilha **p, ListaJogadores jogadores[],int total_jogadores);
    char sorteia_letra(char letras[]);
    int buscar_por_nome(ListaJogadores jogadores[],int total_jogadores,char nome[]);
    void to_upper(char resposta[]);
    int get_pontuacao(ListaJogadores jogadores[],int total_jogadores,int pos);
    void get_respostas(ListaJogadores jogadores[],int total_jogadores,char letras[], Pilha **p,char *categoria);
    void ordena_lista(ListaJogadores jogadores[],int total_jogadores);
    #endif
