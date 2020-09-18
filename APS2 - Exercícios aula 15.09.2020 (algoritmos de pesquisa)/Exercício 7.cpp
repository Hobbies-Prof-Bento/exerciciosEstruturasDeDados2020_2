#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
/*7. Crie um programa em C que preencha um vetor de inteiros de 1000 posições com números aleatórios e implemente o menu de opções abaixo:
1. Ordena Vetor (Use qualquer método que aprendeu na aula passada)
2. Pesquisa Sequencial (Solicite um numero inteiro e informe o tempo para localizá-lo)
3. Pesquisa Sentinela (Solicite um numero inteiro e informe o tempo para localizá-lo)
4. Pesquisa Binária (Solicite um numero inteiro e informe o tempo para localizá-lo)
5. Pesquisa Interpolada (Solicite um numero inteiro e informe o tempo para localizá-lo)
6. Sair
*/

int vetor[11];

void gerarVetor();
void ordenaVetor();
int pesquisaSequencial(int key);
int pesquisaSentinela(int key);
int pesquisaBinaria(int key);
int pesquisaInterpolada(int key);
void bubbleSort();
void selectionSort();
void insertionSort();
void shelfSort();

int main(){
	setlocale(LC_ALL,"portuguese");
	int opcao;
	int chave;
	
	gerarVetor();
	while(1){
		system("cls");		
		printf("SEJA BEM-VINDO");
		printf("\n\nPor gentileza escolha uma opção:");
		printf("\n1-Ordena vetor \n2-Pesquisa sequencial");
		printf("\n3-Pesquisa sentinela \n4-Pesquisa binária");
		printf("\n5-Pesquisa Interpolada \n6-Visualizar vetor");
		printf("\n7-sair");
		
		printf("\n\nEscolha: ");
		scanf("%d",&opcao);
		
		switch(opcao){
			case 1:
				ordenaVetor();
				break;
			case 2:
				printf("\n\nDigite o valor que deseja buscar: ");
				scanf("%d",&chave);
				printf("\nO valor buscado encontra-se no índice %d\n\n\n",pesquisaSequencial(chave));
				system("pause");
				break;
			case 3:
				printf("\n\nDigite o valor que deseja buscar: ");
				scanf("%d",&chave);				
				printf("\nO valor buscado encontra-se no índice %d\n\n\n",pesquisaSentinela(chave));
				system("pause");
				break;
			case 4:
				printf("\n\nDigite o valor que deseja buscar: ");
				scanf("%d",&chave);				
				printf("\nO valor buscado encontra-se no índice %d\n\n\n",pesquisaBinaria(chave));
				system("pause");
				break;
			case 5:
				printf("\n\nDigite o valor que deseja buscar: ");
				scanf("%d",&chave);				
				printf("\nO valor buscado encontra-se no índice %d\n\n\n",pesquisaInterpolada(chave));
				system("pause");
				break;
			case 6:				
				printf("O vetor gerado foi: \n");
				for(int i=0;i<sizeof(vetor)/4-1;i++){
				printf(" %d,",vetor[i]);			
				}
				printf("\n\n\n");
				system("pause");
				break;
			case 7:
				return 0;
				break;
			default:
				system("cls");
				printf("Opção inválida, digite novamente\n\n\n");
				system("pause");
				break;
		}
		
	}
	return 0;
}

void gerarVetor(){
	srand(time(NULL));	
	for(int i=0;i<sizeof(vetor)/4-1;i++){	
		vetor[i]=rand()%(10*(sizeof(vetor)/4)-1);
		for(int j=i-1;j>=0;j--){
			if(vetor[i]==vetor[j]){
				j=-1;
				i--;
			}				
		}
	}
}

void ordenaVetor(){
	int opcao;
	
	printf("\n\nPor gentileza escolha uma opção");
	printf("\n1-Ordena o vetor por Bubble Sort ");
	printf("\n2-Ordena o Vetor por Selection Sort");
	printf("\n3-Ordena o Vetor por Insertion Sort");
	printf("\n4-Ordena o Vetor por Shelf Sort");
	printf("\n5-Retorna ao menu principal");
	
	printf("\n\nEscolha: ");
	scanf("%d",&opcao);
	
	switch(opcao){
		case 1:
			bubbleSort();
			break;
		case 2:
			selectionSort();
			break;
		case 3:
			insertionSort();
			break;
		case 4:
			shelfSort();
			break;
		case 5:
			break;
		default:
			system("cls");
			printf("Opção inválida!!!\n\n\n");
			system("pause");
			break;
	}
	
}

