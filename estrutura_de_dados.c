//Arthur Rodrigues Fernandes 580801
#include "estrutura_de_dados.h"

void push_pilha(Pilha **p, char nome[])
{
    Pilha *novo = malloc(sizeof(Pilha));
    if(novo == NULL)
    {
        printf("\nErro em armazenar jogador na memoria.");
        return;
    }
    
    strcpy(novo->nome,nome);
    if((*p) == NULL)
    {
        novo->prox = NULL;
        (*p)=novo;
        return;
    }
    novo->prox = (*p);
    (*p) = novo;
}

char *pop_pilha(Pilha **p)
{
    // Remove o elemento do topo da pilha e retorna uma cópia de sua string.
    // Caso a pilha esteja vazia, retorna NULL.
    // A função aloca memória para a string retornada; o chamador deve liberá-la.
    // O nó removido da pilha é devidamente liberado.
    // Mantém a pilha consistente ajustando o ponteiro para o próximo nó.

    if((*p) == NULL)
    {
        return NULL;

    }
    char *s = malloc(strlen((*p)->nome) +1);
    if(s == NULL)
    {
        return NULL;
    }
    strcpy(s,(*p)->nome);
    Pilha *removido = (*p);
    (*p) = (*p)->prox;
    free(removido);
    return s;

}
