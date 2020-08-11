#include<stdio.h>
#include<stdlib.h>
#define vertex int

int visit[1000];

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
int GRAF_CAMINHO( Graph G, int s, int t);
int Caminho_P( Graph G, int v, int esc);

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
    {
        printf(" 1 - Inserir um par que sera ligado \n 2 - Ate onde quer chegar \n 3 - Imprimir matriz de Adj\n 4 - Finalizar\n");
        scanf ("%d", &op);
        switch (op){
		
	        case 1:
	            printf ("Digite o par de vertices que quer ligar\n");
	            scanf("%d",&i);
	            scanf("%d",&j);
				if(i!=j)
				{       
	            	GRAPHinsertArc(G,  i,  j);
	        	}
	        	else
	        		printf("Nao pode ligar um vertice a ele mesmo \n");
	        break;
	           
	        
	        case 2:
	        	
	        	printf("Digite de onde quer sair\n");
	            scanf("%d",&sai);
	            printf("Digite onde quer chegar \n");
	            scanf("%d",&esc);
	            if( (GRAF_CAMINHO(  G,  sai, esc)) == 1)
	            {
	                printf("sim, esta ao alcance\n");
	                system("pause");
					system("cls");
				}
	            else
	            {
					printf("nao esta ao alcance\n");
	                system("pause");
					system("cls");
				}
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
    
 
	for(i=0;i<V;i++)
    {
    	printf(" %d ",visit[i]);
	}
		

 	
    
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
   if (G->adj[v][w] == 0) 
   {
      G->adj[v][w] = 1; 
      G->A++;
   }
}

///////
int GRAF_CAMINHO( Graph G, int s, int t )
{
    int v;
     for (v = 0; v < G->V; ++v)
     visit[v] = 0;
     
     Caminho_P( G, s, t);
     if (visit[t] == 0) 
	 	return 0;
    else   
 		return 1;
}

int Caminho_P( Graph G, int v, int esc)
{
    int w;
    
    visit[v] = 1;
    for ( w = 0; w < G->V; ++w)
	{
      if (G->adj[v][w] == 1 && visit[w] == 0 && visit[esc] != 1 )
        { 
		 Caminho_P( G, w, esc);
		}
	}
			
}
