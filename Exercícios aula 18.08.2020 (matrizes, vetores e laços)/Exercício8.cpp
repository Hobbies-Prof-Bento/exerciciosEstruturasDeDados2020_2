#include<stdio.h>
#include<locale.h>
/*8.Escrever m linhas com i asteriscos alinhadas pela esquerda, onde i corresponde ao número da linha corrente (algoritmo, código). Exemplo: Para m=6 a saída do programa deve ser 
*
**
***
****
*****
******

*/

int main(){	
	setlocale(LC_ALL,"portuguese");
	
	int m;
	
	printf("## WELCOME ##\n\nPor gentileza digite o número de linhas: ");
	scanf("%d",&m);
	
	printf("\n\n");	
	for(int i=0;i<m;i++){
		for(int j=0;j<i;j++){
			printf("* ");	
		}
		printf("\n");		
	}
	return 0;
}
