#include <stdio.h>
#include <stdlib.h>


/*
Carlos Henrique 
Matheus Ferreira
Iuri Ramon
*/
int main ()
{
	int v[4],v2[4];
	int i,j,k,l,t=0,min=50;
	int mat[4][4];
	
	v[0] = 0; 
	v[4] = 0;
	

	
	mat[0][0] = mat[1][1] = mat[2][2] = mat[3][3] = 0;
	mat[1][0] = mat[0][1] = 2;
	mat[2][0] = mat[0][2] = 8;
	mat[3][0] = mat[0][3] = 5;
	mat[1][2] = mat[2][1] = 3;
	mat[1][3] = mat[3][1] = 4;
	mat[2][3] = mat[3][2] = 7;
	
	printf("Matriz gerada\n");
	for (i=0;i<4;i++)
	{
			for (j=0;j<4;j++)
			{
				printf("%d ", mat[i][j]);	
			}
			printf("\n");
	}
	
	
	for(i=1;i<=3;i++){
		for(j=1;j<=3;j++){
			for(k=1;k<=3;k++){
				if(i!=k && i!=j && j!=k)
				{
					
					v[1]=i;
					v[2]=j;
					v[3]=k;
					
					for(l=0;l<4;l++)
					{
						int li,col,soma;
						li = v[l];
						col = v[l+1];
						soma = mat[li][col];
						t = soma + t;
			
						
					}
					printf("\n\nCusto: \n %d \nPercurso: \n", t);
					for(l=0;l<=4;l++)
						{
							if(0==v[l])
								printf(" A ");
							if(1==v[l])
								printf(" B ");
							if(2==v[l])
								printf(" C ");
							if(3==v[l])
								printf(" D ");
						}
					if(min>=t)
						{
							
							min = t;
	
							for(l=0;l<=4;l++)
							{
									
								v2[l]=v[l];
							}
											
						
						}
							t=0;
					
				}
	
			}
		}
	}
	printf("\n\n***MELHOR RESULTADO***\nCusto: \n %d \nPercurso: \n", min);
	for(l=0;l<=4;l++)
	{
		if(0==v2[l])
			printf(" A ");
		if(1==v2[l])
			printf(" B ");
		if(2==v2[l])
			printf(" C ");
		if(3==v2[l])
			printf(" D ");
	}
		
		
	printf("\nAtencao: o percurso inverso possui o mesmo custo neste caso");
			
}	
