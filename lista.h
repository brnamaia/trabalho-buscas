#include <stdio.h>
#include <stdlib.h>

#ifndef lista_h
#define lista_h

typedef struct no_lista Lista;

struct no_lista {
  struct no_lista *prox;
  int chave;
  float valor;
  struct no_lista *ant;
};

void inicializar_lista(Lista **);
float busca_lista(Lista **, int);
void inserir_no_na_lista(Lista **, int, float);

#endif