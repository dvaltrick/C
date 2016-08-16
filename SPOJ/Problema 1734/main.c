#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char nome[20];
  int nota;
  int instancia;
}Aluno;


int main(int argc, char *argv[])
{

    int  quantidade,i,j;
    scanf("%d", &quantidade);
    Aluno a[quantidade];
    Aluno aux;

    i = 0;    
    j = quantidade;
    while(scanf("%s %d",&a[i].nome,&a[i].nota) != EOF){
      a[i].instancia = i;
      i++;
    }
    
    for(i = quantidade;i >= 1; i--){
      for(j = 1; j < i; j++){
        if(a[j - 1].nota > a[j].nota){
          aux = a[j];
          a[j] = a[j - 1];
          a[j - 1] = aux;
        }
      }
    }

    aux = a[0];
    
    for(i = 1;i < quantidade;i++){
      if(aux.nota < a[i].nota){
        break;
      }
      if(aux.nota = a[i].nota){
        if(strcmp(aux.nome,a[i].nome) == -1){
          aux = a[i];
        }            
      }
    }
    
    printf("Instancia %d\n%s\n",aux.instancia,aux.nome);
  
  system("PAUSE");	
  return 0;
}
