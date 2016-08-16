#include <stdio.h>
#include "femr_priv.h"

int criaFemr(ppFEMR f, int tamVet, int tamInfo){
    
    int i;
    
    *f = (pFEMR)malloc(sizeof(FEMR));
    if(*f = NULL){
          return FRACASSO;
    }
    
    (*f)->vet = (void**)malloc(tamVet * sizeof(void*));
    if((*f)->vet == NULL){
          free(*f);
          *f = NULL;
          return FRACASSO;
    }
 
    for(i = 0; i < tamVet; i++){
          (*f)->vet[i] = malloc(tamInfo);
          if((*f)->vet[i] == NULL){
                for(i--; i >= 0; i--){
                         free((*f)->vet[i]);
                }
                free((*f)->vet);
                free(*f);
                *f = NULL;
                return FRACASSO;
          }
    } 
      
    (*f)->tamVet = tamVet;
    (*f)->tamInfo = tamInfo;
    (*f)->final = -1;
    return SUCESSO;
}

void destroiFemr(ppFEMR f){
     int i;
     
     for(i = 0; i < (*f)->tamVet; i++){
           free((*f)->vet[i]);
     }
     free((*f)->vet);
     free(*f);
     *f = NULL;
}

void purgaFemr(pFEMR f){
    f->final = -1;
}

int inserefemr(pFEMR f, void *novoDado){
    if(f->final == f->tamVet - 1){
         return FRACASSO;
    }
    f->final++;
    memcpy(f->vet, novoDado, f->tamInfo);
    return SUCESSO;
}

int removeFemr(pFEMR f){
    int i;
    
    if(f->final == -1){
          return FRACASSO;
    }
    
    for(i = 0; i < f->final; i++){
          memcpy(f->vet[i],f->vet[i+1],f->tamInfo);
    }
    f->final--;
    return SUCESSO;
}

int buscaFemr(pFEMR f, void *retorno){
    if(f->final == -1){
          return FRACASSO;
    }
    
    memcpy(retorno, f->vet[0], f->tamInfo);
    return SUCESSO;
}

int testaCheia(pFEMR f){
    if(f->final == f->tamVet - 1){
          return SUCESSO;   //ESTÁ CHEIA
    }
    return FRACASSO;
}

int testaVazia(pFEMR f){
    if(f->final == -1){
          return SUCESSO; //ESTÁ VAZIA
    }
    return FRACASSO;
}

