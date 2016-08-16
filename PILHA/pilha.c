#include <stdlib.h>
#include "pilha_priv.h"

int criaPilha(ppPilha p, int tamVet, int tamInfo){
     int i, j;
     *p = (pPilha)malloc(sizeof(Pilha));
     if(*p == NULL){
     		return FRACASSO;
	  }

     (*p)->Vet = (void**)malloc(sizeof(void*));
     if((*p)->Vet == NULL){
         *p = NULL;
         return FRACASSO;
     }
     for(i = 0; i < tamVet; i++){
         (*p)->Vet[i] = malloc(sizeof(tamInfo));
         if((*p)->Vet[i] == NULL){
             for(j == i; j >= 0; j--){
                 (*p)->Vet[j] = NULL;
             }
             (*p)->Vet = NULL;
             *p = NULL;
             return FRACASSO;
         }
		}
     (*p)->topo;

     return SUCESSO;

}

void destroiPilha(ppPilha p, int tamVet){
	int i;
	for(i = 0; i < tamVet; i++){
		free((*p)->Vet[i]);
	}
	free((*p)->Vet);
	free(p);
}


