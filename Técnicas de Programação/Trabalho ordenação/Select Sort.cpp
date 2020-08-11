#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void selection_sort (int vetor[],int max);

int main(void){
	
	
	int* vetor;
	int i,n,j, aux;
 	int k = NULL;//escolher quantidade de numeros 


//	printf("Tamanho do vetor(select): ");
//	scanf("%i", &k);

	vetor = (int *)malloc(k * sizeof(int));

	for (int i = 0; i < k; i++)
	{
		vetor[i] = rand() % k + 1;

		printf("Valor  %i : %i" , i+1,  vetor[i]);
		printf("\n");
	}
	

  
 	 selection_sort (vetor, k);
	for (int i = 0; i < k; i++)//mostra Resultados
	{

		printf("Valor  %i : %i" , i+1, vetor[i]);
		printf("\n");
	}
}


void selection_sort (int vetor[],int max) {
  int i, j, min, aux;
  
  for (i = 0; i < (max - 1); i++) {
    /* O minimo é o primeiro número não ordenado ainda */
	    min = i;
	    for (j = i+1; j < max; j++) {
	      /* Caso tenha algum numero menor ele faz a troca do minimo*/
		      if (vetor[j] < vetor[min]) {
		   		min = j;
	      		}
	    }
	    /* Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
	    if (i != min) {
	      aux = vetor[i];
	      vetor[i] = vetor[min];
	      vetor[min] = aux;
    }
  }
  
}


  
  
