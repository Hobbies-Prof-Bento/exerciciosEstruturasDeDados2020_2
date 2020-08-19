#include<stdio.h>

/* 2.Crie um vetor de 20 posições com a seguinte sequencia numérica
2,4,6,8,10,... 
Após o preenchimento imprima o vetor
*/

int main(){
	
	int vetor[20];
	for(int i=0;i<20;i++){
		vetor[i]=i*2+2;
	}
	for(int i=0;i<20;i++){
		printf("%d, ",vetor[i]);
	}
	return 0;
}
