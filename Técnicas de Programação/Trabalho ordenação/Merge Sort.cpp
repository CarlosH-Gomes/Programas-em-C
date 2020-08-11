#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void mergeSort(int vetor[], int l, int r);
void merge(int vetor[], int l, int m, int r);

int main(void){
	
	
	int* vetor;
	int i,n,j, aux;
 	int k = 100000;//escolher quantidade de numeros


//	printf("Tamanho do vetor(Merge): ");
//	scanf("%i", &k);

	vetor = (int *)malloc(k * sizeof(int));

	for (int i = 0; i < k; i++)
	{
		vetor[i] = rand() % k + 1;

		printf("Valor  %i : %i" , i+1,  vetor[i]);
		printf("\n");
	}
	
	mergeSort(vetor,i=0, k-1);
	for (int i = 0; i < k; i++)//mostra Resultados
	{

		printf("Valor  %i : %i" , i+1, vetor[i]);
		printf("\n");
	}
}

void merge(int vetor[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* cria os vetores temporarios */
    int L[n1], R[n2];
 
    /* copia de dado */
    for (i = 0; i < n1; i++)
        L[i] = vetor[l + i];
    for (j = 0; j < n2; j++)
        R[j] = vetor[m + 1+ j];
 
    
    i = 0; // indice inicial
    j = 0; // indice inicial do segundo
    k = l; // indice o array mesclado
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vetor[k] = L[i];
            i++;
        }
        else
        {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* 
Copie os elementos restantes de L [], se houver*/
    while (i < n1)
    {
        vetor[k] = L[i];
        i++;
        k++;
    }
 
    /* Copie os elementos restantes de R [], se houver */
    while (j < n2)
    {
        vetor[k] = R[j];
        j++;
        k++;
    }
}
 
/* l é para o índice esquerdo e r é o índice direito do
   sub-array do vetor para ser ordenado */
void mergeSort(int vetor[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;
 
        //Classificar primeira e segunda metade
        mergeSort(vetor, l, m);
        mergeSort(vetor, m+1, r);
 
        merge(vetor, l, m, r);
    }
}
