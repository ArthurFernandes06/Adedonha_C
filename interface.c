#include "interface.h"

int leitura_jogadores(ListaJogadores jogadores[])
{
    // Faz a leitura dos jogadores e armazena em um vertor de structs,
    //onde cada struct guarda um nome e a pontuação.
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

    
        n++;
        strcpy(jogadores[i].nome,buffer);
        jogadores[i].pontuacao = 0;
    }
    
    return n;
}
void sorteia_jogadores(Pilha **p, ListaJogadores jogadores[],int total_jogadores)
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
    int indices[total_jogadores];
    for (int i = 0; i < total_jogadores; i++)
        indices[i] = i;

    //Sorteia os indicies
    for (int i = total_jogadores - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);

        int aux = indices[i];
        indices[i] = indices[j];
        indices[j] = aux;
    }

    for(int i =0; i<total_jogadores; ++i)
    {
        push_pilha(p,jogadores[indices[i]].nome);
        printf("\n      %d.%s",i+1,jogadores[indices[i]].nome);
    }

}
char sorteia_letra(char letras[])
{
    //Sorteia uma letra das disponiveis no vetor letras e a remove do vetor.
    int tam_letras = strlen(letras);
    int pos = rand() % tam_letras;
    char saida = letras[pos];
    
    letras[pos] = letras[tam_letras - 1];
    letras[tam_letras - 1] = '\0';
    
    return saida;
}
int buscar_por_nome(ListaJogadores jogadores[],int total_jogadores,char nome[])
{
    for(int i = 0; i<total_jogadores; ++i)
    {
        if(strcmp(nome,jogadores[i].nome) == 0)
        {
            return i;
        }
    }
    return -1;
}
void to_upper(char resposta[])
{
    for (int i = 0; resposta[i] != '\0'; i++)resposta[i] = toupper((unsigned char)resposta[i]);
}
int get_pontuacao(ListaJogadores jogadores[],int total_jogadores,int pos)
{

    float pontuacao = total_jogadores;
    int freq_respostas = 0;
    for(int i =0; i < total_jogadores; ++i)
    {
    
        if(strcmp(jogadores[i].resposta,jogadores[pos].resposta) == 0)
        {
            freq_respostas++;
        }
    
    }
    return pontuacao/freq_respostas;
}
void get_respostas(ListaJogadores jogadores[],int total_jogadores, char letras[],Pilha **p,char *categoria)
{
    // Executa uma rodada do jogo: sorteia letra, sorteia ordem dos jogadores e coleta respostas.
    // Impõe um tempo máximo (8 + 2*N) por jogador, reduzindo 2s a cada atraso acumulado.
    // Valida tamanho da resposta e se começa com a letra sorteada.
    // Armazena as respostas e calcula a pontuação da rodada.
    // Atualiza e exibe a pontuação total dos jogadores ao final.

    int tempo_maximo = 8 + 2 * total_jogadores;
    int pontuacao[total_jogadores][2]; // [pontos][pode_pontuar]
    char letra_sorteada = sorteia_letra(letras);
    char buffer[128], nome_atual[16];

    printf("\nA letra da rodada eh '%c'", letra_sorteada);
    printf("\nA categoria da rodada eh: %s", categoria);

    sorteia_jogadores(p, jogadores, total_jogadores);

    printf("\nPressione ENTER para iniciar a próxima rodada...");
    while(getchar() != '\n');

    for (int i = 0; i < total_jogadores; ++i)
    {
        char *temp = pop_pilha(p);
        strcpy(nome_atual, temp);
        free(temp);

        int pos = buscar_por_nome(jogadores, total_jogadores, nome_atual);

        int size_buffer = 0;
        int saiu_por_tempo = 0;  // 0 = respondeu, 1 = estourou o tempo

        time_t inicio = time(NULL);

        do
        {
            printf("\nDigite sua resposta %s (Tempo max: %d s): ", nome_atual, tempo_maximo);
            fflush(stdout);

            // Verifica se explodiu o tempo antes de tentar ler
            if (time(NULL) - inicio >= tempo_maximo)
            {
                saiu_por_tempo = 1;
            }
            else
            {
    
                if (strcmp("NOME DE PESSOA", categoria) == 0)
                {
                    scanf("%127s", buffer);
                    while (getchar() != '\n');
                }
                else
                {
                    fgets(buffer, sizeof(buffer), stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                }
            }

            if (!saiu_por_tempo)
            {
                to_upper(buffer);
                size_buffer = strlen(buffer);

                if (size_buffer > 30 || size_buffer < 1)
                    printf("\nTamanho de resposta invalido!!!");

                if (buffer[0] != letra_sorteada)
                    printf("\nVoce digitou uma palavra que nao corresponde a letra sorteada.");

            }

        } while ((size_buffer > 30 || size_buffer < 1 || buffer[0] != letra_sorteada) && !saiu_por_tempo);

        if (saiu_por_tempo)
        {
            printf("\n%s estourou o tempo!\n", nome_atual);
            strcpy(jogadores[pos].resposta, "");
            pontuacao[i][1] = 0;
            tempo_maximo -= 2;
            if (tempo_maximo < 1) tempo_maximo = 1;
        }
        else
        {
            strcpy(jogadores[pos].resposta, buffer);
            pontuacao[i][1] = 1; 
        }
    }


    for (int i = 0; i < total_jogadores; ++i)
    {
        if (pontuacao[i][1] == 1)
        {
            pontuacao[i][0] = get_pontuacao(jogadores, total_jogadores, i);
            jogadores[i].pontuacao += pontuacao[i][0];
        }
        else
        {
            pontuacao[i][0] = 0;
        }
    }

    printf("\n         Pontuacao da rodada | Pontuacao Total\n");
    for (int i = 0; i < total_jogadores; ++i)
    {
        printf("\n%s:       %d  |   %d",
               jogadores[i].nome,
               pontuacao[i][0],
               jogadores[i].pontuacao);
    }
}
void ordena_lista(ListaJogadores jogadores[], int total_jogadores)
{
    //Ordena o vetor de structs por ordem de pontuação.
    for(int i = 0; i < total_jogadores - 1; i++)
    {
        for(int j = 0; j < total_jogadores - i - 1; j++)
        {
            if(jogadores[j].pontuacao < jogadores[j+1].pontuacao)
            {
                ListaJogadores temp = jogadores[j];
                jogadores[j] = jogadores[j+1];
                jogadores[j+1] = temp;
            }
        }
    }
}