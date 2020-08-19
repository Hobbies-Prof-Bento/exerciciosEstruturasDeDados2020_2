#include<stdio.h>
#include<math.h>

/*4.Crie um vetor de 20 posições com a seguinte sequencia numérica
2,4,8,16,32,...
Após o preenchimento imprima o vetor
*/

int main(){
	
	int vetor[20];
	for(int i=1;i<=20;i++){
		vetor[i-1]=pow(2,i);
	}
	for(int i=0;i<20;i++){
		printf("%d, ",vetor[i]);
	}
	return 0;
}
