#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/*2. Criem um programa em C que manipule um vetor de 10 posições de inteiro e possua os menus abaixo:
1-Preenche o Vetor
2-Ordena o Vetor por Bubble Sort
3-Imprime o Vetor
4-Sair
*/

int vetor[10]={3,2,4,5,1,10,8,9,7,6};

void preencheVetor(){
	for(int i=0;i<10;i++){
		printf("\nDigite o %dº valor do vetor: ",i+1);
		scanf("%d",&vetor[i]);
		}
	printf("Operação concluida!!\n\n\n");
	system("pause");	
	}
	
void imprimeVetor(){
	printf("\n\nOs valores do vetor são: ");	
	for(int i=0;i<10;i++){
			printf("%d-",vetor[i]);		
	}
	printf("\n\n\n");
	system("pause");	
}

void bubbleSort(){
	int vetorAux[10]={0,0,0,0,0,0,0,0,0,0};
	int auxiliar,j, verificador = 1, soma =0;
	
	while(verificador !=0){
		
		for(int i=0;i<9;i++){
			auxiliar = vetor[i];
			j = i+1;
			if(vetor[i]>vetor[j]){
				vetor[i]=vetor[j];
				vetor[j]=auxiliar;
			}		
		}
		for(int i=0;i<10;i++){			
			soma+=abs(vetor[i]-vetorAux[i]);			
		}
		for(int i=0;i<10;i++){
			vetorAux[i]=vetor[i];		
		}		
		verificador = soma;
		soma = 0;	
	}
	printf("\n\nOperação concluída!!\n\n");
	printf("\n\n\n\n");
	system("pause");
	
	
}

int main(){
	setlocale(LC_ALL,"portuguese");
	
	int opcao;
		
	system("cls");
			
	printf("BEM-VINDO");
	printf("\n\nPor gentileza escolha uma opção:");
	printf("\n1-Preenche o vetor \n2-Ordena o vetor por Bubble Sort \n3-Imprime o vetor \n4-sair\n\nSeleção: ");
	scanf("%d",&opcao);	
		
	switch(opcao){
		case 1:
			preencheVetor();
			main();
			break;			
				
		case 2:
			bubbleSort();
			main();
			break;
			
		case 3:
			imprimeVetor();
			main();
			break;
			
		case 4:
			return 0;
			break;
			
		default:
			printf("\nOpção incorreta, aperte ENTER e digite novamente!!");
			printf("\n\n\n");
			system("pause");
			main();								
	}	
	
	
	return 0;
}
