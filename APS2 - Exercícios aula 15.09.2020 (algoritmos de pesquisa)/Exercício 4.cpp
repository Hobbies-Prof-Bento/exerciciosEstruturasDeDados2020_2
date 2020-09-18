/*Faça o teste de mesa do código abaixo, com n=10:*/

int pesqBin(int chave, int v[], int n) {
	int inicio = 0; 
	int meio; 
	int fim = n - 1; 
	while (inicio <= fim) { 
		meio = (inicio + fim) / 2; 
		if (chave < v[meio]) { 
			fim = meio - 1; 
		} 
		else if (chave > v[meio]) { 
			inicio = meio + 1; 
		} 
		else { 
			return meio; 
		} 
	} 
	return -1; // Índice Impossível 
}

