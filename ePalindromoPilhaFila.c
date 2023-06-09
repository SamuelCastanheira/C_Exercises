#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//DECLARACAO DE TIPOS E FUNCOES
typedef struct No {
	char Elem;
	struct No * Prox;
} No;

typedef struct Pilha {
	No * Inicio;
	int N;
} Pilha;

typedef struct Fila {
	No * Inicio;
	No * Fim;
	int N;
} Fila;

void inicializaPilha (Pilha *);
void empilha (Pilha * , char );
char desempilha (Pilha *);

void inicializaFila (Fila *);
void enfileira (Fila *, char);
char desenfileira (Fila *);


bool ePalindromo (Fila);

//MAIN
int main (void) {
//INICIALIZACAO
	char c;
	Fila F;
	inicializaFila (&F);

//CODIGO PRINCIPAL
	while ((c=getchar())!='\n') {
		enfileira (&F,c);
		}
		
	if (ePalindromo (F))
		printf ("Palindromo\n");
	else 
		printf ("Nao e palindromo\n");
return 0;
}


//FUNCOES DO PROGRAMA 

void inicializaPilha (Pilha * P) {
	P->Inicio=NULL;
	P->N=0;
}

void inicializaFila (Fila * F) {
	F->Inicio=NULL;
	F->Fim=NULL;
	F->N=0;
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
		
}

void empilha (Pilha * P, char c){
	No * novo;
	novo=malloc(sizeof(No));
	novo->Elem=c;
	novo->Prox=P->Inicio;
	P->Inicio=novo;
	P->N=P->N+1;
}

bool ePalindromo (Fila  F) {
	char c;
	Pilha P;
	No * pont;
	int metade;
	
	inicializaPilha (&P);
	metade = F.N/2;
	pont = F.Inicio;
		
	while (pont!=NULL){
		c = pont->Elem;
		empilha (&P,c);
		pont=pont->Prox;
	}
	while (F.N>=metade)
		if (desenfileira(&F)!=desempilha(&P))
			return false;
	return true;
}

char desenfileira (Fila * F){
	No * Desaloca;
	char c;
	Desaloca=F->Inicio;
	c=F->Inicio->Elem;
	if (F->Inicio==F->Fim) {
		F->Inicio=NULL;
		F->Fim=NULL;
	} else 
		F->Inicio=F->Inicio->Prox;
	free (Desaloca);
	F->N=F->N -1;
	return c;
	
}
char desempilha (Pilha * P){
	char c;
	No * Desaloca;
	Desaloca = P->Inicio;
	c = P->Inicio->Elem;
	P->Inicio = P->Inicio->Prox;
	P->N=P->N-1;
	return c;
}

