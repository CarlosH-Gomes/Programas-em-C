#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void QuickSort(int vetor[], int inicio, int fim);

int main(void){
	
	
	int* vetor;
	int i,n,j, aux;
 	int k =10;//escolher quantidade de numeros


//	printf("Tamanho do vetor(Quick): ");
//	scanf("%i", &k);

	vetor = (int *)malloc(k * sizeof(int));

	for (int i = 0; i < k; i++)
	{
		vetor[i] = rand() % k + 1;

		printf("Valor  %i : %i" , i+1,  vetor[i]);
		printf("\n");
	}
	
	QuickSort(vetor,i=0 ,k-1);
	for (int i = 0; i < k; i++)//mostra Resultados
	{

		printf("Valor  %i : %i" , i+1, vetor[i]);
		printf("\n");
	}
}

void QuickSort(int vetor[], int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] < pivo) 
	  		i = i + 1;
      while (vetor[j] > pivo) 
	  		j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   	}while(j > i);
   
   if(inicio < j) 
   		QuickSort(vetor, inicio, j);
   if(i < fim) 
   		QuickSort(vetor, i, fim);   

}

