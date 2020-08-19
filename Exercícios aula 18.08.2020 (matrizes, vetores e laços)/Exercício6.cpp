#include<stdio.h>
#include<locale.h>
/*6. Leia um valor do teclado e imprima a correspondente quantidade de asteriscos. Ex. Se ler o numero 6 imprima ******/

int main(){	
	setlocale(LC_ALL,"portuguese");
	
	int quantidadeAsteriscos;
	
	printf("## WELCOME ##\n\nPor gentileza digite o número de asteríscos:");
	scanf("%d",&quantidadeAsteriscos);
	printf("\n\n");	
	for(int i=0;i<quantidadeAsteriscos;i++){
		printf("*");
	}
	return 0;
}

