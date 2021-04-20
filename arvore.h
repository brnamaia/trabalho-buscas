#include <stdio.h>
#include <stdlib.h>

#ifndef arvore_h
#define arvore_h

typedef struct no_arvore Abb;

struct no_arvore {
	int chave;
	float valor;
	struct no_arvore *esq;
	struct no_arvore *dir;
	struct no_arvore *pai;
};

void inicializar_arvore(Abb **);
void inserir_no_na_arvore(Abb **, int, float);
void percurso_em_ordem(Abb **, int *, int *);
int busca_arvore(Abb **, int);

#endif 