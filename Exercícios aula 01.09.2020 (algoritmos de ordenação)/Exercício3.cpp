#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/*3. Acrescente no exercício anterior um menu Desempenho para informar quantas 
comparações foram feitas e quantas trocas foram feitas.*/

int vetor[10]={3,2,4,5,1,6,8,9,7,10};
int contComparacao=0, contTroca=0;

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
	int contComparacao=0, contTroca=0;
	int vetorAux[10]={0,0,0,0,0,0,0,0,0,0};
	int auxiliar,j, verificador = 1, soma =0,size=9;	
	
	while(verificador !=0){
		
		/*printf("\nVetor de entrada: ");
		for(int i=0;i<10;i++)
			printf("%d - ",vetor[i]);*/
		
		for(int i=0;i<size;i++){
			auxiliar = vetor[i];
			j = i+1;
			contComparacao++;
			//printf("\ncomparacao: %d , %d com %d",contComparacao,vetor[i],vetor[j]);
			if(vetor[i]>vetor[j]){
				vetor[i]=vetor[j];
				vetor[j]=auxiliar;
				contTroca++;
			//	printf("\ntroca: %d , %d por %d",contTroca,vetor[i],vetor[j]);
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
		size--;	
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
	printf("\n1-Preenche o vetor \n2-Ordena o vetor por Bubble Sort \n3-Desempenho \n4-Imprime o vetor \n5-sair\n\nSeleção: ");
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
			printf("\n\nDESEMPENHO");
			printf("\nNumero de comparações: %d",contComparacao);
			printf("\nNumero de trocas: %d",contTroca);
			
			printf("\n\n\n");
			system("pause");
			main();
			break;
			
		case 4:
			imprimeVetor();
			main();
			break;
			
		case 5:
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
