#include <stdio.h>

int main() {

    int x;
	int y;


	printf("Digite um numero: ");
	scanf("%d", &x);

	printf("Digite outro numero: ");
	scanf("%d", &y);

    int resultado = x*y;
	printf("A multiplicacao de %d e %d e: %d", x, y, resultado);
}