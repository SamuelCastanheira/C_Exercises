#include <stdio.h>
#include <string.h>

int converteBinario (char  octal[],char binario [], int N);
int converteHexa (char binario[],char hexa [], int N);
void Imprime (char convertido[], int N);

int main (void){
    char octal[100];
    char binario[300];
    char hexa[100];
    int tamBinario;
    int tamHexa;
    scanf ("%s",octal);
    tamBinario=converteBinario(octal, binario, strlen(octal));
    Imprime (binario, tamBinario);
    tamHexa=converteHexa(binario,hexa,tamBinario);
    Imprime (hexa,tamHexa);
    return 0;   
}

int converteBinario (char  octal[],char binario [], int N){
	int j=0;
	int k;
    int i = 0;
	int tamanho=0;
    while (i<N) {
			if (octal[i]=='0'){
				binario[tamanho]='0';
				binario[tamanho+1]='0';
				binario[tamanho+2]='0';
			}
			else if (octal[i]=='1'){
				binario[tamanho]='0';
				binario[tamanho+1]='0';
				binario[tamanho+2]='1';
			}
			else if (octal[i]=='2'){
				binario[tamanho]='0';
				binario[tamanho+1]='1';
				binario[tamanho+2]='0';
			}
			else if (octal[i]=='3'){
				binario[tamanho]='0';
				binario[tamanho+1]='1';
				binario[tamanho+2]='1';
			}
			else if (octal[i]=='4'){
				binario[tamanho]='1';
				binario[tamanho+1]='0';
				binario[tamanho+2]='0';
			}
			else if (octal[i]=='5'){
				binario[tamanho]='1';
				binario[tamanho+1]='0';
				binario[tamanho+2]='1';
			}
			else if (octal[i]=='6'){
				binario[tamanho]='1';
				binario[tamanho+1]='1';
				binario[tamanho+2]='0';
			}
			else if (octal[i]=='7'){
				binario[tamanho]='1';
				binario[tamanho+1]='1';
				binario[tamanho+2]='1';
			}
			i++;
			tamanho+=3;
		}
		
    while (binario[j]=='0'){
		for (k=0;k<tamanho;k++){
			    binario[k]=binario[k+1];
		}
		tamanho-=1;
	}
	return tamanho;
}

int converteHexa (char binario[],char hexa [], int N) {
	int j;
    int i=0;
    int k=0;
    int tamanho=0;
    
	while (N%4!=0){
		for (j=N-1;j>=0;j--){
			binario[j+1]=binario[j];
		}
		binario[0]='0';
		N=N+1;
	}
while (i<N){
		if (((i+1)%4)==0){
			if ((binario[i-3]=='0')&&(binario[i-2]=='0')&&(binario[i-1]=='0')&&(binario[i-0])=='0')
				hexa[k]='0';
			else if ((binario[i-3]=='0')&&(binario[i-2]=='0')&&(binario[i-1]=='0')&&(binario[i])=='1')
				hexa[k]='1';
			else if ((binario[i-3]=='0')&&(binario[i-2]=='0')&&(binario[i-1]=='1')&&(binario[i])=='0')
				hexa[k]='2';
			else if ((binario[i-3]=='0')&&(binario[i-2]=='0')&&(binario[i-1]=='1')&&(binario[i])=='1')
				hexa[k]='3';
			else if ((binario[i-3]=='0')&&(binario[i-2]=='1')&&(binario[i-1]=='0')&&(binario[i])=='0')
				hexa[k]='4';
			else if ((binario[i-3]=='0')&&(binario[i-2]=='1')&&(binario[i-1]=='0')&&(binario[i])=='1')
				hexa[k]='5';
			else if ((binario[i-3]=='0')&&(binario[i-2]=='0')&&(binario[i-1]=='1')&&(binario[i])=='1')
				hexa[k]='6';
			else if ((binario[i-3]=='0')&&(binario[i-2]=='1')&&(binario[i=1]=='1')&&(binario[i])=='1')
				hexa[k]='7';
			else if ((binario[i-3]=='1')&&(binario[i-2]=='0')&&(binario[i-1]=='0')&&(binario[i])=='0')
				hexa[k]='8';
			else if ((binario[i-3]=='1')&&(binario[i-2]=='0')&&(binario[i-1]=='0')&&(binario[i])=='1')
				hexa[k]='9';
			else if ((binario[i-3]=='1')&&(binario[i-2]=='0')&&(binario[i-1]=='1')&&(binario[i])=='0')
				hexa[k]='A';
			else if ((binario[i-3]=='1')&&(binario[i-2]=='0')&&(binario[i-1]=='1')&&(binario[i])=='1')
				hexa[k]='B';
			else if ((binario[i-3]=='1')&&(binario[i-2]=='1')&&(binario[i-1]=='0')&&(binario[i])=='0')
				hexa[k]='C';
			else if ((binario[i-3]=='1')&&(binario[i-2]=='1')&&(binario[i-1]=='0')&&(binario[i])=='1')
				hexa[k]='D';
			else if ((binario[i-3]=='1')&&(binario[i-2]=='1')&&(binario[i-1]=='1')&&(binario[i])=='0')
				hexa[k]='E';
			else if ((binario[i-3]=='1')&&(binario[i-2]=='1')&&(binario[i-1]=='1')&&(binario[i])=='1')
				hexa[k]='F';	
			k++;
			tamanho++;
		}
		i++;
    }
    return tamanho;
}


void Imprime (char convertido[], int N){
	int i;
	for (i=0;i<N;i++){
		printf ("%c",convertido[i]);
	}
	printf ("\n");
}
