/*2 - faça o teste de mesa do código abaixo, com n=5:*/

int pesqSeq(int chave, int v[], int n) { 
	int i; 
	for (i = 0; i < n; i++) { 	
		if (v[i] == chave) { 
			return (i); 
		}
	} 
	return (-1); // Índice inválido 
} 

