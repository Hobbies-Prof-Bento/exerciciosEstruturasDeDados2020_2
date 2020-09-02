#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

/*7. Criem um programa em C que manipule um vetor de 10 posi��es de inteiro e possua os menus abaixo, use como base o programa anterior:
1 - Preenche o Vetor
2 - Ordena o Vetor por Bubble Sort
3 - Ordena o Vetor por Selection Sort 
4 - Ordena o Vetor por Insertion Sort
5 - Ordena o Vetor por Shelf Sort
6 - Desempenho 
	1 - Quantidade de compara��es 
	2 - Quantidade de trocas
	3 - Tempo de Execu��o
7 - Imprime o Vetor
8 - Sair
*/

int vetor[10]={3,2,4,5,1,6,8,9,7,10};
int contComparacao=0, contTroca=0;
int tempoProcessamento;

void preencheVetor(){
	for(int i=0;i<10;i++){
		printf("\nDigite o %d� valor do vetor: ",i+1);
		scanf("%d",&vetor[i]);
		}
	printf("Opera��o concluida!!\n\n\n");
	system("pause");	
	}
	
void imprimeVetor(){
	printf("\n\nOs valores do vetor s�o: ");	
	for(int i=0;i<10;i++){
			printf("%d-",vetor[i]);		
	}
	printf("\n\n\n");
	system("pause");	
}

void bubbleSort(){
	clock_t inicio=clock(), fim;
	
	//printf("\n\nclcok %d",inicio);	
	contComparacao = 0;
	contTroca = 0;
	//system("pause");
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
				//printf("\ntroca: %d , %d por %d",contTroca,vetor[i],vetor[j]);
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
	fim = clock();
	//printf("\n\nclcok %d",fim);
	tempoProcessamento = difftime(fim,inicio);
	//printf("\n\nclcok %d",tempoProcessamento);	
	printf("\n\nOpera��o conclu�da!!\n\n");
	printf("\n\n\n\n");
	system("pause");
		
}

void selectionSort(){	
	clock_t inicio = clock(),fim;
	//printf("\n\nclcok %d",inicio);
	contComparacao = 0;
	contTroca = 0;
	
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
	fim=clock();
	//printf("\n\nclcok %d",inicio);
	tempoProcessamento = difftime(fim,inicio);
	//printf("\n\nclcok %d",tempoProcessamento);
	printf("\n\nOpera��o conclu�da!!\n\n");
	printf("\n\n\n\n");
	system("pause");

}

void insertionSort(){
	clock_t inicio = clock(),fim;
	//printf("\n\nclcok %d",inicio);
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
	fim=clock();
	//printf("\n\nclcok %d",inicio);
	tempoProcessamento = difftime(fim,inicio);
	//printf("\n\nclcok %d",tempoProcessamento);
	printf("\n\nOpera��o conclu�da!!\n\n");
	printf("\n\n\n\n");
	system("pause");		
}

void shelfSort(){
	clock_t inicio = clock(),fim;
	//printf("\n\nclcok %d",inicio);
	contComparacao = 0;
	contTroca = 0;
	
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
	fim=clock();
	//printf("\n\nclcok %d",inicio);
	tempoProcessamento = difftime(fim,inicio);
	//printf("\n\nclcok %d",tempoProcessamento);
	printf("\n\nOpera��o conclu�da!!\n\n");
	printf("\n\n\n\n");
	system("pause");
}

int main(){
	setlocale(LC_ALL,"portuguese");
	
	int opcao;
		
	system("cls");
			
	printf("BEM-VINDO");
	printf("\n\nPor gentileza escolha uma op��o:");
	printf("\n1-Preenche o vetor \n2-Ordena o vetor por Bubble Sort ");
	printf("\n3-Ordena o Vetor por Selection Sort \n4-Ordena o Vetor por Insertion Sort ");
	printf("\n5-Ordena o Vetor por Shelf Sort");
	printf("\n6-Desempenho\n7-Imprime o vetor \n8-sair\n\nSele��o: ");
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
			printf("\nPor gentileza selecione uma op��o: \n1-Quantidade de compara��o ");
			printf("\n2-quantidade de trocas\n3-Tempo de execu��o \n4-Ambos \n sele��o: ");
			scanf("%d",&opcao);
			switch(opcao){
				case 1:
					printf("\nNumero de compara��es: %d\n\n\n",contComparacao);
					system("pause");
					main();
					break;
					
				case 2:
					printf("\nNumero de trocas: %d\n\n\n",contTroca);
					system("pause");
					main();
					break;
					
				case 3:
					printf("\nTempo de execu��o: %d milisegundos\n\n\n",tempoProcessamento);
					system("pause");
					main();
					break;
					
				case 4:
					printf("\nNumero de compara��es: %d",contComparacao);
					printf("\nNumero de trocas: %d",contTroca);
					printf("\nTempo de execu��o: %d milisegundos\n\n\n",tempoProcessamento);
					system("pause");
					main();
					break;
				
				default:
					printf("\nOp��o Incorreta!!\n\n\n");
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
			printf("\nOp��o incorreta, aperte ENTER e digite novamente!!");
			printf("\n\n\n");
			system("pause");
			main();
			break;								
	}	
	return 0;
}
