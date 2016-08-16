#include <stdio.h>
#include "pilha.h"

int main(){

	pPilha p;
	int a;

	a = criaPilha(&p , 2, 4);

	printf("%d", a);  
	

	return 0;

}
