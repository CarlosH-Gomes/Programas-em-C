#include<stdio.h>
#include<stdlib.h>

//vamos assumir que o ponteiro ult aponta para o ultimo elemento da lista
//a inserção sempre acontecerá no fim da lista, logo, uma posição posterior a ult, o que facilita
//a inserção já que temos uma lista circular simplesmente encadeada
typedef struct no
{
	char elem;
	struct no *prox;
}no;

typedef struct 
{
	no *ult;
}listaC;


//declaração de duas variáveis do tipo lista

void criar(listaC *l);//recebe uma lista circular e cria uma lista vazia
int inserir(char c, listaC *l);//insere o elemento c na lista circular l
int remover(listaC *l,char *e);//remove o elemento e da lista circular l, retornando o elemento a ser
//eliminado em e, ou null caso não o encontre
int vazia(listaC *l);//retorna 1 se a lista estiver vazia, 0 caso contrário
void imprimir(listaC *l);//imprime todos os elementos da lista l


int main(void)
{
	listaC l1,l2;
	
	char c;
	int op;
	
	
	criar(&l1);
	
	
	do{
	
	printf("Digite 1-para inserir na lista\n2-para remover da lista\n3 para imprimir a lista\n4-para sair\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			printf("Digite o caracter\n");
			scanf(" %c",&c);
			if(inserir(c,&l1))
				printf("Sucesso\n")	;
			else
				printf("Overflow de memória\n");
			break;
		case 2:
			printf("Digite o caractere a ser removido\n");
			scanf(" %c",&c);
			if(remover(&l1,&c))
				printf("O elemento removido foi %c\n",c);
			else
				printf("underflow de lista\n");
			break;
		case 3:
			imprimir(&l1);
			break;
		
	}
	}while(op!=4);
	
}

void criar(listaC *l)
{
	l->ult = NULL;
}

int inserir(char c, listaC *l)
{
	
	no *novo;
	
	novo = malloc(sizeof (no));
	
	if(!novo)
		return 0;
	
	novo->prox=NULL;
	novo->elem = c;
	
	
	if(vazia(l))
	{
		l->ult = novo;//o no novo é o primeiro da lista
		l->ult->prox = l->ult;//o campo prox de prim aponta para ele mesmo
		
	}
	else
	{
		novo->prox = l->ult->prox;//o campo prox de novo aponta para o primeiro no da lista, o qual
		//está na frente de ult
		l->ult->prox = novo;//o campo prox do ult aponta para o novo no inserido
		l->ult = novo;//o novo no inserido será agora o ultimo no da lista
		
	}
	
	return 1;
}

int vazia(listaC *l)
{
	if(l->ult == NULL)//se o ponteiro para inicia da lista estiver nulo
		return 1;
	else
		return 0;
}
 int remover(listaC *l,char *e)
 {
 	no *aux1,*aux2;
 	
 	if(vazia(l))
 		return 0;
 	else
 	{
 		aux1=l->ult->prox;//aux aponta para primeiro da lista
 		aux2 = l->ult;//aux2 aponta para o ultimo
 		while((aux1!=l->ult) && (aux1->elem!=*e))
 		{	
 			printf("%c ",aux1->elem);
 			aux2 = aux1;
 			aux1 = aux1->prox;	
		}
		
		if(aux1->elem == *e)//o elemento foi encontrado em algum no da lista
		{
			if(aux1!=l->ult)//posso deletar o no aux1 sem me preocupar em atualizar o ponteiro ult
			{
				aux2->prox = aux1->prox;
				free(aux1);
			}
			else//o no a ser removido é o ponteiro ult, logo ele precisa ser atualizado
			{//antes de ser deletar para não perdermos o acesso a lista
				if(aux2==aux1)
				{//antes, verificamos se existe apenas um no na lista, o qual será removido
					free(aux1);
					l->ult = NULL;//a lista ficou vazia
				}
				else
				{ //existe mais de um no na lista
					aux2->prox = aux1->prox;
					l->ult = aux2;//o ponteiro ult volta um nó na lista
					free(aux1);
				}
				
			}
			return 1;	
		}
		else
		{
			printf("No não encontrado\n");
				
			return 0;
				
		}
		
		
	}
 	
 	
}

void imprimir(listaC *l)
{
	no *aux;
	
	if(vazia(l))
		printf("Lista vazia\n");
	
	else
	{
		aux=l->ult->prox;
		while(aux!=l->ult)
		{
			printf("%c\n",aux->elem);
			aux = aux->prox;
		}
		printf("%c\n",aux->elem);
		
	}
}
