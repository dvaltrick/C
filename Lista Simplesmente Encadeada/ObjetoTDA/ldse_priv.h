#define SUCESSO 0
#define FALTA_MEMORIA 1
#define POSICAO_INVALIDA 2

typedef struct no{
        void *dados;
        struct no *prox;
}NOLDSE, *pNOLDSE;

typedef struct{
        int tamInfo;
        pNOLDSE inicio;
}LDSE, *pLDSE, **ppLDSE;
