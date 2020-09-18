/*1 - Faça o teste de mesa do exercício do código abaixo*/

double fatorial(int n);
int main(void){
	int numero;
	double f;
	printf("Digite o numero que deseja calcular o fatorial: ");
	scanf("%d",&numero);
	f = fatorial(numero);
	printf("Fatorial de %d = %.0lf",numero,f);
	getch();
	return 0;
}
double fatorial(int n){
	double vfat;
	if ( n <= 1 )
		return (1);
	else{
		vfat = n * fatorial(n - 1);
		return (vfat);
	}
}

