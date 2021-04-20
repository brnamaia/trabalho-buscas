#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// inicializa a lista apontando-a para nulo
void inicializar_lista(Lista **lista){ 
  *lista = NULL;
}

// busca uma chave na lista 
float busca_lista(Lista **lista, int chave){ 
  Lista *aux = *lista;
  
  if (aux == NULL){
    return 0.0; // chave não encontrada
  }

  if ((*(aux)).chave == chave){
    return 1.0; 
  }

  aux = aux->prox;
  
  while(aux != NULL) {
    if((*(aux)).chave == chave){
      return 1.0; // chave encontrada
    }
    aux = aux->prox;
  }
  
  return 0.0; // chave não encontrada 
}

// insere um nó que contém chave e valor na lista encadeada
void inserir_no_na_lista(Lista **lista, int chave, float valor){ 

    Lista* novo_no = (Lista*)malloc(sizeof(Lista));
    if(novo_no == NULL){
      return ;
      //exit(0);
    }
    (*(novo_no)).prox = NULL;
    (*(novo_no)).ant = NULL;
    (*(novo_no)).chave = chave;
    (*(novo_no)).valor = valor;

  if(*lista ==  NULL) {
    *lista = novo_no;
    return;
  } 
  if(!(*(*(lista))).prox){
    (*(*(lista))).prox = novo_no;
  } else {
    inserir_no_na_lista(&(*(*(lista))).prox, chave, valor);
  } 
}

