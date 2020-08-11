#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	int i, j=0, troco=0,total=0;
	int VMoeda[5]; 
	VMoeda[0] = 20;  
	VMoeda[1] = 10;  
	VMoeda[2] = 5;  
	VMoeda[3] = 2;  
	VMoeda[4] = 1;  
	
	
		printf("Qual valor do Troco:"); // troco 
		scanf("%d",&troco);
	
		int VMoeda2[troco]; // vetor que armazena a solção de tamanho de troco ... caso só entre moeda de 1.
		
		for(i=0; i<=4; i++) // Só sair quando tem a soluçao
		{

		
			if(  (total + VMoeda[i]) <= troco)// testa até ter um resultado bom ou ótimo
			{
				VMoeda2[j]=VMoeda[i];
				total = total + VMoeda[i];
				j=j+1;
				i = i -1;
			}
			else if(troco == total)// condição apenas é válida devido a ter a moeda 1, sendo assim o algoritmo guloso e preciso
				i = troco;
		}	
	
		for(i=0; i<=(j-1); i++) // mostra os resultados 
		{
			printf("Moeda: %d \n", VMoeda2[i]);
	
		}
	
}
