#include <stdio.h>
#include <string.h>
int main (void){
	char str[101];
	char aux[101];
	int tam;
	int i;
	fgets (str,101,stdin);
	strcpy (aux,str);
	tam=strlen(str)-1;
	for (i=0;i<tam;i++)
		str[i]=aux[(tam-1)-i];
	if ((strcmp(str,aux)==0))
		printf ("E paralindromo\n");
	else 
		printf ("Nao e palindromo\n");
	}
