#define FRACASSO 0
#define SUCESSO 1

typedef struct{}VET, *pVET, **ppVET;

int criaVetor(ppVET v);

void setaVetor(pVET v, float x1, float x2, float x3);

void somaVet(pVET x, pVET v, pVET u);

void subVet(pVET x, pVET v, pVET u);

void multEscalar(pVET v, float x);

void divEscalar(pVET v, float x);

float produtoEscalar(pVET v, pVET u);

float moduloVet(pVET v);

void produtoVetorial(pVET x, pVET v, pVET u);

float produtoMisto(pVET v, pVET u, pVET w);

int paralelo(pVET v, pVET u);

float areaDosVetores(pVET v, pVET u);

float volumeDosVetores(pVET v, pVET u, pVET w);

float anguloEntreVetores(pVET v, pVET u);

void pegaVetor(pVET v, float *a, float *b, float *c);
