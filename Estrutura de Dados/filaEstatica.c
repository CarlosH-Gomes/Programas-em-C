#include<stdio.h>


typedef struct
{
	int f[100];//o conteudo da fila
	int prim;//armazena o indice do primeiro elemento da fila
	int ult;//armazena o indice do ultimo elemento da fila
}fila;

fila f1;//variavel do tipo fila


//f1.prim = 0;a
//f1.ult = -1;

int inserir(int elem);//recebe o elemento a ser inserido e retorna sucesso ou fracasso 
int remover(int *elem);//recebe o endereço de um inteiro para retornar o elemento removido
//retorna sucesso ou fracasso
int vazia(void);//retorna 1 se a fila estiver vazia, 0 caso contrário
void imprimir();

int main(void)
{
	f1.prim=0;//o indice prim indica a posição atual de remoção e quando a fila está vazia deve estar no
//0 pois não existe elemento ali. Não há problemas com isso pois vamos usar o ult para indicar fila vazi
	f1.ult=-1;//o indice ult indica a posicao atual de inserção
	int op,e;
	
	do{
		printf("Digite sua opção, ou 3 para sair");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("Digite o elemento\n");
				scanf("%d",&e);
				if(inserir(e))
					printf("Sucesso\n");
				else
					printf("Fracasso\n");
				break;
			case 2:
				if(remover(&e))
				{
					printf("Elemento removido %d\n",e);
				}
				else
					printf("Fracasso\n");
				break;
			case 4:
				imprimir();
				break;
		}
	
	
	}while(op!=3);
	
	
	
	
}

int inserir(int elem)
{
	if(f1.ult<100)//é possível inserir quando a fila não estiver cheia
	{
		f1.f[++f1.ult] = elem;//antes de inserir, incrementa-se o ult, para se alcançar a posição de inserção
		return 1;
	}
	else
	{
			printf("Fila cheia\n");
			return 0;
	}
	
}

void imprimir()
{
	int i;
	if((f1.ult>=0) && (f1.prim<=f1.ult))
	{
		for(i=f1.prim;i<=f1.ult;i++)
			printf("%d\n",f1.f[i]);
	}
	
}

int remover(int *elem)
{
	//pode-se remover apenas se existir algum elemento na fila
	if((f1.ult>=0) && (f1.prim<=f1.ult))
	{//a fila não está vazia
		
		*elem = f1.f[f1.prim++]	;//recupera o elemento a ser eliminado e incrementa o indice do primeiro da fila
		
		return 1;
	}
	else
	{
		printf("Pilha vazia\n");
		return 0;
	}
}
