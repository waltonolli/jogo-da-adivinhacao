#include <stdio.h>
#include <locale.h>

int main () {
    setlocale(LC_ALL, "Portuguese");

    // for (int i = 0; i <= 100; i++)
    // {
    //  printf("%d\n", i);
    // }

    // int i = 1;
    // while (i<=100)
    // {
    //     printf("%d\n", i);
    //     i++;
    // }


    int i = 1;
    int soma = 0;

    // while (i<=100)
    // {
    //     soma = soma + i;
    //     i++;
                
    //     printf("%d\n", soma);
        
    // }

    for(int i = 1; i <= 100; i++) {
        soma = soma + i;
    }

    printf("A soma eh %d", soma);
    
}