#include <stdio.h>
#include <math.h>
#include "algan_priv.h"


int criaVetor(ppVET v){
    *v = (pVET)malloc(sizeof(VET));
    if(*v == NULL)
          return FRACASSO;
    return SUCESSO;
}

void destroiVetor(ppVET v){
     free(*v);
}

void setaVetor(pVET v, float x1, float x2, float x3){
    v->x = x1;
    v->y = x2;
    v->z = x3; 
}

void somaVet(pVET x, pVET v, pVET u){   
     x->x = v->x + u->x;
     x->y = v->y + u->y;
     x->z = v->z + u->z;
}

void subVet(pVET x, pVET v, pVET u){   
     x->x = v->x - u->x;
     x->y = v->y - u->y;
     x->z = v->z - u->z;
}

void multEscalar(pVET v, float x){
     v->x = v->x * x;
     v->y = v->y * x;
     v->z = v->z * x;     
}

void divEscalar(pVET v, float x){
     v->x = v->x / x;
     v->y = v->y / x;
     v->z = v->z / x;     
}

float produtoEscalar(pVET v, pVET u){
          return (v->x * u->x) + (v->y * u->y) + (v->z * u->z);
}

float moduloVet(pVET v){
      return sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
}

void produtoVetorial(pVET x, pVET v, pVET u){
     x->x = (v->y * u->z) - (v->z * u->y);
     x->y = (v->z * u->x) - (v->x * u->z);
     x->z = (v->x * u->y) - (v->y * u->x);     
}

float produtoMisto(pVET v, pVET u, pVET w){
      return(((v->x * u->y * w->z) + (v->y * u->z * w->x) + (v->z * u->x * w->y)) - ((v->y * u->x * w->z) + (v->x * u->z * w->y) +(v->z * u->y * w->x)));
}

int paralelo(pVET v, pVET u){
    float a,b,c;
    a = v->x / u->x;
    b = v->y / u->y;
    c = v->z / u->z;
    
    if((a == b) && (a == c))
          return 1;
    return 0;
}

float areaDosVetores(pVET v, pVET u){
      int aloca;
      pVET x;
      
      aloca = criaVetor(&x);
      produtoVetorial(x, v, u);
      return moduloVet(x);
}

float volumeDosVetores(pVET v, pVET u, pVET w){
      float result;
      result = produtoMisto(v, u, w);
      result = result * result;
      return sqrt(result);
}

float anguloEntreVetores(pVET v, pVET u){
      float result;
      result = produtoEscalar(v, u)/(moduloVet(v) * moduloVet(u));
      return result;
}

void pegaVetor(pVET v, float *a, float *b, float *c){
     *a = v->x;
     *b = v->y;
     *c = v->z;
}
