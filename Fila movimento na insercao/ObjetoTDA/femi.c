#include <stdio.h>
#include "femi_priv.h"

int criaFemi(ppFEMI f, int tamVet, int tamInfo){
    int i;
    
    *f = (pFEMI)malloc(sizeof(FEMI));
    if(*f == NULL){
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
    (*f)->tamInfo = tamInfo;
    (*f)->tamVet = tamVet;
    (*f)->final = -1;
    return SUCESSO;
}

void destroiFemi(ppFEMI f){
     int i;
     
     for(i = 0; i < (*f)->tamVet; i++){
           free((*f)->vet[i]);
     }
     free((*f)->vet);
     free(*f);
     *f = NULL;
}

int insereFemi(pFEMI f, void *novoDado){
    if(f->final == f->tamVet -1){
                return FRACASSO;
    }
    
    f->final++;
    memcpy(f->vet, novoDado, f->tamInfo);
    return SUCESSO;
}

int removeFemi(){
}
