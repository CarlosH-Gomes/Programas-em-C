#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void insertionSort(int vetor[], int k);

int main(void){
	
	
	int* vetor;
	int i,n,j, aux;
 	int k = 100000;//escolher quantidade de numeros


//	printf("Tamanho do vetor(insertion): ");
//	scanf("%i", &k);

	vetor = (int *)malloc(k * sizeof(int));

	for (int i = 0; i < k; i++)
	{
		vetor[i] = rand() % k + 1;

		printf("Valor  %i : %i" , i+1,  vetor[i]);
		printf("\n");
	}
	
	insertionSort(vetor,k);
	for (int i = 0; i < k; i++)//mostra Resultados
	{

		printf("Valor  %i : %i" , i+1, vetor[i]);
		printf("\n");
	}
}

void insertionSort(int vetor[], int k)
{
   int i, comp, j;
   for (i = 1; i < k; i++)
   {
       comp = vetor[i];
       j = i-1;
 
       /* Mover elementos de vetor [0..i-1], que são
          maior que a chave, para uma posição à frente
          da sua posição atual */
       while (j >= 0 && vetor[j] > comp)
       {
           vetor[j+1] = vetor[j];
           j = j-1;
       }
       vetor[j+1] = comp;
   }
}

