#include <stdlib.h>
#include "ldse_priv.h"

int cria(pLDSE l, int tamInfo){
    
    l = (pLDSE)malloc(sizeof(LDSE));
    if(l == NULL){
         return FALTA_MEMORIA;
    }
    
    l->tamInfo = tamInfo;
    l->inicio = NULL;
    
    return SUCESSO;
    
}

int insere(pLDSE l, int pos, void *dado){
    int i;
    pNOLDSE *aux, no;
    
    if(pos < 0){
          return POSICAO_INVALIDA;
    }
    
    aux = &(l->inicio);
    
    for(i = 0; i < pos && *aux != NULL; i++){
          aux = &((*aux)->prox);
    }
    
    no = (pNOLDSE)malloc(sizeof(NOLDSE));
    if(no == NULL){
          return FALTA_MEMORIA;
    }
    
    no->dados = malloc(l->tamInfo);
    if(no->dados == NULL){
          free(no);
          no = NULL;
          return FALTA_MEMORIA;
    }
    
    no->prox = *aux;
    *aux = no;
    
    memcpy(no->dados, dado, l->tamInfo);
    
    return SUCESSO;
}

int remove(pLDSE l, int pos){
    int i;
    pNOLDSE no, *aux;
    
    if(pos < 0){
           return POSICAO_INVALIDA;
    }
    
    aux = &(l->inicio);
    no = l->inicio;
    
    for(i = 0; i <= pos; i++){
          if(i != pos){
               no = no->prox;
          }
          aux = &((*aux)->prox);
    }
    
    free(no);
    no = *aux;
    
    return SUCESSO;           

}

void destroi(pLDSE l){
     int i;
     pNOLDSE no;
     
     no = l->inicio;
     
     for(i = 0; no != NULL; i++){
           free(no->dados);
     }
     free(l);
     l = NULL;
}
