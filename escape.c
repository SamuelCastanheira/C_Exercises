#include <stdio.h>
#include <string.h>
void Leitura (int str, char string []);
void Conversao (int str, char string[], int * i);
void Imprime (char string []);
int main (void){
	int str;
	char string[200]="";
	Leitura(str,string);
	Imprime(string);
	return 0;
}
void Leitura (int str, char string []){
    int i=0;
	while ((str=getchar())!=EOF){
	    Conversao(str,string,&i);
	}
}
void Conversao (int str, char string [], int * i){
		switch (str){
		case '\t':
	        string[*i]='\\';
		    string[*i=*i+1]='t';
		    *i=*i+1;
			break;
		case '\f':
			string[*i]='\\';
		    string[*i=*i+1]='f';
		    *i=*i+1;
			break;
		case '\v':
			string[*i]='\\';
		    string[*i=*i+1]='v';
		    *i=*i+1;
			break;
		case '\n':
            string[*i]='\\';
		    string[*i=*i+1]='n';
		    *i=*i+1;
			break;
		case '\r':
		   string[*i]='\\';
		   string[*i=*i+1]='r';
		   *i=*i+1;
		   break;
	    default:
		   string[*i]=str;
	       *i=*i+1;
		   break;
		}
	}

void Imprime (char string[]){
	for (int i=0;i<strlen(string);i++){
	printf ("%c",string[i]);
	}
}
