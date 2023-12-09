#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define NUMERO_DE_TENTATIVAS 5 //constantes são declarada fora do main()

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
    int numerosecreto = numerogrande % 100; // % é o resto da divisão

    int chute; //variavel inicializada, mas no C ele tem algum valor.
    int tentativas = 1;
    double pontos = 1000; //double é usado para números quebrados (com números após a vírgula)

    //for (int i = 1; i <= NUMERO_DE_TENTATIVAS; i++)
    while (1) //usado para loops que não sabe quando vai acabar.
    {   
        printf("Tentativa %d\n", tentativas); 
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        //printf("Seu chute foi %d\n", chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }

        int acertou = (chute == numerosecreto);
        int chutemaiorquenumerosecreto = chute > numerosecreto;

        if (acertou) {
            printf("Parabéns, você acertou o número secreto!\n");
            break;
        }
        
        else if (chutemaiorquenumerosecreto) {
            printf("O número secreto é menor\n");
        }
        
        else {
            printf("O número secreto é maior\n");
        }
    
        tentativas ++;

        // double pontosperdidos = (double)(chute-numerosecreto) / (double)2; //double na frente do doi para representar um numero double ao inves de inteiro.
        // if (pontosperdidos < 0) {
        //     pontosperdidos = pontosperdidos* -1;
        // }
        
        double pontosperdidos = abs(chute - numerosecreto) / (double)2; //abs devolve o valor absoluto(sem sinal, ou seja positivo) do número.
        
        pontos = pontos - pontosperdidos;
    }
    
    printf("Fim de jogo!\n");
    printf("Você acertou em %d tentativas!\n", tentativas);
    printf("Total de pontos: %.1f\n", pontos); //mascara do double é %f - o .1 quer dizer a quantidade de decimais que queremos mostrar.
}