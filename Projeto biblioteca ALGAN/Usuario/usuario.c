#include <stdio.h>
#include <math.h>
#include "algan.h"

int criaMenu{
    printf("MENU ===============================================================\n");   
    printf("1 - Cria vetores.\n");
    printf("2 - Seta valores dos vetores.\n");
    printf("3 - Soma vetores.\n");
    printf("4 - Subtrai vetores.\n");
    printf("5 - Multiplicacao escalar.\n");
    printf("6 - Divisao escalar.\n");
    printf("7 - Produto escalar.\n");
    printf("8 - Modulo vetor.\n");
    printf("====================================================================\n"); 
}

int main(){
    VET *u, *v, *w;
    float x,y,z;
    int ret;
    
    
    ret = criaVetor(&u);
    printf("criou: %d\n\n", ret);
    
    ret = criaVetor(&v);
    ret = criaVetor(&w);
    
    
    setaVetor(u, 2, 4, 2);
    setaVetor(v, 4, 2, 4);
    
    somaVet(w, u, v);
    
    pegaVetor(w, &x,&y,&z);
    
    printf("\nw = ( %.2f, %.2f, %.2f)\n", x,y,z);
    
    subVet(w, v, u);
    pegaVetor(w, &x, &y, &z);
    
    printf("\nw = ( %.2f, %.2f, %.2f)\n", x,y,z);
    
    
    //multEscalar(u, 2);
    //pegaVetor(u, &x, &y, &z);
    
    //printf("\nu = ( %.2f, %.2f, %.2f)\n", x,y,z);
    
    /*divEscalar(u, 2);
    pegaVetor(u, &x, &y, &z);
    
    printf("\nu = ( %.2f, %.2f, %.2f)\n", x,y,z);*/
    
    printf("\nProduto escalar de u.v: %.2f\n\n", produtoEscalar(u,v));
    printf("\nModulo de v: %.2f\n\n", moduloVet(v));   
    
    produtoVetorial(w, u, v);
    pegaVetor(w, &x, &y, &z);
    
    printf("\nw = ( %.2f, %.2f, %.2f)\n", x,y,z);     
    
    setaVetor(w, 4, 3, 1);
    pegaVetor(w, &x, &y, &z);
    
    printf("\nw = ( %.2f, %.2f, %.2f)\n", x,y,z);    
    printf("Produto misto uxv.w = %.2f\n\n", produtoMisto(u , v, w));  //VERIFICAR PRODUTO MISTO 
    
    /*if(paralelo(u,v) == 1){
         printf("\nOs vetores sao paralelos\n\n");
    }
    else{
         printf("\nNao sao paralelos!\n\n");
    }*/
    
    printf("A area formado por u e w eh: %.2f\n\n", areaDosVetores(u,w));
    printf("O volume dos vetores eh: %.2f\n\n", volumeDosVetores(u,v,w));
    printf("O angulo entre os vetores u e v eh: %.2f\n\n", anguloEntreVetores(u,v));
    
    
    destroiVetor(&u);
    destroiVetor(&v);
    destroiVetor(&w);
    system("PAUSE");
       
}
