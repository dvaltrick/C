#include <stdio.h>
#include "ldse_priv.h"

int criaLdse(ppLDSE l, int tamInfo){

    *l = (pLDSE)malloc(sizeof(LDSE));
    if(*l == NULL){
          return FRACASSO;
    }
    
    (*l)->inicio  = NULL;
    (*l)->tamInfo = tamInfo;
    
    return SUCESSO;
}

int insereLdse(pLDSE l, void *novo, int pos){

    int i;
    pNO *aux, no;
    
    if(pos < 0){
           return FRACASSO;
    }
    
    aux = &(l->inicio);
    for(i = 0; i < pos && *aux != NULL; i++){
          aux = &(*aux)->prox;
    }

    if(i != pos){
		return FRACASSO;
	}

	// PASSO 2 - ALOCAR MEMÓRIA
		
	if((no = (pNO)malloc(sizeof(NO))) == NULL){
		return FRACASSO;
	}

	if((no->dados = malloc(l->tamInfo)) == NULL){
		free(no);
		return FRACASSO;
	}
	// PASSO 3 - INCLUIR ELEMENTO		

	no->prox = *aux;
	*aux = no;

	// PASSO 4 - COPIAR O VALOR
     
	memcpy(no->dados, &novo, l->tamInfo);
	return SUCESSO;
}

void purgaLdse(pLDSE l){
     
     int i;
     pNO aux1, aux2;
     
     aux1 = l->inicio;
     while(aux1 != NULL){
          aux2 = aux1->prox;
          free(aux1->dados);
          free(aux1);
          aux1 = aux2;
     }
     
     l->inicio = NULL;
}

void destroiLdse(ppLDSE l){
     
     int i;
     pNO aux1,aux2;
     
     aux1 = (*l)->inicio;
     while(aux1 != NULL){
         aux2 = aux1->prox;
         free(aux1->dados);
         free(aux1);
     }
     free(*l);
     *l = NULL;    
     
}

int removeLdse(pLDSE l, int pos){
    int i;
    pNO *aux1, aux2;
    
    if(pos < 0){
           return FRACASSO;
    }   
    
    printf("vou achar\n");
    aux1 = &l->inicio;
    
    for(i = 0; i < pos && (*aux1)->prox != NULL; i++){
          aux1 = &((*aux1)->prox);
    }
    if( i != pos ){
        return FRACASSO;
    }
    aux2 = *aux1;
    *aux1 = (*aux1)->prox;
    free(aux2->dados);
    free(aux2);

    return SUCESSO;
    
}

int buscaLdse(pLDSE l, int pos, void *ret){
    int i;
    pNO aux;
    
    if(pos < 0){
           return FRACASSO;
    }
    
    aux = l->inicio;
    
    for(i = 0; i < pos; i++){
          aux = aux->prox;
    }
    
    if(i != pos){
         return FRACASSO;
    }
    memcpy(ret , aux->dados , l->tamInfo);
    
    return SUCESSO;
    
}

int inverte(pLDDE l){
    pLDDE laux;
    int x;

    cria(&laux);
    
    while(x != NULL){
      buscaUltimo(l,x);
      insereNaFrente(laux, x);
      removeUltimo(l);
    }
    while(x != NULL){
      buscaNaFrente(laux, x);
      insereNaFrente(l, x);
      removePrimeiro(laux);  
    }
v}

}
int main(){
    LDSE *lista;
    int b,a, c, d = 7 ,e = 90;
    b = 8;
    a = b;
    a = criaLdse(&lista, 2);
    printf("%d\n", a);
    a = insereLdse(lista, b, 0);
    printf("%d\n", a);
    a = 4;
    a = insereLdse(lista, d, 1);
    printf("%d\n", a);
    a  = 5;
    a = insereLdse(lista, e , 2);
    printf("%d\n", a);
    //a = remove(lista, 1);
    buscaLdse(lista, 1, &c);
    printf("busquei %d\n", c);
    a = removeLdse(lista,0);
    buscaLdse(lista, 0,&c); 
    printf("%d\n", c);
    purgaLdse(lista);
    destroiLdse(&lista);
    system("PAUSE");

}
