#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n[10000],i, tam,teste;
  
  teste = 1;
  while(scanf("%d", &tam) != EOF){
    if(tam != 0){
        for(i = 0;i < tam;i++){
          scanf("%d",&n[i]);
          if(n[i] == i +1){
            printf("Teste %d\n%d\n\n",teste,n[i]);
          }
        }
        teste++;
    }else{
      break;
    }
  }  
    
  
  system("PAUSE");	
  return 0;
}
