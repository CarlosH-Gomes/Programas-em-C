#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
	int elem;//o conteudo de cada no
	struct no *prox;//armazena o indice do primeiro elemento da fila
	
}no;

typedef struct
{
	no *prim;
	no *ult;
}fila;

fila f1;//variável do tipo fila

int inserir(int elem);
int remover(int *elem);
void imprimir(void);
int vazia(void);
void criar(void);

int main(void)
{
	int op,e;
	criar();
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
	no *novo;
	
	novo = malloc(sizeof(no));//alocação de memória
	novo->prox = NULL;//o ponteiro prox será nulo
	novo->elem = elem;//inseri o elemento no novo no
	
	if(vazia())
	{
		f1.prim = f1.ult = novo;//o prim e u ult apontam para o novo no
	}
	else
	{
		f1.ult->prox = novo;//o campo prox de ult aponta para o novo no
		f1.ult = novo;//atualizo a posição do ult
	}
	return 1;
	
	
}
int remover(int *elem)
{
	no *aux;
	if(vazia())
	{
		return 0;
	}
	else
	{
		aux = f1.prim;//variavel auxiliar aponta para o primeiro no da fila
		f1.prim = f1.prim->prox;//atualizo o pontoeiro prim para o proximo no
		*elem = aux->elem;//retorno o elemento que será removido
		free(aux);
		return 1;
		
	}
}
void imprimir(void)
{
	no *aux;
	
	aux = f1.prim;//aux comoça do inicio da fila
	
	while(aux!=NULL)//enquanto não chegar ao fim da fila
	{
		printf("%d ",aux->elem);
		aux = aux->prox;//aux vai para o proximo no
	}
}
int vazia(void){
	
	if(f1.prim == NULL)
		return 1;
	else
		return 0;
}
void criar(void)
{
	f1.prim = NULL;
//	f1.prim->prox = NULL;
	f1.ult = NULL;
	//f1.ult->prox = NULL;
}
