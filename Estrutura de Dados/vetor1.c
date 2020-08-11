#include<stdio.h>

int main()
{
	int vet1[4]={0,0,0,0},i;
	
	
	
	for(i=0;i<3;i++)
	{
		scanf("%d",&vet1[i]);
	}
	for(i=2;i>=0;i--)
		printf("%d ",vet1[i]);
}
