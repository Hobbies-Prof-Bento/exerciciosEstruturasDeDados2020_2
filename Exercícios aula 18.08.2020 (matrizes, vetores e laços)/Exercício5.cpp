#include<stdio.h>
#include<math.h>

/*5.Crie um  vetor de 10 posições com a seguinte sequencia numérica
1,2,4,8,16,32,...
Um segundo vetor receber a subtração do segundo elemento com o primeiro, do terceiro com o primeiro, etc
Após o preenchimento imprima o vetor
*/

int main(){
	
	int vetor1[10];
	int vetor2[9];
	
	for(int i=0;i<10;i++){
		vetor1[i]=pow(2,i);		
	}
	for(int i=0;i<9;i++){
		vetor2[i]=vetor1[i+1]-vetor1[0];
	}
	
	for(int i=1;i<9;i++){
		printf("%d, ",vetor2[i]);
	}
	return 0;
}
