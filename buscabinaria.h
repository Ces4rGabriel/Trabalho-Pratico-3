#ifndef buscabinaria_h
#define buscabinaria_h

typedef int TChave;

typedef struct {
    TChave Chave;
} TRegistro;

typedef struct {
    TRegistro *v;
    int n, max, cont;
} TDicionario;

int CheckPos(TDicionario *t, int pos, TChave x);

void lerMalhas(int m, TDicionario *dicionario, int *pos, int *alvo);

void exibeResultado(int PosDesejada, int PosEncontrada, int interacoes);

void TDicionario_Inicia(TDicionario *t, int malhas);

int TDicionario_find(TDicionario *t, TChave x);

int TDicionario_Binaria(TDicionario *t, TChave x, int esq, int dir);

void Results(int alvo, int achou);


#endif // buscabinaria_h
