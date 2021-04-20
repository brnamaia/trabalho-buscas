// Bruna Raynara Maia Batista - 499257
// Domingos Mykaeull Gomes Peres - 500594

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "busca.h"
#include "lista.h"
#include "arvore.h"
#include "tempo.h"

#define K 1100000
#define N 2000

// OBS: as vezes a busca na árvore gera pouco menos de 2s e as vezes gera pouco mais de 2s (levar isso em consideração).

int main(){
  Abb *arvore;
  Lista *lista;
  int vetor[N];
  int chave; 
  int p = 0;
	int *indice = &p;
  int i;
  long double tempo_lista = 0.0;
  long double tempo_abb = 0.0;
  long double tempo_binaria = 0.0; 
  long double tempo_sequencial = 0.0;

  inicializar_arvore(&arvore);
  inicializar_lista(&lista);
  
  gerar_tuplas(N, &arvore, &lista);

  percurso_em_ordem(&arvore, vetor, indice);

  srand(time(NULL));

  // realiza as 4 buscas da aplicação K vezes, retornando a cada iteração o tempo da busca e incrementando(somando) a um contador criado para cada algoritmo de busca.
  for (i = 0; i < K; i++){
    chave = rand() % N;

    tempo_abb += tempo_arvore(&arvore, chave);

    tempo_lista += tempo_lista_encadeada(&lista, chave);

    tempo_binaria += tempo_busca_binaria(vetor, chave, 0, N);

    tempo_sequencial += tempo_sequencial_vetor(vetor, N, chave);

  }

  printf("------------------------------------------------------\n");
  printf("Tempo de busca na arvore: %Lf segundos\n", tempo_abb);
  printf("Tempo de busca na lista: %Lf segundos\n", tempo_lista);
  printf("Tempo da busca binaria no vetor: %Lf segundos\n", tempo_binaria);
  printf("Tempo de busca sequencial no vetor: %Lf segundos \n", tempo_sequencial);
  printf("------------------------------------------------------\n");

  return 0; 

}