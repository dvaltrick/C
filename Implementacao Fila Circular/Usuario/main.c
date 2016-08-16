#include <stdio.h>
#include "fila.h"

int main(){
 
    FILAC *fila;
    int a, b, c;
    
    a = criaFila(&fila, 4, 2);
    
    for(b = 0; b < 4; b++){
          a = insereFila(fila, &b);
    }
    printf("a: %d\n\n", a);

    a = buscaFrenteFila(fila, &c);
    printf("b: %d\n\n", c);
    
    printf("cheia: %d\n\n", testaCheia(fila));
    printf("vazia: %d\n\n", testaVazia(fila)); 
       
    a = removeFila(fila);
    
    printf("a: %d\n\n", a);
    printf("cheia: %d\n\n", testaCheia(fila));
    printf("vazia: %d\n\n", testaVazia(fila));
    
    a = buscaFrenteFila(fila, &c);
    printf("b: %d\n\n", c);
    
    
    b++;
    a = insereFila(fila, &b);
    printf("cheia: %d\n\n", testaCheia(fila));
    printf("vazia: %d\n\n", testaVazia(fila));
    
    purgaFila(fila);

    printf("cheia: %d\n\n", testaCheia(fila));
    printf("vazia: %d\n\n", testaVazia(fila));
    
    a = buscaFrenteFila(fila, &c);
    printf("b: %d\n\n", c);
        
    destroiFila(&fila);
    
    system("PAUSE"); 
    
}
