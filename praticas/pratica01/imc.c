#include  <stdio.h> 
 int main(){
float peso = 70.0; 
float altura = 1.75;
float imc ;
 
imc = peso/ (altura*altura);
printf("seu imc: %.2f\n",imc);
printf("situacao:  ");


if ( imc < 18.5 ){
    printf(" abaixo do peso\n ");
}
  else if (imc >= 18.5 && imc <= 24.9) {
    printf("peso normal\n");
  }
  else if ( imc >= 25.0 && imc <= 29.9) {
    printf("sobrepeso\n");
  }
  else{
    printf("obesidade\n");
  }
   
   
 return 0;
}