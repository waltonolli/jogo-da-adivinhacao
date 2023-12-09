#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {
    setlocale(LC_ALL, "Portoguese");

    int numero;
    printf("Tabuada de qual número você quer?\n");
    scanf("%d", &numero);

    for(int i = 1; i <=10; i++) {

         int multiplicacao = numero * i;
         printf("%d * %d = %d\n",numero, i, multiplicacao);
    }

    
}