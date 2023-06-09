#include <stdio.h>

void incrementa (int);

int main (void){
int num=9;
incrementa(num);
printf ("%d\n",num);
return 0;
}

void incrementa (int num){
num=num+1;
}
