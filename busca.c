#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "busca.h"
#include "arvore.h"
#include "lista.h"

// busca uma chave no vetor gerado de forma sequencial
int busca_sequencial(int *vetor, int n, int chave){ 
  int i; 

  for(i = 0; i < n ; i++){
    if(vetor[i] == chave){
      return 1; // chave encontrada
    } 
  }

  return 0; // chave não encontrada
}

// gera tuplas que contém uma chave e um valor, e em seguida armazena essas chaves e esses valores em nós de árvore e de lista, inserindo-os nas suas respectivas estruturas
void gerar_tuplas(int n, Abb **arvore, Lista **lista) { 
  int i;
  int j;
  int chave;

  srand(time(NULL));

  Tupla *vet = malloc(n*sizeof(Tupla));

  for (i = 0; i < n; i++) {
    chave = rand() % n;
    while (busca_arvore(&(*arvore), chave)) {
      chave = rand() % n;
    }
    vet[i].chave = chave;
    vet[i].valor = (float)(rand() % n) + (float)(rand() % n)/n + ((float)(rand() % n)/n)/10;
    inserir_no_na_arvore(&(*arvore), vet[i].chave, vet[i].valor);
    inserir_no_na_lista(&(*lista), vet[i].chave, vet[i].valor);
  } 

}

// busca uma chave no vetor gerado utilizando o algoritmo de busca binária
int busca_binaria(int *vetor, int chave, int inicio, int fim){
  int meio;

  if (inicio <= fim){
    meio = (inicio + fim)/2;
    if (vetor[meio] == chave){
      return 1;  // chave encontrada
    } else {
      if (chave < vetor[meio]){
        return busca_binaria(vetor, chave, inicio, meio - 1);
      } else {
        return busca_binaria(vetor, chave, meio + 1, fim);

      }
    }
  }

  return 0; // chave não encontrada
}
