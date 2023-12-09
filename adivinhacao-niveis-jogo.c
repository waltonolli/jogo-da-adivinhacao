#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {

    setlocale(LC_ALL, "Portuguese");

    // imprime cabeçalho do jogo na tela
    printf("\n\n");
    printf("**************************************************************\n");
    printf("*    ____                         _           _         _    *\n");
    printf("*   | __ )  ___ _ __ ___   __   _(_)_ __   __| | ___   | |   *\n");
    printf("*   |  _ \\ / _ \\ '_ ` _ \\  \\ \\ / / | '_ \\ / _` |/ _ \\  | |   *\n");
    printf("*   | |_) |  __/ | | | | |  \\ V /| | | | | (_| | (_) | |_|   *\n");
    printf("*   |____/ \\___|_| |_| |_|   \\_/ |_|_| |_|\\__,_|\\___/  (_)   *\n");
    printf("*                                                            *\n");
    printf("*                   ao jogo de adivinhação                   *\n");
    printf("*                                                            *\n");
    printf("**************************************************************\n");
    printf("\n\n");

    int segundos = time(0); //numero em segundos do tempo de 01/01/1970 até agora. precisa do #include <time.h>
    srand(segundos); //função para usar o numero randomico.
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;

    int chute;
    int tentativas = 1;
    double pontos = 1000;
    int acertou = 0;

   int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Digite: ");
    scanf("%d", &nivel);

    int numerodetentativas;

    switch(nivel) {
        case 1:
            numerodetentativas = 20;
            break;
        case 2:
            numerodetentativas = 15;
            break;
        default:
            numerodetentativas = 6;
            break;
    }

    // if(nivel == 1) {
    //     numerodetentativas = 20;
    // }
    // else if (nivel == 2){
    //     numerodetentativas = 15;
    // }
    // else {
    //     numerodetentativas = 6;
    // }

    for (int i = 1; i <= numerodetentativas; i++) 
    {   
        printf("Tentativa %d\n", tentativas); 
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }

        acertou = (chute == numerosecreto);
        int chutemaiorquenumerosecreto = chute > numerosecreto;

        if (acertou) {
            break;
        }
        else if (chutemaiorquenumerosecreto) {
            printf("O número secreto é menor\n");
        }
        
        else {
            printf("O número secreto é maior\n");
        }
    
        tentativas ++;
        
        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        
        pontos = pontos - pontosperdidos;
    }
    
    printf("Fim de jogo!\n");
    
    if (acertou) {
        printf("\n\n");
        printf("**************************************************************\n");
        printf("*                                                            *\n");
        printf("*        ____                 _       __                     *\n");
        printf("*       |  _ \\ __ _ _ __ __ _| |__   /_/ _ __  ___           *\n");
        printf("*       | |_) / _` | '__/ _` | '_ \\ / _ \\ '_ \\/ __|          *\n");
        printf("*       |  __/ (_| | | | (_| | |_) |  __/ | | \\__ \\          *\n");
        printf("*       |_|   \\__,_|_|  \\__,_|_.__/ \\___|_| |_|___/          *\n");
        printf("*               Você acertou o número secreto!               *\n");
        printf("*                                                            *\n");
        printf("*                                                            *\n");
        printf("**************************************************************\n");
        printf("*                                                            *\n");
        printf("*  Você acertou em %d tentativas!                             *\n", tentativas);
        printf("*  Total de pontos: %.1f                                    *\n", pontos);
        printf("*                                                            *\n");
        printf("**************************************************************\n");
        printf("\n\n");
    } else {
        printf("\n\n");
        printf("*************************************\n");
        printf("*                                   *\n");
        printf("*          \\|/ ____ \\|/             *\n");
        printf("*           @~/ ,. \\~@              *\n");
        printf("*          /_( \\__/ )_\\             *\n");
        printf("*             \\__U_/                *\n");
        printf("*   Você perdeu, tente novamente!   *\n");
        printf("*                                   *\n");
        printf("*************************************\n");
        printf("\n\n");
    }
    
    
}