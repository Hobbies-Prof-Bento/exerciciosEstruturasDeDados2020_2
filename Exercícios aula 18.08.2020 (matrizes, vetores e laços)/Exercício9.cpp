#include<stdio.h>
#include<locale.h>
/*9.Escrever um programa que gere a tabuada de 1 a 10 (algoritmo, código).*/

int main(){	
	setlocale(LC_ALL,"portuguese");
	
	for(int i=0;i<10;i++){
		printf("\n\nTABUADA DO %d\n",i+1);
		for(int j=0;j<=10;j++){
			printf("%d x %d = %d\n",i+1,j,(i+1)*j);			
		}
	}
	return 0;
}
