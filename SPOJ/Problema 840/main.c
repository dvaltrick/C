#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int difer,joao,ze,qtd,teste,i;
  
  teste = 1;
  while(scanf("%d",&qtd) != EOF){
    if(qtd == 0){
      break;
    }else{
      printf("Teste %d\n",teste);
      difer = 0;

      for(i = 0;i < qtd;i++){
          scanf("%d",&joao);
          scanf("%d",&ze);
          difer = difer + (joao - ze);
          printf("%d\n",difer);
      }
    }
    printf("\n");
    teste++;
  }
  
  system("PAUSE");	
  return 0;
}
