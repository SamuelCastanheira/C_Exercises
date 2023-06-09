#include <stdio.h>
int main (void){
int numerador, denominador;
float divisao;

scanf ("%d",&numerador);
scanf ("%d",&denominador);

if (denominador!=0){
divisao=(float)numerador/denominador;
printf ("%.2f",divisao);
	}
else {
printf ("Divisao por zero");
	}
return 0;
} 
