#include <stdio.h>
#include "fdsp_priv.h"

int criaFdsp(ppFDSP f, int tamInfo){
    
    *f = (pFDSP)malloc(sizeof(FDSP));
    if(*f == NULL){
          return FRACASSO;
    }
    
    (*f)->tamInfo = tamInfo;
    (*f)->inicio  = NULL;
    
    return SUCESSO;

}

int insereFdsp(pFDSP f, void *novo, int (pfunc)(void *v1,void *v2)){
    
    int i;
    pNO no, *aux;
    
    no = (pNO)malloc(sizeof(NO));
    if(no == NULL){
          return FRACASSO;
    }    
    
    no->dados = malloc(f->tamInfo);
    if(no->dados == NULL){
          free(no);
          return FRACASSO;
    }
    
    aux = f->inicio;
    
    while(*aux!=NULL&&pfunc((*aux)->dados,novo)==MENOR){
         aux = &(*aux)->prox;
    }
    no->prox = *aux;
    *aux = no;
    
    memcpy(no->dados,novo,f->tamInfo);
    return SUCESSO;

}

void destroiFdsp(ppFDSP f){
     pNO aux1, aux2;
     
     aux1 = (*f)->inicio;
     
     while(aux1 != NULL){
         aux2 = aux1->prox;
         free(aux1->dados);
         free(aux1);
         aux1 = aux2;
     }
     free(*f);
     *f = NULL;
}

void purga(ppFDSP f){
     pNO aux1, aux2;
     
     aux1 = (*f)->inicio;
     
     while(aux1 != NULL){
         aux2 = aux1->prox;
         free(aux1->dados);
         free(aux1);
         aux1 = aux2;
     }
     (*f)->inicio = NULL;
}

int testaVazia(pFDSP f){
    if(f->inicio == NULL)
         return SUCESSO;
    return FRACASSO;
}

void pinta(pFDSP f)
{
     pNO aux ;
     aux = f->inicio;
     while(aux!=NULL)
     {
         printf("%i| ",*((int*)aux->dados));
         aux = aux->prox;
     }
     printf("\n");
}

int buscaNaFrente(pFDSP f,void *pReg)
{
    pNO no;
    no = f->inicio;
    if(f->inicio==NULL)
        return FRACASSO;
    memcpy(pReg,no->dados,f->tamInfo);
    return SUCESSO;
}

int compara(void *x,void *y)
{
    if(*((int*)x)>*((int*)y))
        return MAIOR;
    return MENOR;
}

int main(){
    
    int x, c, y = 4;
    FDSP *fila;
    
    x = criaFdsp(fila, sizeof(int));
    printf("%d\n", x);
    x = insereFdsp(fila, &y, compara);
    printf("%d\n", x);
    y = 1;
    x = insereFdsp(fila, &y, compara);
    printf("%d\n", x);
    x = insereFdsp(fila, &y, compara);
    printf("%d\n", x);
    x = buscaNaFrente(fila, &c);
    printf("%d\n", c);  
    system("PAUSE");
}
