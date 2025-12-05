#ifndef ESTRUTURA_H
#define ESTRUTURA_H
    #include <time.h>
    #include <stdlib.h>
    #include<stdio.h>
    #include<string.h>

    typedef struct Pilha
    {
        char nome[16];
        struct Pilha *prox;
    }Pilha;

    typedef struct ListaEncadeada
    {
        char letra;
        int posicao;
        struct ListaEncadeada *prox;
    }ListaEncadeada;
    
    void push_pilha(Pilha **p, char nome[]);
    char *pop_pilha(Pilha **p);

    
#endif