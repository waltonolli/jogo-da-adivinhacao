#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {

    setlocale(LC_ALL, "Portuguese");

    // imprime cabeçalho do jogo na tela
    printf("*******************************************\n");
    printf("*                                         *\n");
    printf("*   Bem vindo(a) ao jogo de adivinhação   *\n");
    printf("*                                         *\n");
    printf("*******************************************\n");

    int segundos = time(0); //numero em segundos do tempo de 01/01/1970 até agora. precisa do #include <time.h>
    srand(segundos); //função para usar o numero randomico.
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;

    int chute;
    int tentativas = 1;
    double pontos = 1000;
    int acertou = 0;

    int numerodetentativas = 5;
    

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
        printf("Parabéns, você acertou o número secreto!\n");
        printf("Você acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    } else {
        printf("Você perdeu, tente novamente!");
    }
    
    
}