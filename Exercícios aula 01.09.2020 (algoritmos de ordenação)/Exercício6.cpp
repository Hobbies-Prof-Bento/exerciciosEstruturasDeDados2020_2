#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/*6. Criem um programa em C que manipule um vetor de 10 posições de inteiro e possua os menus abaixo, use como base o programa anterior:
1 - Preenche o Vetor
2 - Ordena o Vetor por Bubble Sort
3 - Ordena o Vetor por Selection Sort 
4 - Ordena o Vetor por Insertion Sort
5 - Ordena o Vetor por Shelf Sort
6 - Desempenho 
	1 - Quantidade de comparações 
	2 - Quantidade de trocas
7 - Imprime o Vetor
8 - Sair
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

void selectionSort(){
	int contComparacao=0, contTroca=0;
	
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
	int contComparacao=0, contTroca=0;
	
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

void shelfSort(){
	int contComparacao=0, contTroca=0;
	
	int i, j, value, h=1;
	
	while(h<10){
		h=3*h+1;
	}
	while(h>0){
		for(i=h;i<10;i++){
			value = vetor[i];
			j=i;
			contComparacao++;
			//printf("\ncomparacao: %d , %d com %d",contComparacao,vetor[i-h],vetor[i]);
			while(j>h-1&&value<=vetor[j-h]){
				vetor[j]=vetor[j-h];
				j=j-h;
				vetor[j]=value;
				contTroca++;
				//printf("\ntroca: %d , %d por %d",contTroca,vetor[i-h],vetor[i]);
			}			
		}
		h=h/3;
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
	printf("\n1-Preenche o vetor \n2-Ordena o vetor por Bubble Sort ");
	printf("\n3-Ordena o Vetor por Selection Sort \n4-Ordena o Vetor por Insertion Sort ");
	printf("\n5-Ordena o Vetor por Shelf Sort");
	printf("\n6-Desempenho\n7-Imprime o vetor \n8-sair\n\nSeleção: ");
	scanf("%d",&opcao);
	fflush(stdin);
		
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
			selectionSort();
			main();
			break;
			
		case 4:
			insertionSort();
			main();
			break;
			
		case 5:
			shelfSort();
			main();
			break;
			
		case 6:
			opcao =0;
			printf("\n\nDESEMPENHO");
			printf("\nPor gentileza selecione uma opção: \n1-Quantidade de comparação \n2-quantidade de trocas \n3-Ambos \n seleção: ");
			scanf("%d",&opcao);
			switch(opcao){
				case 1:
					printf("\nNumero de comparações: %d\n\n\n",contComparacao);
					system("pause");
					main();
					break;
					
				case 2:
					printf("\nNumero de trocas: %d\n\n\n",contTroca);
					system("pause");
					main();
					break;
					
				case 3:
					printf("\nNumero de comparações: %d",contComparacao);
					printf("\nNumero de trocas: %d\n\n\n",contTroca);
					system("pause");
					main();
					break;
				
				default:
					printf("\nOpção Incorreta!!\n\n\n");
					system("pause");
					main();
					break;
			}		
			
		case 7:
			imprimeVetor();
			main();
			break;
			
		case 8:
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
