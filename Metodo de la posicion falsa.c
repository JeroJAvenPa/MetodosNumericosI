/*
	Programa para encontrar un 0 de la función
			f(x)=(x-2)^3/4+2sen(x)-1
	por el método de la posición falsa
*/
#include <math.h>
#include <stdio.h>

double fx(double x){
	
	x=pow(x-2,3)/4+2*sin(x)-1;
	
	return x;
}

int main(){
	double a, b, p, error, s1, s2;
	int i=0;
	printf("\tDame el intervalo de solución \n");
	printf("a: "); scanf("%lf", &a);
	printf("b: "); scanf("%lf", &b);
	
	system("cls");
	printf("i\ta\tb\tf(a)\t\tf(b)\t\tp\t\t\tf(p)\t\terror\n");
	
	do{
		p=b-fx(b)*(a-b)/(fx(a)-fx(b));
		
		s2=s1;
		s1=fx(p);
		error=fabs(s1-s2);
		
		printf("%d\t%.3f\t%.3f\t%.6f\t%f\t%.17f\t%.10f\t%.6f\n", i+1, a, b, fx(a), fx(b), p, s1, error );
		
		if(fx(a)*s1<0)
			b=p;
		else a=p;
		
		i++;
		
	}while(error>0.0000005);
	
	return 0;
}
