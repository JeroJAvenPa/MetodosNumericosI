#include <stdio.h>
#include <math.h>
#include <locale.h>

/*
	Desarollado por:
	Aguirre Olgín Alan
	Avendaño Pachuca Jerónimo Jahir
	Baeza Guerrero Roberto
*/

int ConfiguraIdioma(){
	//Cambia al idioma Español  
	struct lconv *lcPtr;
	setlocale(LC_ALL, "spanish");
	lcPtr = localeconv();
	
	//Configura cantidades para México
	lcPtr->decimal_point = ".";
	lcPtr->thousands_sep = ",";
	lcPtr->grouping = "3";
}

int menuMetodo(){
	int opcion;
	
	printf("\tMenú de métodos\n\
1.- Método de la bisección\n\
2.- Método de Newton-Raphson\n\
3.- Salir\n");

	do{
		printf("Selecione una opción: ");
		scanf("%d",&opcion);
		
	}while(opcion<1||opcion>3);
	system("cls");
	
	return opcion;
}

int menuFuncion(){
	int opcion;
	
	printf("\tMenú de funciones\n\
1.- x^2*cos(x)-2x\n\
2.- 4/x^2*e^(x+2)/4+1\n\
3.- x^3-3sen(x^2)+1\n\
4.- x^3+6x^2+9.4x+2.5\n\
5.- Salir\n");

	do{
		printf("Selecione una opción: ");
		scanf("%d",&opcion);
		
	}while(opcion<1||opcion>5);
	system("cls");
	
	return opcion;
}

double fx1(double x){
	
	return pow(x,2)*cos(x)-2*x;
}

double fx2(double x){
	
	return pow(exp(1),x+2)*(6-2/pow(x,2))/4+1;
}

double fx3(double x){
	
	return pow(x,3)-3*sin(pow(x,2))+1;
}

double fx4(double x){
	
	return pow(x,3)+6*pow(x,2)+9.4*x+2.5;
}

double dx1(double x){
	
	return 2*x*cos(x)-sin(x)*pow(x,2)-2;
}

double dx2(double x){
	
	return pow(exp(1),x+2)*(3*pow(x,3)-x+2)/(2*pow(x,3));
}

double dx3(double x){
	
	return 3*x*(x-2*cos(pow(x,2)));
}

double dx4(double x){
	
	return 3*pow(x,2)+12*x+9.4;
}

void biseccion(int f){
	double a, b, tol, p, s2, s1, error, fa, fb, fp;
	int i, max;
	//Lectura del intervalo
	printf("\tIndique el intervalo de solución \n");
	printf("a: "); scanf("%lf", &a);
	printf("b: "); scanf("%lf", &b);
	
	printf("\tIndique el máximo de iteraciones: ");
	scanf("%d", &max);
	
	printf("\tIndique la tolerancia al error relativo: ");
	scanf("%lf", &tol);
	
	system("cls");
	printf("i\ta\tb\tf(a)\t\tf(b)\t\tp\t\t\tf(p)\t\terror\n");
	
	do{
		//obtenemos el punto medio
		p=(a+b)/2;
		//esto sirve para sacar el error s1 es x_n y s2 es x_(n-1)
		s2=s1;
		s1=p;
		error=fabs((s1-s2)/s1);
		//obtenemos todas las evaluaciones según la función
		switch(f){
			case 1:
				fa=fx1(a); fb=fx1(b); fp=fx1(p);
			break;
			
			case 2:
				fa=fx2(a); fb=fx2(b); fp=fx2(p);
			break;
			
			case 3:
				fa=fx3(a); fb=fx3(b); fp=fx3(p);
			break;
			
			case 4:
				fa=fx4(a); fb=fx4(b); fp=fx4(p);
			break;
		}
		
		//La tabla del proceso
		printf("%d\t%.3f\t%.3f\t%.6f\t%f\t%.17f\t%.10f\t%.6f\n", i+1, a, b, fa, fb, p, fp, error );
		//comprobación de la raíz en el intervalo deseado
		if(fa*fp<0)
			b=p;
		else a=p;
		
		i++;
	}while(tol<error&&i<max);
	
	system("pause"); system("cls");
}

void NewtonRaphson(int f, double (*dx[])(double) ){
	double a, tol, p, fa, s2, s1, error;
	int max, i;
	
	do{
		printf("\tDame el punto inicial \n");
		printf("a: "); scanf("%lf", &a);
	}while((*dx[f-1])(a)==0);
	
	printf("\tIndique el máximo de iteraciones: ");
	scanf("%d", &max);
	
	printf("\tIndique la tolerancia al error relativo: ");
	scanf("%lf", &tol);
	
	system("cls");
	printf("i\ta\tf(a)\t\tp\t\t\tabsoluto\trelativo\n");
	
	do{
		//obtenemos todas las evaluaciones según la función
		switch(f){
			case 1:
				p=a-fx1(a)/dx1(a); fa=fx1(a); 
			break;
			
			case 2:
				p=a-fx2(a)/dx2(a); fa=fx2(a);
			break;
			
			case 3:
				p=a-fx3(a)/dx3(a); fa=fx3(a);
			break;
			
			case 4:
				p=a-fx4(a)/dx4(a); fa=fx4(a);
			break;
		}
		//esto sirve para sacar el error s1 es x_n y s2 es x_(n-1)
		s2=s1;
		s1=p;
		error=fabs((s1-s2)/s1);
		//La tabla del proceso
		printf("%d\t%.3f\t%.10f\t%.17f\t%.6f\t%.10f\n", i+1, a, fa, p, fabs(s1-s2), error );
		//Nuevo punto inicial
		a=p;
		
		i++;
	}while(tol<error&&i<max);
	
	system("pause"); system("cls");
}

int main(){
	double (*dx[])(double)={&dx1, &dx2, &dx3, &dx4};
	ConfiguraIdioma();
	int metodo, funcion, opc;
	
	do{
		metodo=menuMetodo();
		
		if(metodo==1){
			funcion=menuFuncion();
			while(funcion!=5){
				
				do{
					biseccion(funcion);
					printf("¿Obtener otra raíz?\n1.- Sí\nOtro.- Salir\n\tSelecione una opción: ");
					scanf("%d",&opc);
					system("cls");
				}while(opc==1);
				
				funcion=menuFuncion();
			}
			funcion=0;
		}
		if(metodo==2){
			funcion=menuFuncion();
			while(funcion!=5){
				
				do{
					NewtonRaphson(funcion, dx);
					printf("¿Obtener otra raíz?\n1.- Sí\nOtro.- Salir\n\tSelecione una opción: ");
					scanf("%d",&opc);
					system("cls");
				}while(opc==1);
				
				funcion=menuFuncion();
			}
			funcion=0;
			
		}
	}while(metodo!=3);
	printf("\n\n\
Desarollado por:\n\
	Aguirre Olgín Alan\n\
	Avendaño Pachuca Jerónimo Jahir\n\
	Baeza Guerrero Roberto\n\n\
");
	return 0;
}
