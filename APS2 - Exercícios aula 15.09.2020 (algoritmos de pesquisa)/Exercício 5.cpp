#include<stdio.h>
#include<locale.h>

/*5. Implemente uma versão recursiva da função pesquisa binária, teste com n = 5. 
Protótipo da função: int pesqBinRec(int chave, int v[], int ini, int fim);
*/

int pesqBin(int chave, int v[],int ini, int fi);

int main(){
	setlocale(LC_ALL,"portuguese");
	int vetor[10]={1,5,7,9,10,11,12,14,16,17};
	int key = 7;
	int inicio =0;
	int size = 10;
	int indiceDoArmazenamento;
	
	indiceDoArmazenamento = pesqBin(key,vetor,inicio,size);
	
	printf("O índice é: %d",indiceDoArmazenamento);
	
	return 0;	
}

int pesqBin(int chave, int v[],int ini, int fi){
	int inicio = ini;
	int meio;
	int fim = fi-1;
	
	if(inicio<=fim){
		meio = (inicio+fim)/2;
		if(chave<v[meio]){
			fim = meio;
			return pesqBin(chave,v,inicio,fim);
		}
		else if(chave>v[meio]){
			inicio = meio+1;
			fim +=1;
			return pesqBin(chave,v,inicio,fim);
		}
		else
			return meio;
	}
	else
		return -1;
}
