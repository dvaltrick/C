#define FRACASSO 0
#define SUCESSO 1

typedef struct {} FILAC, *pFILAC, **ppFILAC;

int criaFila(ppFILAC p, int tamVet, int tamInfo);

void destroiFila(ppFILAC p);

int testaCheia(pFILAC p);

int testaVazia(pFILAC p);

int insereFila(pFILAC p, void *novoDado);

int removeFila(pFILAC p);

void purgaFila(pFILAC p);

int buscaFrenteFila(pFILAC p, void *retorno);
