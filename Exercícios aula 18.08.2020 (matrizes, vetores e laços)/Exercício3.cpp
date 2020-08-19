#include<stdio.h>

/*3.Crie um vetor de 20 posições com a seguinte sequencia numérica
1,-1,1,-1,1,...
Após o preenchimento imprima o vetor
*/

int main(){
	
	int vetor[20];
	int resultado = 1;
	for(int i=0;i<20;i++){
		vetor[i]=resultado;
		resultado *=-1;
	}
	for(int i=0;i<20;i++){
		printf("%d, ",vetor[i]);
	}
	return 0;
}
