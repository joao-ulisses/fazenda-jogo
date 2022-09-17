#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dinheiro;
    int sementes;
    int batataEstoque;
    int batatasPlantadas;
    int dia;
} tJogador;

void defineJogador(tJogador *jogador)
{
    jogador->dinheiro = 50;
    jogador->sementes = 0;
    jogador->batataEstoque = 0;
    jogador->batatasPlantadas = 0;
    jogador->dia = 1;
}

typedef struct no
{
    int diasRestantes;
    struct no *proximo;
}No;

void plantarBatata(No **batatas, tJogador *jogador)
{
    No *aux, *novo = malloc(sizeof(No));
    if (jogador->sementes > 0) {
        jogador->sementes--;
        jogador->batatasPlantadas++;

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
    } else {
        printf("\nErro, voce nao tem sementes\\n");
        system("PAUSE");
    }
}

void colherBatata(No **fila, tJogador *jogador) {
    No *remover = NULL;
    No *filaValor = NULL;

    if (*fila) {
        filaValor = *fila;
        if (filaValor->diasRestantes == 0) {
            remover = *fila;
            *fila = remover->proximo;
            jogador->batataEstoque++;
            jogador->batatasPlantadas--;
        } else {
            printf("\nSem batatas para colher\n");
            system("PAUSE");
        }
    } else{
        printf("\nSem batatas para colher\n");
        system("PAUSE");
    }
}

int proximaBatata(No *no) {
    if (no) {
        return no->diasRestantes;
    } else {
        return -1;
    }
}

void comprarSementes(tJogador *jogador) {
    int preco = 10;
    if (jogador->dinheiro >= preco) {
        jogador->dinheiro = jogador->dinheiro - preco;
        jogador->sementes++;
    } else {
        printf("\nSem dinheiro suficiente para comprar sementes\n");
        system("PAUSE");
    }
}

void venderBatata(tJogador *jogador) {
    if (jogador->batataEstoque > 0) {
        jogador->batataEstoque--;
        jogador->dinheiro = jogador->dinheiro + 15;
    } else {
        printf("\nSem batatas no estoque para vender\n");
        system("PAUSE");
    }
}

void passarDia(tJogador *jogador, No *batatas) {
    if(batatas){
        if(batatas->diasRestantes != 0) {
            batatas->diasRestantes--;
        }
        if (batatas->proximo != NULL) {
            passarDia(&jogador, batatas->proximo);
        }
    }
    jogador->dia++;
}

void jogar()
{
    char opcaoJogo = '0';
    tJogador jogador;
    No *batatas = NULL;
    defineJogador(&jogador);
    for (;;)
    {
        system("CLS");
        printf("########################################################################################################");
        printf("\n\n\t Batatas plantadas: %d", jogador.batatasPlantadas);
        printf("\t\t\t\t Dia: %d", jogador.dia);
        printf("\n\n\t Proxima batata brota em: %d", proximaBatata(batatas));
        printf("\n\n\t Sementes disponiveis: %d", jogador.sementes);
        printf("\n\n\t Dinheiro: %d", jogador.dinheiro);
        printf("\n\n\t Batatas no estoque: %d", jogador.batataEstoque);
        printf("\n\n\n\n\n\n\n\n");
        printf("\t 0 - Comprar Semente | 1 - Plantar batata | 2 - Colher batata | 3 - Vender Batata | 4 - Passar o dia");
        printf("\n\n\n########################################################################################################\n");

        fflush(stdin);
        opcaoJogo = getchar();

        switch (opcaoJogo)
        {
            case '0':
                comprarSementes(&jogador);
                break;
            case '1':
                plantarBatata(&batatas, &jogador);
                break;
            case '2':
                colherBatata(&batatas, &jogador);
                break;
            case '3':
                venderBatata(&jogador);
                break;
            case '4':
                passarDia(&jogador, batatas);
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
    printf("\n[ 2 ] - Sair\n");
    printf("\n####################################################################################\n");

    fflush(stdin);
    opcao = getchar();
    switch (opcao)
    {
        case '1':
            jogar();
            break;
        case '2':
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