int pesquisaSequencial(int key){
	clock_t inicio=clock(),fim;
	int size = sizeof(vetor)/4-1;
	for(int i=0;i<size;i++){
	//	printf("\n%d size: %d",vetor[i],size);
		if(vetor[i]==key){
			//system("pause");
			fim=clock();
			printf("O tempo de processamento foi de %d milissegundos",fim-inicio);
			return i;
		}			
	}
	//system("pause");
	fim=clock();
	printf("O tempo de processamento foi de %d milissegundos",fim-inicio);
	return -1;
}

int pesquisaSentinela(int key){
	clock_t inicio=clock(),fim;
	int i=0,size=sizeof(vetor)/4-1;
	vetor[size] = key;
	while(vetor[i]!=key){
		i++;
	}
	if(i<size){	
		//system("pause");
		fim=clock();
		printf("O tempo de processamento foi de %d milissegundos",fim-inicio);
		return i;
	}
	//system("pause");
	fim=clock();
	printf("O tempo de processamento foi de %d milissegundos",fim-inicio);	
	return -1;
}

int pesquisaBinaria(int key){
	//shelfSort();
	clock_t start=clock(), stop;
	int inicio =0;
	int meio;
	int fim = sizeof(vetor)/4-2;
	
	while(inicio<=fim){
		meio=(inicio+fim)/2;
		if(key<vetor[meio])
			fim = meio-1;
		else if(key>vetor[meio])
			inicio = meio+1;
		else{
		//	system("pause");
			stop=clock();
			printf("O tempo de processamento foi de %d milissegundos",stop-start);
			return meio;
		}			
	}
	//system("pause");
	fim=clock();
	printf("O tempo de processamento foi de %d milissegundos",stop-start);
	return -1;
}

int pesquisaInterpolada(int key){
	//shelfSort();
	clock_t start=clock(), stop;
	int inicio =0;
	int meio;
	int fim = sizeof(vetor)/4-2;
	
	while(inicio<=fim){
		meio=inicio+((fim-inicio)*(key-vetor[inicio]))/(vetor[fim]-vetor[inicio]);
		if(key<vetor[meio])
			fim = meio-1;
		else if(key>vetor[meio])
			inicio = meio+1;
		else{
		//	system("pause");
			stop=clock();
			printf("O tempo de processamento foi de %d milissegundos",stop-start);
			return meio;
		}			
	}
	//system("pause");
	fim=clock();
	printf("O tempo de processamento foi de %d milissegundos",stop-start);
	return -1;
}

void bubbleSort(){
	int vetorAux[sizeof(vetor)/4-1];
	int auxiliar,j, verificador = 1, soma =0,size=(sizeof(vetor)/4)-2;
	
	for(int i=0;i<sizeof(vetor)/4-1;i++){
		vetorAux[i]=0;
	}

	while(verificador !=0){		
		for(int i=0;i<size;i++){
			auxiliar = vetor[i];
			j = i+1;
			if(vetor[i]>vetor[j]){
				vetor[i]=vetor[j];
				vetor[j]=auxiliar;
			}			
		}
		for(int i=0;i<sizeof(vetor)/4-1;i++){			
			soma+=abs(vetor[i]-vetorAux[i]);			
		}
		for(int i=0;i<sizeof(vetor)/4-1;i++){
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
	int auxiliar,indice, size=sizeof(vetor)/4-1;	
		
	for(int i=0;i<size-1;i++){
		auxiliar = vetor[i];
		indice = i;			
		for(int j=i+1;j<size;j++){
			if(auxiliar>vetor[j]){
				auxiliar = vetor[j];
				indice = j;				
			}			
		}
		vetor[indice]=vetor[i];
		vetor[i]=auxiliar;			
	}
	printf("\n\nOperação concluída!!\n\n");
	printf("\n\n\n\n");
	system("pause");
}

void insertionSort(){
	int auxiliar,j,k, size=sizeof(vetor)/4-1;
	
	for(int i=0;i<size-1;i++){
		j=i+1;
		k=i;
		for(j;j>0;j--,k--){			
			if(vetor[k]>vetor[j]){
				auxiliar=vetor[j];
				vetor[j]=vetor[k];
				vetor[k]=auxiliar;				
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
	int i, j, value, h=1, size=sizeof(vetor)/4-1;
	
	while(h<size){
		h=3*h+1;
	}
	while(h>0){
		for(i=h;i<size;i++){
			value = vetor[i];
			j=i;
			while(j>h-1&&value<=vetor[j-h]){
				vetor[j]=vetor[j-h];
				j=j-h;
				vetor[j]=value;				
			}			
		}
		h=h/3;
	}
	printf("\n\nOperação concluída!!\n\n");
	printf("\n\n\n\n");
	system("pause");
}
