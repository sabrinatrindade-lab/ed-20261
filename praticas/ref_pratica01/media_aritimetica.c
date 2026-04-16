#include <stdio.h>
int main(){
int n;

float numeros [100];
float soma = 0, media;

printf("digite um numero de 1 a 100 :  ");
scanf("%d",&n);
 
while ( n >100 || n<=0 ){
    printf("invalido!, digite um numero de 1 a 100:");
    scanf("%d",&n);
}

for (int i=0; i<n; i++){
    numeros[i] = 1+i; 
   soma = soma + numeros[i]; 
   
}
   
   media = soma/n ; 
   printf("soma total é : %2.f\n", soma);
   printf("media é : %.2f\n",media);
    return 0;
}