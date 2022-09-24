/*
	Programa para encontrar un 0 de la función
		f(x)=x^3+x^2-4x-1
	por el método de la secante.
*/

#include <stdio.h>
#include <math.h>

double f(double x){
	return -(3.72995*(0.046694*pow(0.4*pow(x,2)+2,3.5)-1)/pow(x,2) )-(1/pow(1-pow(x,2),0.5)-0.1915*pow(x,2)/(pow(1-pow(x,2),0.5)+1));
}

int main(){
	double xn, xm, p, error, s1, s2;
	int i=0;
	printf("\tDame el punto inicial\n");
	printf("x_0: "); scanf("%lf", &xm);
	
	printf("\tDame el punto inicial x_1\n");
	printf("x_1: "); scanf("%lf", &xn);

	system("cls");
	printf("i\tx_0\tx_1\tf(x_0)\t\tf(x_1)\t\tx_2\t\t\tf(x_2)\t\tabsoluto\tporcentual\n\n");
	
	do{
		p=xn-f(xn)*(xn-xm)/(f(xn)-f(xm));
		s2=s1;
		s1=p;
		error=fabs((s1-s2)/s1)*100;
		printf("%d\t%.3f\t%.3f\t%.6f\t%.6f\t%.17f\t%.10f\t%.8f\t%.10f\n", i+1, xm, xn, f(xm), f(xn), p, f(p), fabs(s1-s2), error );
		xm=xn;
		xn=p;
		i++;
	}while(error>0.0003);
	
	return 0;
}
