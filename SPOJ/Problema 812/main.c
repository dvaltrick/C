#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
  int valor,cont50,cont10,cont5,cont1,contTeste;
  contTeste = 0;
  while(scanf("%d",&valor) != EOF){
    contTeste = contTeste + 1;
    if(valor == 0){
      break;
    }else{
     cont50 = 0;
     cont10 = 0;
     cont5 = 0;
     cont1 = 0;
     
     while(valor >= 50){
       cont50++;
       valor = valor - 50;
     }
     while(valor >= 10){
       cont10++;
       valor = valor - 10;
     }
     while(valor >= 5){
       cont5++;
       valor = valor - 5;
     }
     while(valor >= 1){
       cont1++;
       valor = valor - 1;
     }
     printf("Teste %d\n%d %d %d %d\n\n",contTeste,cont50,cont10,cont5,cont1);
     
    }
  }
  
  system("PAUSE");	
  return 0;
}
