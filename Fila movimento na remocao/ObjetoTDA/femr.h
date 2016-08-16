#define SUCESSO 1
#define FRACASSO 0

typedef struct {}FEMR,*pFEMR,**ppFEMR;

int criaFemr(ppFEMR f, int tamVet, int tamInfo);

void destroiFemr(ppFEMR f);

void purgaFemr(pFEMR f);

int inserefemr(pFEMR f, void *novoDado);

int removeFemr(pFEMR f);

int buscaFemr(pFEMR f, void *retorno);

int testaCheia(pFEMR f);

int testaVazia(pFEMR f);

