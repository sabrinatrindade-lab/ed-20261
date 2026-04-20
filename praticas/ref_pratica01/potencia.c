#include <stdio.h> 
int main( ){
    int  base = 5;
    int expoente = 3 ;
   long int res = 1;

  for (int i= 0; i < expoente; i++){
   res= res * base ;
  }
    printf(" res = %d\n",res) ;    
   return 0;
} 
