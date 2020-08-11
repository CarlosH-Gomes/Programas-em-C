#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	int i, j, maior=0,posicao = 0,maiorPreco,maiorPeso;
	int VPreco[4],VPreco2[4], VPeso[4], VPeso2[4]; 
	VPreco[0] = 42;  VPeso[0] = 7;
	VPreco[1] = 12;  VPeso[1] = 3;
	VPreco[2] = 40;  VPeso[2] = 4;
	VPreco[3] = 25;  VPeso[3] = 5;
	
	for(j=0; j<=3; j++)// organiza o vetor em ordem decrescente de valor
	{
		for(i=0; i<=3; i++) // Garante que o Maior preco das posibilidades será selecionado
		{
			if(maior < VPreco[i])
			{
				
					maiorPreco =VPreco[i] ;
					maiorPeso =VPeso[i] ;
					maior = VPreco[i];
					posicao = i;
			}	
	
		}
		VPreco2[j] = maiorPreco;
		VPeso2[j] = maiorPeso;
		VPreco[posicao] = VPeso[posicao] = maior = 0;
	}
		
		VPreco[0]= VPreco2[0];// sabemos que na possição 0 do vetor terá o maior valor e ele sempre será usado
		VPeso[0]= VPeso2[0];
		j=1;
		
		for(i=1; i<=3; i++) // i=1 começa em 1 devido a comentario anterior, o laço acha os demais  maiores  valores que não  estoure o peso 
		{
		
		
			if( (VPeso2[0] + VPeso2[i]) <= 10)
			{
				VPreco[j]=VPreco2[i];
				VPeso[j]=VPeso2[i];
				j=j+1;
			}
		}	
		maior = 0;
		for(i=0; i<=(j-1); i++) // mostra os resultados 
		{
			printf("Preco: %d \n", VPreco[i]);
			printf("Peso: %d \n\n", VPeso[i]);
			maior = VPreco[i] + maior;
		}
		printf("\n Custo Total: R$%d \n", maior);
		
}
