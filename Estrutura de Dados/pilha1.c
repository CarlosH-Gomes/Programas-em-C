#include<stdio.h>

int pilha[50];
int topo=0;
int push(int num);
int pop(int *dado);

int main()
{
	int i,op,num,n;
	
	printf("Qual sua opção:\n1-Para empilhar\n2-Para desempilhar\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			printf("Digite o número\n");
			scanf("%d",&num);
			if(push(num))
			{
				printf("Sucesso\n");
			}
			else
				printf("Pilha cheia\n");
			break;
		case 2:
			if(pop(&n))
			{
				printf("o numero desempilhado eh %d\n",n);
			}
			else
				printf("Pilha vazia\n");
			break;
	}
	
	
}

int push(int num)
{
	if(topo<50)
	{
			pilha[topo] = num;
			topo++;
			return 1;
	}
	else
	{
		return 0;
	}
	
}

int pop(int *dado)
{
	if(topo != 0)
	{
		*dado = pilha[--topo];
		return 1;
		
	}
	else
	{
		
		return 0;	
	}
	
	
}

