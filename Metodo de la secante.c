#include <stdio.h>
#include <math.h>

double fx(double x){
    return 3*x + sin(x) - exp(x);
}

int main(){
    double x0,x1,x2,aux,fx0,fx1,fx2,error, errorr, tole;
    int i=0;
    
    printf("\n intervalo inicial x0: ");
    scanf("%lf",&x0);
    printf("\n intervalo final x1: ");
    scanf("%lf",&x1);
    printf("\n Nivel de tolerancia: ");
    scanf("%lf", &tole);
    
    printf("\n\n Lista de valores: \n");
    printf("\nx0: %.8lf", x0);
    printf("\nx1: %.8lf", x1);
    fx0= fx(x0);
    printf("\nfx0: %.8lf", fx0);
    fx1= fx(x1);
    printf("\nfx1: %.8lf", fx1);
    x2= x1-(fx1)*((x0-x1)/(fx0-fx1));
    printf("\nx2: %.8lf", x2);
    fx2= fx(x2);
    printf("\nfx2: %.8lf", fx2);
    error= (x2-x1)/(x2);
    //printf("\nerror: %.8lf", error);
    errorr= abs(error);
    printf("\nerror abs: %.8lf", errorr);
    printf("\ntole: %.8lf", tole);
    aux= x1;
    //printf("\naux: %.8lf", aux);
    printf("\n Iteracion %d", i+1);
    printf("\n\n");
    getch();
    
    do{
        aux= x1;
        //printf("\naux: %.8lf", aux);
        x1= x2;
        x0= aux;
        printf("\nx0: %.8lf", x0);
        printf("\nx1: %.8lf", x1);
        fx0= fx(x0);
        printf("\nfx0: %.8lf", fx0);
        fx1= fx(x1);
        printf("\nfx1: %.8lf", fx1);
        x2= x1-(fx1)*((x0-x1)/(fx0-fx1));
        printf("\nx2: %.8lf", x2);
        fx2= fx(x2);
        printf("\nfx2: %.8lf", fx2);
        error= (x2-x1)/(x2);
        //printf("\nerror: %.8lf", error);
        errorr= abs(error);
        printf("\nerrorr: %.8lf", errorr);
        printf("\n Iteracion %d",i+2);
        printf("\n\n");
        i++;
        system("pause");
    }while(tole<errorr);

	return 0;
}

