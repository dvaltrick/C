/*
  Name: Multiplicação de matrizes
  Copyright: Todos os direitos reservados para Diego Ecker Valtrick
  Author: Diego Ecker Valtrick
  Date: 10/09/09 14:50
  Description: TDA para auxiliar no trabalho com a multiplicação de matrizes
*/


#include <stdio.h>
#include "mat_priv.h"


//ALOCANDO MEMORIA E INICIALIZANDO VARIAVEIS

int criaMatriz(ppMAT m, int qtdLinhas, int qtdColunas){
    int i;
    
    *m = (pMAT)malloc(sizeof(MAT));
    if(*m == NULL){
          return FRACASSO;
    }
    
    (*m)->mat = (int**)malloc(qtdLinhas * sizeof(int*));
    if((*m)->mat == NULL){
                 free(*m);
                 *m = NULL;
                 return FRACASSO;
    }
    
    for(i=0; i<qtdLinhas; i++){
         (*m)->mat[i] = malloc(qtdColunas * sizeof(int));
         if((*m)->mat[i] == NULL){
              for(i--; i >= 0; i--){
                       free((*m)->mat[i]); 
              }
              free((*m)->mat);
              free(*m);
              *m = NULL;
              return FRACASSO;
         }
    }
    
    (*m)->qtdLinhas = qtdLinhas;
    (*m)->qtdColunas = qtdColunas;
    return SUCESSO;
}

//DESALOCANDO MEMORIA

void destroiMatriz(ppMAT m){
     int i;
     for(i = 0; i < (*m)->qtdLinhas; i++){
           free((*m)->mat[i]);
     }
     free((*m)->mat);
     free(*m);
     *m = NULL;
}

//ATRIBUI VALOR A MATRIZ NA POSIÇÃO INDICADA

void setaMatriz(ppMAT m, int Linha, int Coluna, int valor){
     (*m)->mat[Linha][Coluna] = valor;
}

//RETORNA O VALOR DA MATRIZ NA POSIÇÃO INDICADA

int getMatriz(ppMAT m, int Linha, int Coluna){
    return (*m)->mat[Linha][Coluna];
}

//RETORNA QUANTIDADE DE LINHAS EXISTENTES NA MATRIZ

int pegaQtdLinha(ppMAT m){
    return (*m)->qtdLinhas;
}

//RETORNA QUANTIDADE DE COLUNAS EXISTENTES NA MATRIZ

int pegaQtdColuna(ppMAT m){
    return (*m)->qtdColunas;
}

//MULTIPLICA A MATRIZ

void multiplicaMatriz(ppMAT m1, ppMAT m2, ppMAT mR){
       int i, j, k;
       
       for (i = 0; i < pegaQtdLinha(m1); i++){                 //PERCORRE MATRIZ 1
            for (j = 0; j < pegaQtdColuna(m2); j++){           //PERCORRE MATRIZ 2
               (*mR)->mat[i][j] = 0;                           //LIMPA MATIZ DE RESULTADO
               for (k = 0; k < pegaQtdColuna(mR); k++){        //PERCORRE MATRIZ DE RESULTADO
                    (*mR)->mat[i][j] += (*m1)->mat[i][k] * (*m2)->mat[k][j];   //EXECUTA OPERAÇÕES DE MULTIPLICAÇÃO
               }
            }
       }
} 
