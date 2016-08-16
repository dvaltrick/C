#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int tamPeriodo,teste,x,y,i, maiorSaldo, maiorInicio, maiorFim, saldo, inicio,fim;
  
  teste = 0;
  
  while(scanf("%d",&tamPeriodo) != EOF){
    if(tamPeriodo == 0){
      break;
    }else{
      teste = teste + 1;
      saldo = 0;
      inicio = 0;
      maiorInicio = 0;
      maiorFim = 0;
      maiorSaldo = 0;
      fim = 0;
      for(i = 0;i < tamPeriodo;i++){
        scanf("%d %d",&x,&y);
        
        saldo = saldo + (x - y);
        if(saldo > 0){
          if(inicio == 0){
            inicio = i + 1; 
          }
          fim = i + 1;
          
          if(saldo > maiorSaldo){
             maiorSaldo = saldo;  
             maiorFim = fim;
             maiorInicio = inicio;
          }else{
            if(saldo == maiorSaldo){
              if((fim - inicio) > (maiorFim - maiorInicio)){
                maiorInicio = inicio;
                maiorFim = fim;
              }
            }
          }

          if((inicio == maiorInicio) ){
            maiorFim = fim;
          }
        }else{
    
          if(saldo <= 0){
           if((inicio == maiorInicio)){
             maiorFim = i;
           }
          }else{
            saldo = 0;
            inicio = 0;
            fim = 0;
          }
          
        }      
      }
      if(maiorSaldo > 0 ){
        printf("Teste %d\n%d %d\n\n",teste,maiorInicio,maiorFim);
      }else{
        printf("Teste %d\nnenhum\n\n",teste);
      }      
    }
  }
    
  system("PAUSE");	
  return 0;
}
