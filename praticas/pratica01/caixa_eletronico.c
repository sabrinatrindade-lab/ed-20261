#include <stdio.h>
int main(){
int cedulas []={200,100,50,20,10,5,2};
int saque;
int total_notas;

printf("digite o valor do saque ( pode até R$1000) : ");
scanf("%d",&saque);

if(saque >1000 || saque <= 0){
printf("valor invalido!\n");
return 0; 
}
printf("para o valor de R$ %d, recebera : \n",saque);

for(int i =0; i<7; i++){
    total_notas = saque / cedulas[i];
    saque = saque % cedulas[i] ;
    if (total_notas> 0 ){
        printf("%d nota(s) de R$ %d\n ", total_notas, cedulas[i]);
    }
}
if (saque > 0){
    printf("atençao: sobrou R$ %d que não pode ser sacado com as notas disponiveis.\n",saque);
}

    return 0 ; 
}