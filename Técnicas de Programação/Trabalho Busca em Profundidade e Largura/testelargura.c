#define vertex int
#include<stdio.h>
#include<stdlib.h>

struct graph {
   int V; 
   int A; 
   int **adj; 
};

typedef struct graph *Graph;



// fila
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

void Busca_Largura( Graph G, int s, int *num, int *ord);
static int **MATRIXint( int r, int c, int val);
void GRAPHinsertArc( Graph G, vertex v, vertex w);
void GRAPHremoveArc( Graph G, vertex v, vertex w);
Graph GRAPHinit( int V) ;


//funcoes fila
int inserir(int elem);
int remover(int *elem);
void imprimir(void);
int vazia(void);
void criar(void);


int main()

{
	
	int  s2,i,j, op, V,  result;
    Graph G;
    printf ("Digite o numero de vertices\n");  
    scanf ("%d", &V);
    int grau[V];
    int visit[V];
    int num[V];
    int ord[V];
    int pre[V];
    
    G = GRAPHinit( V);
		do
 	   {
    	    printf(" 1 - Inserir um par que sera ligado \n 2 - finalizar\n" );
	        scanf ("%d", &op);
    	    
        	if (op == 1)
			{
             printf ("Digite o par de vertices que quer ligar\n");
           	 
			 scanf("%d",&i);
           	 scanf("%d",&j);
				if(i!=j)
				{       
           			GRAPHinsertArc(  G,  i,  j);
           	 		GRAPHinsertArc(  G,  j,  i);
        		}
        		else
        			printf("Nao pode ligar um vertice a ele mesmo \n");
        	}
		}while (op==1);    	
		
		
		printf ("Digite o vertice de saida\n");
			scanf ("%d", &s2);
			Busca_Largura(G, s2, num, ord);
			printf ("O vetor num: ");
			for (i=0; i<V; i++)
			{
				printf ("%d  ", num[i]);
			}						
			printf ("\n");
			printf ("A ordem de descoberta dos vertices foi: ");
			for (i=0; i<V; i++)
			{
				printf ("%d  ", ord[i]);
			}
			printf ("\n");
}

Graph GRAPHinit( int V) { 
   Graph G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = MATRIXint( V, V, 0);
   return G;
}


static int **MATRIXint( int r, int c, int val) { 
  
    int i, j;   
   int **m = malloc( r * sizeof (int *));
   for ( i = 0; i < r; ++i) 
      m[i] = malloc( c * sizeof (int));
   for (i = 0; i < r; ++i)
      for (j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}



void GRAPHinsertArc( Graph G, vertex v, vertex w) { 
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1; 
      G->A++;
   }
}



void GRAPHremoveArc( Graph G, vertex v, vertex w) { 
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0; 
      G->A--;
   }
}

void Busca_Largura( Graph G, int s, int *num, int *ord) 
{ 
   int w,a, cnt = 0;
   for ( a = 0; a < G->V; ++a)
      num[a] = -1;
   criar( );//cria uma fila vazia
   ord[cnt] = s;
   num[s] = cnt++; 
   inserir(s);
    
   while (!vazia( )) {
       int v;
		remover(&v); 
      for (w = 0; w< G->V; w++)
         if (num[w] == -1 && G->adj[v][w]!=0) {
            ord[cnt] = w;
			num[w] = cnt++; 
            inserir(w); 
         }
   }
   //EliminaFila( ); 
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

/* arvore de busca em largura 
static int num[1000];
static vertex pa[1000];
void GRAPHbfs( Graph G, vertex s) 
{ 
   int cnt = 0;
   for (vertex v = 0; v < G->V; ++v)
      num[v] = pa[v] = -1;
   QUEUEinit( G->V);
   num[s] = cnt++; 
   pa[s] = s;
   QUEUEput( s); 

   while (!QUEUEempty( )) {
      vertex v = QUEUEget( ); 
      for (link a = G->adj[v]; a != NULL; a = a->next)
         if (num[a->w] == -1) {
            num[a->w] = cnt++; 
            pa[a->w] = v;
            QUEUEput( a->w); 
         }
   }
   QUEUEfree( ); 
}*/
