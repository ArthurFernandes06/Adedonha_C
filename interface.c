#include "interface.h"

int leitura_jogadores(char *nomes[])
{
    // Faz a leitura dos jogadores e armazena em um vertor de ponteiros para char,
    //onde cada ponteiro aponta para um nome.
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
void sorteia_jogadores(Pilha **p, char *nomes[],int jogadores)
{
    /*
        Uma função para adicionar os jogadores a uma pilha
        em ordem aleatoria.

        Entrada:
            1) A pilha que os jogadores serão adicionados;
            2) O vetor de ponteiros com os nomes;
            3) O total de jogadores.
    */
    // cria vetor de índices
    int indices[jogadores];
    for (int i = 0; i < jogadores; i++)
        indices[i] = i;

    //Sorteia os indicies
    for (int i = jogadores - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);

        int aux = indices[i];
        indices[i] = indices[j];
        indices[j] = aux;
    }

    for(int i =0; i<jogadores; ++i)
    {
        push_pilha(p,nomes[indices[i]]);
    }

}
char sorteia_letra(char letras[])
{
    int tam_letras = strlen(letras);
    int pos = rand() % tam_letras;
    char saida = letras[pos];
    
    letras[pos] = letras[tam_letras - 1];
    letras[tam_letras - 1] = '\0';
    
    return saida;
}
