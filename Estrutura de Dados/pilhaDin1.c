#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
	int elem;
	struct no *prox,*ant;
	
}no;

no *topo=NULL;

void push(int num);
int pop(void);

int main(void)
{
	
	int num,i,op;
	
	do
	{
		printf("Digite qsuas opções\n: 1-emplilhar\n2-desempilhar o topo\n3-esvaziar a pilha\n4-sair");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("Digite o número\n");
				scanf("%d",&num);
				push(num);
				break;
			case 2:
				if(!pop())
				{
					printf("Pilha vazia\n");
				}
				break;
			case 3:
				if(!topo)
				{
					printf("Pilha vazia\n");
				}
				else
				{
						for(;pop(););
						printf("Pilha vazia\n");
				}
				
					
				break;
			case 4:
				printf("sair\n");
				break;
			default:
				printf("opção invalida. Tente novamente\n");
				break;
		}
	}while(op!=4);
	
		
}
	
void push(int num)	
{
	no *novo;//novo no que sera inserido na pilha
	
	novo = malloc(sizeof(no));//alocar a memoria necessaria para armazenar um no
	novo->prox = NULL;//
	novo->elem=num;
	novo->ant = NULL;
	
	if(!topo)//se a pilha estiver vazia, basta topo apontar para o novo no
	{
		topo=novo;//topo aponta para o novo no
	}
	
	else{
		topo->prox = novo;//o campo prox de topo aponta para o novo no
	novo->ant = topo;//o campo anterior do novo no aponta para topo
	topo = novo;//topo é atualizada, ou seja, aponta para o ultimo no inserido
	}
	
	
}

int pop(void)
{
	no *aux;
	
	if(topo!=NULL)//desempilho se a pilha não estiver vazia
	{
		aux = topo;//aux aponta para o topo
		topo = topo->ant;//atualizo topo para o no anterior da pilha
		printf("elemento desempilhado %d\n",aux->elem);//imprimo o valor do topo antes de desempilhar
		free(aux);//libero o espaço da memoria reservado para o topo
		return 1;
	}
	else
		return 0;
}
	
	

