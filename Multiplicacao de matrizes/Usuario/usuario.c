#include <stdio.h>
#include "matriz.h"

int main(){
    
    MAT *mat1, *mat2, *matR;
    int x, y, z, i, j;
    
    x = criaMatriz(&mat1, 4, 4);
    y = criaMatriz(&mat2, 4, 4);
    z = criaMatriz(&matR, 4, 4);
    
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
              setaMatriz(&mat1, i, j, i + j);
        }
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
              setaMatriz(&mat2, i, j, j - i + 1);
        }
    }    
    for(i = 0; i < 4; i++){
        printf("\n");
        for(j = 0; j < 4; j++){
              printf("%d ", getMatriz(&mat1,i,j));
        }
    }
    
    printf("\n\n");
    for(i = 0; i < 4; i++){
        printf("\n");
        for(j = 0; j < 4; j++){
              printf("%d ", getMatriz(&mat2,i,j));
        }
    }
    
    multiplicaMatriz(&mat1, &mat2, &matR);
    
    printf("\n\n\n\n");
    
    for(i = 0; i < pegaQtdLinha(&matR); i++){
        printf("\n");
        for(j = 0; j < pegaQtdColuna(&matR); j++){
              printf("%d ", getMatriz(&matR,i,j));
        }
    }    
    
    destroiMatriz(&mat1);
    destroiMatriz(&mat2);
    destroiMatriz(&matR);
    system("PAUSE");
}
