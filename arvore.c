#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Inicializa a arvore apontando-a para nulo.
void inicializar_arvore(Abb **arvore) { 
	*arvore = NULL;
}

/* A função a seguir insere o um no na arvore, chegando primeiro se a arvore eh vazia, caso seja apenas insere. Se a arvore nao estiver vazia, o algoritmo chega onde o valor sera inserido, a esquerda ou a direita da raiz. */

void inserir_no_na_arvore(Abb **arvore, int chave, float valor) {

	Abb *novo_no = (Abb *)malloc(sizeof(Abb));
  if (novo_no == NULL){
    printf("Erro");
    return ;
    //exit(0);
  }
	(*(novo_no)).chave = chave;
	(*(novo_no)).valor = valor;
	novo_no->dir = NULL;
	novo_no->esq = NULL;

	Abb *y = NULL;
	Abb *x = *arvore;
	while (x != NULL) {
		y = x;
		if ((*(novo_no)).chave < (*(x)).chave) {
			x = x->esq;
		} else {
			x = x->dir;
		}
	}
	novo_no->pai = y;
	if (y == NULL) {
		*arvore = novo_no;
	} else if ((*(novo_no)).chave < (*(y)).chave) {
		y->esq = novo_no;
	} else {
		y->dir = novo_no;
	}

}

/* Na funcao abaixo, o percurso funciona da seguinte maneira: percorre a subarvore, esquerda em ordem, visita a raiz adicionando o valor de sua chave em um vetor, percorre a subarvore direita em ordem. (ordem simetrica). */

void percurso_em_ordem(Abb **arvore, int *vetor, int *n) {

	if (*arvore != NULL) {
		percurso_em_ordem(&(**(arvore)).esq, vetor, n);
		vetor[*n] = (*(*(arvore))).chave;
		*n = *n + 1;
		percurso_em_ordem(&(**(arvore)).dir, vetor, n);
	}
}

/* A funcao a seguir recebe um valor k, tenta localizar, se existir, um no na
arvore cujo a chave seja igual a k. z. Quando a busca chega a um no qualquer, 
ou esse no ja possui o valor procurado e a busca termina, ou ele possui um valor
menor ou maior que k. */

int busca_arvore(Abb **arvore, int k) { 
  
	if (*arvore == NULL || (*(*arvore)).chave == k) {
		if (*arvore == NULL) {
			return 0; // não encontrada
		} else if ((*(*arvore)).chave == k) {
			return 1; // encontrada
		}
	}

	if ((*arvore)->chave > k) {
		return busca_arvore(&(*(*arvore)).esq, k);
	} else {
		return busca_arvore(&(*(*arvore)).dir, k);
	}
}
