#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tempo.h"

/* Cada função a seguir calcula o tempo inicial ate o tempo final que o algoritmo leva para cada busca. */

long double tempo_arvore(Abb **arvore, int chave){
    int aux;
    time_t tempo_inicio, tempo_fim;
    long double tempo_total; 

    tempo_inicio = clock();
    aux = busca_arvore(&(*arvore), chave);
    tempo_fim = clock();

    tempo_total = (long double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;

    return tempo_total;

}

long double tempo_lista_encadeada(Lista **lista, int chave){
    int aux;
    time_t tempo_inicio, tempo_fim;
    long double tempo_total; 

    tempo_inicio = clock();
    aux = busca_lista(&(*lista), chave);
    tempo_fim = clock();

    tempo_total = (long double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;

    return tempo_total;

}

long double tempo_sequencial_vetor(int *vetor, int n, int chave){
  int aux;
  time_t tempo_inicio, tempo_fim;
  long double tempo_total; 

  tempo_inicio = clock();
  aux = busca_sequencial(vetor, n, chave);
  tempo_fim = clock();

  tempo_total = (long double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;

  return tempo_total;

}

long double tempo_busca_binaria(int *vetor, int chave, int inicio, int fim){
  int aux;
  time_t tempo_inicio, tempo_fim;
  long double tempo_total; 

  tempo_inicio = clock();
  aux = busca_binaria(vetor, chave, inicio, fim);
  tempo_fim = clock();

  tempo_total = (long double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;

  return tempo_total;

}