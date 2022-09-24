/*
	Programa para encontrar un 0 de la función
		f(x)=x^3+x^2-4x-1
	por el método de Newton-Raphson.
*/

#include <stdio.h>
#include <math.h>

double f(double x){
	return pow(x,3)+pow(x,2)-4*x-1;
}

double fx(double x){
	return 3*pow(x,2)+2*x-4;
}

int main(){
	double a, p, error, s1, s2;
	int i=0;
	printf("\tDame el punto inicial \n");
	printf("a: "); scanf("%lf", &a);
	
	system("cls");
	printf("i\ta\tf(a)\t\tp\t\t\tabsoluto\tporcentual\n");
	
	do{
		p=a-f(a)/fx(a);
		s2=s1;
		s1=p;
		error=fabs((s1-s2)/s1)*100;
		printf("%d\t%.3f\t%.10f\t%.17f\t%.6f\t%.10f\n", i+1, a, f(a), p, fabs(s1-s2), error );
		a=p;
		i++;
	}while(error>0.0003);
	
	return 0;
}
