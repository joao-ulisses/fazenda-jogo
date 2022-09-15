#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int energia;
    int dinheiro;
    int sementes;
    int batataEstoque;
} tJogador;

void defineJogador(tJogador *jogador)
{
    jogador->energia = 100;
    jogador->dinheiro = 50;
    jogador->sementes = 0;
    jogador->batataEstoque = 0;
}

typedef struct no
{
    int diasRestantes;
    struct no *proximo;
}No;

void plantarBatata(No **batatas)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo) {
        novo->diasRestantes = 2;
        novo->proximo = NULL;
        if(*batatas == NULL) {
            *batatas = novo;
        } else {
            aux = *batatas;
            while (aux->proximo) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    } else {
        printf("\nErro ao alocar na memoria.\n");
    }
}

void colherBatata(No **fila) {
    No *remover = NULL;

    if (*fila) {
        remover = *fila;
        *fila = remover->proximo;
    } else {
        printf("\nSem batatas para colher");
    }
}

int imprimir(No *no){
    int cont = 0;
    if(no){
        cont++;
        imprimir(no->proximo);
    } else {
        return cont;
    }
}

void jogar()
{
    //comoJogar();
    char opcaoJogo = '0';
    int dia = 0;
    tJogador jogador;
    defineJogador(&jogador);
    No *batatas = NULL;
    for (;;)
    {
        system("CLS");
        printf("####################################################################################");
        printf("\n\n\n\t Energia: %d", jogador.energia);
        printf("\t\t\t\t Dia: %d", dia);
        printf("\n\n\t Batatas plantadas: %d", imprimir(batatas));
        printf("\n\n\t Proxima batata brota em: ");
        printf("\n\n\t Sementes disponiveis: %d", jogador.sementes);
        printf("\n\n\t Dinheiro: %d", jogador.dinheiro);
        printf("\n\n\t Batatas no estoque: %d", jogador.batataEstoque);
        printf("\n\n\n\n\n\n\n\n");
        printf("\t 0 - Colher Batata | 1- Vender batata | 2- Comprar semente | 4- Passar dia");
        printf("\n\n\n####################################################################################");

        fflush(stdin);
        opcaoJogo = getchar();

        switch (opcaoJogo)
        {
            case '0':
                colherBatata(&batatas);
                break;
            case '1':
                //venderBatata();
                break;
            case '2':
                //comprarSementes();
                break;
            case '3':
                plantarBatata(&batatas);
                break;
            case '4':
                //passarDia();
                break;
            default:
                printf("\nOpcao invalida\n");
                system("PAUSE");
        }
   }
}



int menu()
{
    char opcao = '0';

    system("cls");
    printf("\n#################################Fazenda Padulisses#################################\n");
    printf("\n[ 1 ] - Jogar");
    printf("\n[ 2 ] - Como jogar");
    printf("\n[ 3 ] - Sair\n");
    printf("\n####################################################################################\n");

    fflush(stdin);
    opcao = getchar();
    switch (opcao)
    {
        case '1':
            jogar();
            break;
        case '2':
            //comoJogar();
            break;
        case '3':
            return 0;
        default:
            printf("\nOpcao invalida\n");
            system("PAUSE");
    }
    return 1;
}

int main()
{
    while(menu())
    {
    }
    return 0;
}
