#include<stdio.h>
#include<stdlib.h>
#define vertex int

int cnt;
int pre[1000];
int visit[1000];

/* resultado    0  1  4  5  3  2  6  11 12  7  8  10  9
indice vetor:	0  1  2  3  4  5  6  7  8   9 10 11  12*/

struct graph 
{
   int V; 
   int A; 
   int **adj; 
};

typedef struct graph *Graph;

Graph GRAPHinit( int V);
static int **MATRIXint( int r, int c, int val);
void GRAPHinsertArc( Graph G, vertex v, vertex w);
void Busca_dfs( Graph G);
static void dfsR( Graph G, vertex v);


int main()
{
    int  i,j, op ,V, esc, sai ;
    Graph G;
    printf ("Digite o numero de vertices\n");  
    scanf ("%d", &V);
    int grau[V];
  
    G = GRAPHinit( V);
    
    printf("Lembrando que a contagem se inicia 0\n");
    do 
    {printf(" 1 - Inserir um par que sera ligado \n 2 - ordem de visita profundidade \n 3 - Imprimir matriz de Adj\n 4 - Finalizar\n");
        scanf ("%d", &op);
        switch (op){
		
	        case 1:
	            printf ("Digite o par de vertices que quer ligar\n");
	            scanf("%d",&i);
	            scanf("%d",&j);
				if(i!=j)
				{       
	            	GRAPHinsertArc(G,  i,  j);
	            	GRAPHinsertArc(G,  j,  i);
	        	}
	        	else
	        		printf("Nao pode ligar um vertice a ele mesmo \n");
	        break;
	           
	        
	        case 2:
	        	
	       		Busca_dfs(G);
	       		for(i=0;i<V;i++)
    			{
    				printf(" %d ",pre[i]);
				}
				printf("\n");
				for(i=0;i<V;i++)
    			{
    				printf(" %d ",visit[i]);
				}
				printf("\n");
				system("pause");
				system("cls");
	        break;
	        case 3:
	        	for(i=0;i<V;i++)
			    {
			    	for(j=0;j<V;j++)
			    	{
			    		printf(" %d ",G->adj[i][j]);
			    	}
			    	printf("\n");
			    	
				}
	        break;
	        default :
	        	printf("opcao invalida \n");
			break;
		}
        
       
        
        
    }while (op!=4);
    
 

 	
    
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

///////



void Busca_dfs( Graph G) 
{ 
   cnt = 0;
   vertex v;
     for (v = 0; v < G->V; ++v)
     visit[v] = 0;
     
     for ( v = 0; v < G->V; ++v) 
      pre[v] = -1;
      
   for (v = 0; v < G->V; ++v)
      if (pre[v] == -1) 
         dfsR( G, v);
     
      // come�a nova etapa
}

static void dfsR( Graph G, vertex v) 
{ 
   pre[v] = cnt++; 
	visit[v] = 1;
   vertex w;
   for (w = 0; w < G->V; ++w)
      if (G->adj[v][w] != 0 && pre[w] == -1 && G->adj[v][w] == 1 && visit[w] == 0)
         dfsR( G, w); 
         
         
    
  
   
	
}
