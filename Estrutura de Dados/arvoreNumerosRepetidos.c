#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
	int info;
	struct no *esq;
	struct no *dir;
	
}no;


typedef struct
{
	no *raiz;
}arvore;

//fun��es de manipula��o de uma arvore bin�ria
//1 - info(p) - retorna a informa��o armazenada no n� p
//2 - left(p) - retorna o filho � esquerda do n� p
//3 - rigth(p) - retorna o filho � direita do n� p
//4 - father(p) - retorna um ponteiro para o n� pai do n� p
//5 - brother(p) - retorna um ponteiro para o n� irm�o do n� p
//6 - criar(avr) - retorna um ponteiro para uma �rvore, ou seja, um ponteiro para sua raiz
//7 - setleft(p) - cria um n� filho � esquerda do no p.
//8 - setrigth(p) - cria um n� filho � direita do n� p.


void criar(arvore *av);//cria uma arvore vazia
int criarR(arvore *av,int e);//cria uma �rore com raiz diferente de nulo
void info(no *p,int *i);//
no* left(no *pai);
void rigth(no *pai, no *fdir);
void setrigth(no *pai, int n);
void setleft(no *pai, int n);
int busca(arvore *av);
int vazia(arvore *av);
int inserir(arvore *a,int n);

void criar(arvore *av)
{
	av->raiz = NULL;
}

int criarR(arvore *av,int e)
{
	no *novo;
	
	novo = malloc(sizeof(no));
	
	if(!novo)
		return 0;
	else
	{
		novo->info = e;
		novo->dir = NULL;
		novo->esq = NULL;
		av->raiz = novo;
		return 1;
	}
}

void info(no *p,int *i)
{
	if(p!=NULL)
		*i = p->info;//a variavel apontada por i recebe o valor do campo info do n� apontado por p
	else
		i = NULL;
}


no* left(no *pai)
{
	
	return pai->esq;//fesq recebe o filho esquerdo do n� pai
}

void rigth(no *pai, no *fdir)
{
	fdir = pai->dir;//fesq recebe o filho esquerdo do n� pai
}

//5 - brother(p) - retorna um ponteiro para o n� irm�o do n� p

//7 - setleft(p) - cria um n� filho � esquerda do no p.

void setleft(no *p, int n)
{
	no *novo;
	
	novo = malloc(sizeof(no));
	if(!novo)
	{
	
		printf("mem�ria cheia\n");
		return;
	}
	
	novo->info = n;
	novo->dir = NULL;
	novo->esq = NULL;
	
	p->esq = novo;	
	
}

//8 - setrigth(p) - cria um n� filho � direita do n� p.
void setrigth(no *p, int n)
{
	no *novo;
	
	novo = malloc(sizeof(no));
	if(!novo)
	{
	
		printf("mem�ria cheia\n");
		return;
	}
	
	novo->info = n;
	novo->dir = NULL;
	novo->esq = NULL;
	
	p->dir = novo;	
	
}

int vazia(arvore *av)
{
	if(av->raiz == NULL)
		return 1;
	else
		return 0;
}


int busca(arvore *av)
{
	no *aux;
	int chave, n;
	aux = av->raiz;
	
	printf("%d\n",aux->info);
	
	printf("Qual n�mero deseja localizar?\n");
	scanf("%d",&chave);
	
	if(!vazia(av))
	{
		 	info(aux,&n);
			printf("%d\n",n);
	}
	
	
	else
		return 0;
		
	while((aux!=NULL)&&(n!=chave))
	{
		
		if(chave < n)
		{
			aux = left(aux);//atualiza aux para o n� filho esquerdo
			info(aux,&n);//passo o no atual e recebe o campo info deste no para compara��o
		}
		else
		{
			rigth(aux,aux);//atualiza aux para o n� filho direito
			info(aux,&n);//passo o no atual e recebe o campo info deste no para compara��o
		}
			
		
		
	}
	if(n == chave)//chave encontrada
		return 1;
	else
		return 0;
	
	
}


