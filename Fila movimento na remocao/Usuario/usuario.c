#include <stdio.h>
#include "femr.h"

int main(){
    FEMR *fila;
    int aux;
    aux = criaFemr(&fila, 4, 2);
    printf("Criou: %d\n\n", aux);
    
    //destroiFemr(fila);
    
    system("PAUSE");
}
