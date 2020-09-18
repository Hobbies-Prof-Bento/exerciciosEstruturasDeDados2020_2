/*Faça o teste de mesa do código abaixo, com n=10:*/

int pesqInter(int chave, int v[], int n) { 
int ini = 0, meio, fim = n - 1; 
while (ini <= fim) { 
		meio = ini + ((fim-ini)*(chave-v[ini])) / (v[fim]-v[ini]); 
		printf("\n O indice do meio foi: %i", meio); 
		if (chave < v[meio]) { 
			fim = meio - 1; 
		} 
	else if (chave > v[meio]) { 
		ini = meio + 1; 
	} 
	else { 
		return meio; 
		} 
} 
return -1; // Índice Impossível 
} 
