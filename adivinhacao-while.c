#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define NUMERO_DE_TENTATIVAS 5 //constantes s�o declarada fora do main()

int main() {

    setlocale(LC_ALL, "Portuguese");

    // imprime cabe�alho do jogo na tela
    printf("*******************************************\n");
    printf("*                                         *\n");
    printf("*   Bem vindo(a) ao jogo de adivinha��o   *\n");
    printf("*                                         *\n");
    printf("*******************************************\n");

    int segundos = time(0); //numero em segundos do tempo de 01/01/1970 at� agora. precisa do #include <time.h>
    srand(segundos); //fun��o para usar o numero randomico.
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100; // % � o resto da divis�o

    int chute; //variavel inicializada, mas no C ele tem algum valor.
    int tentativas = 1;
    double pontos = 1000; //double � usado para n�meros quebrados (com n�meros ap�s a v�rgula)

    //for (int i = 1; i <= NUMERO_DE_TENTATIVAS; i++)
    while (1) //usado para loops que n�o sabe quando vai acabar.
    {   
        printf("Tentativa %d\n", tentativas); 
        printf("Qual � o seu chute? ");
        scanf("%d", &chute);
        //printf("Seu chute foi %d\n", chute);

        if(chute < 0) {
            printf("Voc� n�o pode chutar n�meros negativos!\n");
            continue;
        }

        int acertou = (chute == numerosecreto);
        int chutemaiorquenumerosecreto = chute > numerosecreto;

        if (acertou) {
            printf("Parab�ns, voc� acertou o n�mero secreto!\n");
            break;
        }
        
        else if (chutemaiorquenumerosecreto) {
            printf("O n�mero secreto � menor\n");
        }
        
        else {
            printf("O n�mero secreto � maior\n");
        }
    
        tentativas ++;

        // double pontosperdidos = (double)(chute-numerosecreto) / (double)2; //double na frente do doi para representar um numero double ao inves de inteiro.
        // if (pontosperdidos < 0) {
        //     pontosperdidos = pontosperdidos* -1;
        // }
        
        double pontosperdidos = abs(chute - numerosecreto) / (double)2; //abs devolve o valor absoluto(sem sinal, ou seja positivo) do n�mero.
        
        pontos = pontos - pontosperdidos;
    }
    
    printf("Fim de jogo!\n");
    printf("Voc� acertou em %d tentativas!\n", tentativas);
    printf("Total de pontos: %.1f\n", pontos); //mascara do double � %f - o .1 quer dizer a quantidade de decimais que queremos mostrar.
}