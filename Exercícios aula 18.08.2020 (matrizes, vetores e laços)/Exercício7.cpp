#include<stdio.h>
#include<locale.h>
/*7. Leia dois números no teclado, X e y. Imprima a quantidade de asteriscos de acordo com os valores de X e Y, ex. Se ler 5 e 4, imprime: 
*****
*****
*****
*****
*/

int main(){	
	setlocale(LC_ALL,"portuguese");
	
	int x,y;
	
	printf("## WELCOME ##\n\nPor gentileza digite o número de asteríscos em x: ");
	scanf("%d",&x);
	printf("\nPor gentileza digite o número de asteríscos em y: ");
	scanf("%d",&y);
	printf("\n\n");	
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			printf("*");	
		}
		printf("\n");		
	}
	return 0;
}
