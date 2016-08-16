#define FRACASSO 0
#define SUCESSO 1

typedef struct {}MAT, *pMAT, **ppMAT;

int criaMatriz(ppMAT m, int qtdLinhas, int qtdColunas);
void destroiMatriz(ppMAT m);
void setaMatriz(ppMAT m, int Linha, int Coluna, int valor);
int getMatriz(ppMAT m, int Linha, int Coluna);
int pegaQtdLinha(ppMAT m);
int pegaQtdColuna(ppMAT m);
void multiplicaMatriz(ppMAT m1, ppMAT m2, ppMAT mR);
