#include<stdio.h>
#include<stdlib.h>
/* chamada dia 20/10 iuri, carlos, matheus ferreira
danilo
silas
leandro
fabricio
denis
filipe
igor
joao vitor
bruno
lucas andrei
julia
willian
luiz*/


typedef struct no
{
	char elem;
	struct no *prox;
}no;

typedef struct 
{
	no *prim;
}lista;


//declaração de duas variáveis do tipo lista

void criar(lista *l);//recebe uma lista
int inserir(char c, lista *l);
int remover(lista *l,char *e);
int vazia(lista *l);
void imprimir(lista *l);


int main(void)
{
	lista l1,l2;
	
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

void criar(lista *l)
{
	l->prim = NULL;
}

int inserir(char c, lista *l)
{
	
	no *novo;
	
	novo = malloc(sizeof (no));
	
	if(!novo)
		return 0;
	
	novo->prox=NULL;
	novo->elem = c;
	
	
	if(vazia(l))
	{
		l->prim = novo;//o no novo é o primeiro da lista
		
	}
	else
	{
		novo->prox = l->prim;//o campo prox de novo aponta para o prim
		l->prim = novo;//o prim da lista é atualizado para seu inicio
		
	}
	
	return 1;
}

int vazia(lista *l)
{
	if(l->prim == NULL)//se o ponteiro para inicia da lista estiver nulo
		return 1;
	else
		return 0;
}
 int remover(lista *l,char *e)
 {
 	no *aux;
 	
 	if(vazia(l))
 		return 0;
 	else
 	{
 		aux=l->prim;//aux aponta para primeiro da lista
		*e= aux->elem;//o valor da variavel apontada por e recebe o conteudo do elemento que será removido
		l->prim=l->prim->prox;//o ponteiro prim aponta para o proximo no da lista	
		free(aux);
	}
 	
 	return 1;
}

void imprimir(lista *l)
{
	no *aux;
	
	if(vazia(l))
		printf("Lista vazia\n");
	
	else
	{
		aux=l->prim;
		while(aux!=NULL)
		{
			printf("%c\n",aux->elem);
			aux = aux->prox;
		}
	}
}
