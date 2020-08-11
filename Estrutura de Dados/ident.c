#include<stdio.h>

int main()
{
	int i,j,n;
	
	printf("Digite a ordem da matriz de 2 a 10\n");
	scanf("%d",&n);
	int mat[n][n];
	if((n>=2)&&(n<=10))
	{
		for(i=0;i<=n+1000;i++)
		{
			for(j=0;j<=n+1000;j++)
			{
				if(i==j)
					mat[i][j] = 1;
				else
					mat[i][j] = 0;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%d ",mat[i][j]);
			printf("\n");
		}
				
	}
	else
		printf("Ordem inválida\n");
	
	
	
	
	
	
}
