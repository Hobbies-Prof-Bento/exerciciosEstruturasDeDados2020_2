#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/*5. Criem um programa em C que manipule um vetor de 10 posições de inteiro e possua os menus abaixo, use como base o programa anterior:
1 - Preenche o Vetor
2 - Ordena o Vetor por Bubble Sort
3 - Ordena o Vetor por Selection Sort 
4 - Ordena o Vetor por Insertion Sort
5 - Desempenho 
	1 - Quantidade de comparações 
	2 - Quantidade de trocas
6 - Imprime o Vetor
7 - Sair
*/

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
	contComparacao=0;
	contTroca=0;
	
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

void selectionSort(){
	contComparacao=0;
	contTroca=0;
	
	int auxiliar,indice;	
		
	for(int i=0;i<9;i++){
		auxiliar = vetor[i];
		indice = i;
			
		for(int j=i+1;j<10;j++){
			contComparacao++;
			//printf("\ncomparacao: %d , %d com %d",contComparacao,vetor[i],vetor[j]);
			if(auxiliar>vetor[j]){
				auxiliar = vetor[j];
				indice = j;				
			}			
		}
		vetor[indice]=vetor[i];
		vetor[i]=auxiliar;
		if(indice!=i){
			contTroca++;
			//printf("\ntroca: %d , %d por %d",contTroca,vetor[i],vetor[indice]);
		}			
	}
	printf("\n\nOperação concluída!!\n\n");
	printf("\n\n\n\n");
	system("pause");	
}

void insertionSort(){
	contComparacao=0;
	contTroca=0;
	
	int auxiliar,j,k;
	
	for(int i=0;i<9;i++){
		j=i+1;
		k=i;
		for(j;j>0;j--,k--){
			contComparacao++;
			//printf("\ncomparacao: %d , %d com %d",contComparacao,vetor[k],vetor[j]);
			if(vetor[k]>vetor[j]){
				auxiliar=vetor[j];
				vetor[j]=vetor[k];
				vetor[k]=auxiliar;
				contTroca++;
				//printf("\ntroca: %d , %d por %d",contTroca,vetor[k],vetor[j]);
			}
			else
				j=0;
		}
	}	

	printf("\n\nOperação concluída!!\n\n");
	printf("\n\n\n\n");
	system("pause");	
}

int main(){
	setlocale(LC_ALL,"portuguese");
	
	int opcao;
	while(1){	
		system("cls");
				
		printf("BEM-VINDO");
		printf("\n\nPor gentileza escolha uma opção:");
		printf("\n1-Preenche o vetor \n2-Ordena o vetor por Bubble Sort ");
		printf("\n3-Ordena o Vetor por Selection Sort \n4-Ordena o Vetor por Insertion Sort ");
		printf("\n5-Desempenho\n6-Imprime o vetor \n7-sair\n\nSeleção: ");
		scanf("%d",&opcao);
		fflush(stdin);
			
		switch(opcao){
			case 1:
				preencheVetor();
				break;			
					
			case 2:
				bubbleSort();
				break;
				
			case 3:
				selectionSort();
				break;
				
			case 4:
				insertionSort();
				break;
				
			case 5:
				opcao =0;
				printf("\n\nDESEMPENHO");
				printf("\nPor gentileza selecione uma opção: \n1-Quantidade de comparação \n2-quantidade de trocas \n3-Ambos \n seleção: ");
				scanf("%d",&opcao);
				switch(opcao){
					case 1:
						printf("\nNumero de comparações: %d\n\n\n",contComparacao);
						system("pause");
						break;
						
					case 2:
						printf("\nNumero de trocas: %d\n\n\n",contTroca);
						system("pause");
						break;
						
					case 3:
						printf("\nNumero de comparações: %d",contComparacao);
						printf("\nNumero de trocas: %d\n\n\n",contTroca);
						system("pause");
						break;
					
					default:
						printf("\nOpção Incorreta!!\n\n\n");
						system("pause");
						break;
				}		
				break;
				
			case 6:
				imprimeVetor();
				break;
				
			case 7:
				return 0;
				break;
				
			default:
				printf("\nOpção incorreta, aperte ENTER e digite novamente!!");
				printf("\n\n\n");
				system("pause");
				break;								
		}	
	}
	
	return 0;
}
