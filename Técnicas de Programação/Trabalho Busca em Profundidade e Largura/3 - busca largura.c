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



Graph GRAPHinit( int V);
static int **MATRIXint( int r, int c, int val);
void GRAPHinsertArc( Graph G, vertex v, vertex w);
void GRAPHremoveArc( Graph G, vertex v, vertex w);
void GRAPHshow( Graph G);
void UGRAPHdegrees(Graph G, vertex v, vertex w, int *grau );
void reachR(Graph G, int v, int *visit, int t);
int GRAFO_CAMINHO(Graph G, int s, int t, int *visit);  
void Busca_Largura( Graph G, int s, int *num, int *ord); 
void Busca_dfs( Graph G, int *pre);
static void dfsR( Graph G, int v, int *pre); 

//funcoes fila
int inserir(int elem);
int remover(int *elem);
void imprimir(void);
int vazia(void);
void criar(void);


int cnt = 0;

int main(){
    
    int  s2,i,j, op, op2, op3, V, s, t, result;
    Graph G;
    printf ("Digite o numero de vertices\n");  
    scanf ("%d", &V);
    int grau[V];
    int visit[V];
    int num[V];
    int ord[V];
    int pre[V];
  
    G = GRAPHinit( V);
    
    
    printf ("1- Para grafos dirigidos\n2- Para grafos nao dirigidos\n");
    scanf ("%d", &op3);
	printf("Lembrando que a contagem dos vertices se inicia 0 e termina em %d, caso digite um vertice de valor maior o programa retornara erro\n", (V-1));
    if (op3 == 1)
    {
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
	            	//GRAPHinsertArc(  G,  j,  i);
	        	}
	        	else
	        		printf("Nao pode ligar um vertice a ele mesmo \n");
	        }
		}while (op==1);

    }
    else if (op3==2)
    {
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
	
	}
	else 
	printf("Opcao nao identificada finalizando programa\n");
	system ("pause");
    
    for(i=0;i<V;i++)
    {
    	 for(j=0;j<V;j++)
    	{
    		printf(" %d ",G->adj[i][j]);
		}
		printf("\n");
	}
 
	do
	{
 	printf ("\n 1 - Para ver o grau de cada vertice\n 2 - Para verificar se existe caminho entre dois vertices\n 3- Para executar a busca em largura\n 4- Para executar a busca em profundidade\n 5- Para finalizar\n");
 	scanf ("%d", &op2);
 	switch (op2)
 	{
 		case 1:
 		{
	 		UGRAPHdegrees(G, V, V,  grau );
    		for (i = 0; i<V; i++)
    		{
        		printf ("grau de %d: %d  \n",i, grau[i]);
    		}	   	
		}
		break;
		
		case 2:
		
		{
			printf ("Digite o vertice de saida\n");
			scanf ("%d", &s);
			printf ("Digite o vertice de chegada\n");
			scanf ("%d", &t);		
			result = GRAFO_CAMINHO(G, s, t, visit);
			/*for (i=0; i<V; i++)
			{
				printf ("%d  ", visit[i]);
			}*/
			printf ("\n");
			if (result == 1)
			{
				printf ("Existe caminho entre os vertices\n");
			}
			else 
			printf ("Não existe caminho entre os vertices\n");
		 }
		 break;
		
		case 3:
		{
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
		break;
		case 4:
		{
			Busca_dfs(G, pre);
			printf ("O vetor pre: ");
			for (i=0; i<V; i++)
			{
				printf ("%d  ", pre[i]);
			}
			printf ("\n");			
		}
		break;	
	}

}while (op2!=5);

    
    system("pause");
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


void GRAPHshow( Graph G) { 
    int v, w;
   for (v = 0; v < G->V; ++v) {
      printf( "%2d:", v);
      for (w = 0; w < G->V; ++w)
         if (G->adj[v][w] == 1) 
            printf( " %2d", w);
      printf( "\n");
   }
}

void UGRAPHdegrees(Graph G, vertex v, vertex w, int *grau )
{
    int i, j, soma;
    for (i = 0; i<v; i++)
    {
        soma= 0;
        for(j = 0; j<v; j++)
        {
            G->adj[i][j];
            if ((G->adj[i][j]==1)&&(G->adj[i][j] != G->adj[j][i]))
            soma = soma+1;
        }
        for(j = 0; j<v; j++)
        {
            G->adj[j][i];
            if ((G->adj[j][i]==1))
            soma = soma+1;
                        
        } 
        grau[i] = soma;
      
 
 
    }
     
}



int GRAFO_CAMINHO(Graph G, int s, int t, int *visit) 
{ 
int v;
for(v = 0; v < (G->V) ; ++v)
    visit[v] = 0;
   reachR( G, s, visit, t);
if
 (visit[t] == 0) 
return
 0;
else
return
 1;
}


void reachR(Graph G, int v, int *visit, int t) 
{ 
	int w, i;   
		visit[v] = 1;
    	printf ("(G, %d):", v);
		for (i=0; i<G->V; i++)
		{
			printf (" %d  ", visit[i]);
		}
		printf ("\n");
   	//if (visit[t] ==1)
	//return;
   	//else
   	{
		for (w = 0; w < G->V; ++w)
		{
			if (G->adj[v][w] == 1 && visit[w] == 0 && visit[t]!=1)
				reachR( G, w, visit, t);
	    		
		}   		
 	return;
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



void Busca_dfs( Graph G, int *pre) 
{ 
   int  v;
   
   for (v = 0; v < G->V; ++v) 
      pre[v] = -1;
   for (v = 0; v < G->V; ++v)
      if (pre[v] == -1) 
         dfsR( G, v, pre); // começa nova etapa
}

static void dfsR( Graph G, int v, int *pre) 
{ 
   int w;
   pre[v] = cnt++; 
   for ( w = 0; w < G->V; ++w)
      if (G->adj[v][w] != 0 && pre[w] == -1)
         dfsR( G, w, pre); 
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
