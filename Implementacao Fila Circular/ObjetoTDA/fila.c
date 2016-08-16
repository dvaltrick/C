#include <stdio.h>
#include "fila_priv.h"

int criaFila(ppFILAC p, int tamVet, int tamInfo){
    int i;

    *p = (pFILAC)malloc(sizeof(FILAC));
    if(*p == NULL){
          return FRACASSO;
    }
    
    (*p)->vet = (void**)malloc(tamVet * sizeof(void*));
    if((*p)->vet == NULL){
                 free(*p);
                 *p == NULL;
                 return FRACASSO;
    }
    
    for(i = 0; i < tamVet; i++){
          (*p)->vet[i] = malloc(tamInfo);
          if((*p)->vet[i] == NULL){
                for(i--;i>=0;i--){
                     free((*p)->vet[i]); 
                }
                free((*p)->vet);
                free(*p);
                *p = NULL;
                return FRACASSO;
          }      
    }
    (*p)->tamVet = tamVet;
    (*p)->tamInfo = tamInfo;
    (*p)->inicio = -1;
    (*p)->final = -1;
    (*p)->tamFila = 0;
    return SUCESSO;
}

void destroiFila(ppFILAC p){
        int i;

		for(i = 0; i < (*p)->tamVet; i++){
			free((*p)->vet[i]);
		}
		free((*p)->vet);
		free(*p);
		*p = NULL;
}

int testaCheia(pFILAC p){
    if(p->tamFila == p->tamVet)
    {
          return 1; //Está cheia
    }
    return 0;
}

int testaVazia(pFILAC p){
    if(p->tamFila == 0){
          return 1; //Está vazia
    }
    return 0;
}

int insereFila(pFILAC p, void *novoDado){
     if(p->tamFila == 0){
          if(p->final < p->tamVet - 1){
               p->final++;
               p->inicio = p->final;
               p->tamFila++;
               memcpy(p->vet[p->final], novoDado, p->tamInfo);
          }
          else{
               p->final = 0;
               p->inicio = p->final;
               p->tamFila++;
               memcpy(p->vet[p->final], novoDado, p->tamInfo);
          }               
     }
     else if(p->tamFila == p->tamVet){
          return FRACASSO;
     }
     else{
          if(p->final < p->tamVet - 1){
               p->final++;
               p->tamFila++;
               memcpy(p->vet[p->final], novoDado, p->tamInfo);
          }
          else{
               p->final = 0;
               p->tamFila++;
               memcpy(p->vet[p->final], novoDado, p->tamInfo);
          }          
     }
     return SUCESSO;
}

int removeFila(pFILAC p){
     if(p->tamFila == 0){
           return FRACASSO;
     }
     /*if(p->final > 0){
          p->final--;
     }
     else{
          p->final = p->tamVet - 1;
     }*/
     p->tamFila--;
     if(p->inicio == p->tamVet - 1){
           p->inicio = 0;
     }
     else{
          p->inicio++;
     }
     return SUCESSO;
}

void purgaFila(pFILAC p){
     p->tamFila = 0;
}

int buscaFrenteFila(pFILAC p, void *retorno){
    if(p->tamFila == 0){
         return FRACASSO;
    }
    memcpy(retorno, p->vet[p->inicio], p->tamInfo);
    return SUCESSO;
}

