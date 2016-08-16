#define SUCESSO 1
#define FRACASSO 0

typedef struct no{
       void *dados;
       struct no *prox;
} NO, *pNO, **ppNO;

typedef struct{
        NO *inicio;
        int tamInfo;
} LDSE, *pLDSE, **ppLDSE;
