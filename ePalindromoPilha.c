#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
	char Elem;
	struct No * Prox;
} No;

typedef struct Pilha {
	 No * Inicio;
	int N;
} Pilha;

bool ePalindromo (char *);
void empilha (Pilha * , char );
char desempilha (Pilha *);

int main (void) {
	char str[101];
	fgets (str,101,stdin);
	if (ePalindromo (str))
		printf ("Palindromo");
	else 
		printf ("Nao e palindromo");
	return 0;
}

bool ePalindromo (char * str) {
	int tam;
	int i;
	Pilha P;
	
	P.N=0;
	P.Inicio=NULL;
	tam=strlen(str)-1;
	
	for (i=0;i<tam;i++)
		empilha (&P,str[i]);
		
	for (i=0;i<tam/2;i++){
		if (str[i]!=desempilha(&P))
			return false;
	}
	return true;
}

void empilha (Pilha * P, char elem){
	No * novo;
	novo=malloc(sizeof(No));
	novo->Elem=elem;
	novo->Prox=P->Inicio;
	P->Inicio=novo;
	P->N=P->N+1;
}

void enfileira (Fila * F, char c) {
	No * novo;
	novo=malloc(sizeof(No));
	novo->Elem= c;
	novo->Prox=NULL;
	if (F->Inicio==NULL){
		F->Inicio=novo;
		F->Fim=novo;
	}else{
		F->Fim->Prox=novo;
		F->Fim=novo;
		F->N=F->N+1;
	
	}
		
