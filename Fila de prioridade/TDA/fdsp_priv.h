#include <stdlib.h>
#define FRACASSO 0
#define SUCESSO 1
#define MAIOR 1
#define MENOR -1

typedef struct no{
        void *dados;
        struct no *prox;
}NO, *pNO, **ppNO;

typedef struct{
        int tamInfo;
        void *inicio;
} FDSP, *pFDSP, **ppFDSP;
