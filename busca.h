#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore.h"
#include "lista.h"

#ifndef busca_h
#define busca_h

typedef struct tupla Tupla;

struct tupla{
  int chave;
  float valor;
};

int busca_sequencial(int *, int, int);
void gerar_tuplas(int, Abb **, Lista **);
int busca_binaria(int *, int, int, int);

#endif