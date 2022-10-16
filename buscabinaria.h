#ifndef buscabinaria_h
#define buscabinaria_h

typedef int TChave;

typedef struct {
    TChave Chave;
} TRegistro;

typedef struct {
    TRegistro *v;
    int n, max;
} TDicionario;

void lerMalhas(int m, TDicionario *dicionario, int *pos, int *alvo);

void TDicionario_Inicia(TDicionario *t);

int TDicionario_find(TDicionario *t, TChave x);

int TDicionario_Binaria(TDicionario *t, TChave x, int esq, int dir);


#endif // buscabinaria_h
