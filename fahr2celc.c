#include <stdio.h>

float fahr2celc (int);

int main (void){
int fahr=0;
int i=0;
for (fahr=0;fahr<=300;fahr+=20){
	printf ("%03d\t%06.2f\n",fahr,fahr2celc(fahr));
	}
}

float fahr2celc (int fahr){
	return (5.0/9)*(fahr-32);
}
