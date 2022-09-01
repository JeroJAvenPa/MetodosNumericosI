/*
	Programa para encontrar un 0 de la función
	f(x)=2xcos(2x)+x/4+0.4
*/
#include <math.h>
#include <stdio.h>

double fx(double x){
	
	x=2*x*cos(2*x)+x/4+0.4;
	
	return x;
}

int main(){
	double a, b, p;
	int i=0;
	printf("\tDame el intervalo de solución \n");
	printf("a: "); scanf("%lf", &a);
	printf("b: "); scanf("%lf", &b);
	
	system("cls");
	
	printf("i\ta\tb\tf(a)\t\tf(b)\t\tp\t\t\tf(p)\n");
	
	do{
		p=(a+b)/2;
		
		printf("%d\t%.3f\t%.3f\t%.6f\t%f\t%.17f\t%.10f\n", i+1, a, b, fx(a), fx(b), p, fx(p) );
		if(fx(a)*fx(p)<0)
			b=p;
		else a=p;
		i++;
	}while(i<55);
	
	return 0;
}
