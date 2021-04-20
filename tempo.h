#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "busca.h"
#include "lista.h"
#include "arvore.h"

#ifndef tempo_h
#define tempo_h

long double tempo_arvore(Abb **, int);
long double tempo_lista_encadeada(Lista **, int);
long double tempo_sequencial_vetor(int *, int, int);
long double tempo_busca_binaria(int *, int, int, int);

#endif 