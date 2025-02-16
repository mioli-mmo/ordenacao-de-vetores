#include <iostream>
#include <algorithm>
#include "ordenacao.hpp"

/*
  Função que retorna se um vetor 'a' de 't' elementos 
  está ordenado não decrescentemente --- Ou seja, não está ordenada (menor --> maior)

  Retorno: false Se 'a' não estiver ordenado
           true caso contrário
*/
/* Implementar função */
bool ordenado(int a[], int t){
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
void selecao(int a[], int t){
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
void insercao(int a[], int t){
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
// 1) FUNÇÃO MERGE
void merge(int a[], int p, int q, int r) {
  
	int n1 = q - p + 1; // n1 = metade esquerda
	int n2 = r - q;	  // n2 = metade direita

	// cria os dois subarrays com as duas metades
	int a1[n1];
	int a2[n2];
  
	for (int i = 0; i < n1; i++) { // copia elementos para subarray a1
		a1[i] = a[p + i];
	}

	for (int j = 0; j < n2; j++) { // copia elementos para subarray a2
		a2[j] = a[q + 1 + j];
	}

	int i = 0, j = 0, k = p; // armazena índices dos arrays

	// Confere qual o menor elemento entre subarrays e o adicona ao array final
	while ( (i < n1) && (j < n2) ) { // execute enquanto ouver elementos em ambos os subrrays
	if (a1[i] <= a2[j]) { 
	  a[k] = a1[i];
	  i++; // avança para o próximo elemento de a1
	} else {
	  a[k] = a2[j];
	  j++; // avança para o próximo elemento de a2
	}
	k++;
	}

	// Quando chega ao fim de algum dos subarrays, copia restante para o array final
	for (; i < n1; i++, k++) { // copia de a1
	a[k] = a1[i];
	}

	for (; j < n2; j++, k++) { // copia de a2
	a[k] = a2[j];
	}
	}

// 2) FUNÇÃO MERGE SORT
// l = left		m = mid		r = right
void mergeSort(int a[], int l, int r) {
  if (l < r) {
	int m = l + (r - l) / 2; // define o ponto médio entre os subarrays
	
	mergeSort(a, l, m); // aplica mergeSort na esquerda
	mergeSort(a, m + 1, r); // aplica mergeSort na direita

	merge(a, l, m, r); // junta os subarrays em um
  }
}
