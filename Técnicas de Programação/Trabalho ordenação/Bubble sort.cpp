#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void bubble (int vetor[],int k );

int main(void){
	
	
	int* vetor;
	int i,n,j, aux;
 	int k = NULL;//escolher quantidade de numeros 


	//printf("Tamanho do vetor(Bubble): ");
	//scanf("%i", &k);

	vetor = (int *)malloc(k * sizeof(int));

	for (int i = 0; i < k; i++)
	{
		vetor[i] = rand() % k + 1;

		printf("Valor  %i : %i" , i+1,  vetor[i]);
		printf("\n");
	}
	
	
	//bubble
	bubble(vetor, k );
   

	for (int i = 0; i < k; i++)
	{

		printf("Valor  %i : %i" , i+1, vetor[i]);
		printf("\n");
	}
	
	return 0;
}

void bubble (int vetor[],int k )
{
	int i, j, aux;
 
	 for (i = 1; i < k; i++)
	  {
	        for (j = 0; j < k - 1; j++) {
	            if (vetor[j] > vetor[j + 1]) {
	                aux          = vetor[j];
	                vetor[j]     = vetor[j + 1];
	                vetor[j + 1] = aux;
	            }
	        }
	    }
}
