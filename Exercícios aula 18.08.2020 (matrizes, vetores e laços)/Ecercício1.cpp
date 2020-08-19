#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int imprimeResultado(float valores[5]){
	system("cls");
	printf("O resultado é: ");
	for(int i=0;i<5;i++){
		printf("%.2f,",valores[i]);
	}
	return 0;
}


int main(){
	
	setlocale(LC_ALL,"portuguese");

	float vetor1[5];
	float vetor2[5];
	float resultado[5];
	int opcao;
	
	printf("### WELCOME ###");
	for(int i=0;i<10;i++){
		if(i<5){
			printf("\nPor gentileza digite o %dº número do primeiro vetor: ",i+1);
			scanf("%f",&vetor1[i]);		
		}
		else{
			printf("\nPor gentileza digite o %dº número do segundo vetor: ",i-4);
			scanf("%f",&vetor2[i-5]);
		}
	}
	a:
	printf("\n\nPor gentileza escolha uma opção:");
	printf("\n1-soma\n2-subtração\n3-multiplicação\n4-divisão\nopção: ");
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
			for(int i=0;i<5;i++){
				resultado[i]=vetor1[i]+vetor2[i];
			}
			imprimeResultado(resultado);
			break;
		case 2:
			for(int i=0;i<5;i++){
				resultado[i]=vetor1[i]-vetor2[i];
			}
			imprimeResultado(resultado);
			break;
		case 3:
			for(int i=0;i<5;i++){
				resultado[i]=vetor1[i]*vetor2[i];
			}
			imprimeResultado(resultado);
			break;
		case 4:
			for(int i=0;i<5;i++){
				resultado[i]=vetor1[i]/vetor2[i];
			}
			imprimeResultado(resultado);
			break;
		default:			
			printf("\nOpção inválida\n\n");
			goto a;
	}	

}
