/*2 - fa�a o teste de mesa do c�digo abaixo, com n=5:*/

int pesqSeq(int chave, int v[], int n) { 
	int i; 
	for (i = 0; i < n; i++) { 	
		if (v[i] == chave) { 
			return (i); 
		}
	} 
	return (-1); // �ndice inv�lido 
} 

