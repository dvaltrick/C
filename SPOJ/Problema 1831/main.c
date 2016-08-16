#include <stdio.h>
#include <stdlib.h>

int f91(int n){
    if(n <= 100){
      return f91(f91(n+11));
    }else{
      return n - 10;
    }
};

int main(int argc, char *argv[])
{
  int linha, retorno;
   
  while(scanf("%d",&linha) != EOF){
    if(linha == 0){
      break;
    }else{
      retorno = f91(linha);
      printf("f91(%d) = %d\n", linha,retorno);
    }
  }  
  system("PAUSE");	
  return 0;
}
