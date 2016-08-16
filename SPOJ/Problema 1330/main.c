#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int fx1,fy1,fx2,fy2,mx,my,qtd,i,teste, cont;
  
  teste = 0;
  while(scanf("%d %d %d %d",&fx1,&fy1,&fx2,&fy2) != EOF){
    if( (fx1 == 0) && (fy1 == 0) && (fx2 == 0) && (fy2 == 0)  ){
      break;
    }else{
      teste = teste + 1;
      scanf("%d",&qtd);
      cont = 0;
      for(i = 0;i < qtd;i++){
        scanf("%d %d",&mx,&my);
        if( (mx >= fx1) && (mx <= fx2) && (my <= fy1) && (my >= fy2)){
          cont = cont + 1;
        }
      }
      printf("Teste %d\n%d\n\n",teste,cont);
    }
  }
    
  
  system("PAUSE");	
  return 0;
}
