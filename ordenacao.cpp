#include <iostream>
#include "ordenacao.hpp"

/*
  Função que retorna se um vetor 'a' de 't' elementos 
  está ordenado não decrescentemente --- Ou seja, não está ordenada (menor --> maior)

  Retorno: false Se 'a' não estiver ordenado
           true caso contrário
*/
/* Implementar função */
bool ordenado(int a[],  unsigned int t){
	for (int i = 0; i < t-1; i++) { // loop do primeiro ao penúltimo
		if (a[i] > a[i+1]) { // verifica ordem CRESCENTE
			return false;
		}
	}
	
	return true; // caso todos estejam ordenados
}


/*
  Função que ordena o vetor 'a' de forma não decrescente
  usando o método de ordenação por seleção.
  A ordenação é feita diretamente no vetor 'a'
*/
/* Implementar função */
void selecao(int a[], unsigned int t){
for (int i = 0; i < t; i++) { // loop externo (index-alvo)
int min_index = i; //supõe atual como menor --- usando index por causa da função swap()

	for (int j = i; j < t; j++) { // loop interno (compara restante do array)
		if (a[j] <= a[min_index]) {
		min_index = j;
		}
	}
	std::swap(a[i], a[min_index]);
	
}
}


/*
  Função que ordena o vetor 'a' de forma não decrescente
  usando o método de ordenação por inserção.
  A ordenação é feita diretamente no vetor 'a'
*/
/* Implementar função */
void insercao(int a[], unsigned int t){
int n_ordenado = 1;

		for (int i = n_ordenado; i < t; i++) { // seleciona próximo elemento nao_ordenado
			int sel = a[i]; // elemento selecionado (2º) é copiado em 'sel'
			int j = i-1; // j começa no primeiro elemento ordenado
			
			while ( (j >= 0) && (sel < a[j]) ) { // itera pela parte ordenada do array de trás para frente
				a[j+1] = a[j]; // se j for maior que sel, j entra à direita
				j--;
			}
			a[j+1] = sel; // senã, sel entra à direita
			
			n_ordenado++;
		}
}


/*
  Função que ordena o vetor 'a' de forma não decrescente
  usando o método de ordenação merge-sort.
  A ordenação é feita diretamente no vetor 'a'
*/
/* TODO: Implementar função */
void merge_sort(int a[], unsigned int t);
