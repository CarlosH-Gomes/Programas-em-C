1 - Fun��o de Floresta de Busca em largura

void Busca_Largura( Grafo G, int s) 
{ 
   int cnt = 0;
   for (int v = 0; v < G->V; ++v)
      num[v] = -1;
   CriaFila( );//cria uma fila vazia
   num[s] = cnt++; 
   InsereFila( s); 
   while (!FilaVazia( )) {
      int v = RemoveFila( ); 
      for (w = 0; w< G->V; w++)
         if (num[w] == -1) && (G->adj[v][w]!=0) {
            num[w] = cnt++; 
    Pai[w] = v;
    InsereFila(w); 
         }
   }
   EliminaFila( ); 
}

2 -  Fun��o que encontra os caminhos m�nimos de um v�rtice de origem a todos os outros v�rtices alcan��veis

void CaminhoMin( Graph G, int s, 
                    int *dist, int *pai) 
{ 
   const int INFINITO = G->V;
   for (int v = 0; v < G->V; ++v) 
      pai[v] = -1, dist[v] = INFINITO;
   CriaFila( G->V);
   dist[s] = 0;
   pai[s] = s;
   InserirFila( s); 

   while (!FilaVazia( )) {
      int v = RemoveFila( ); 
      for (w = 0; w< G->V; w++)
         if (dist[w] == -1) && (G->adj[v][w]!=0) {//w � adjacente a v e ainda n�o foi visitado
                 pa[w] = v;
 dist[w] = dist[v] + 1;
            InserirFila( w); 
         }
   }
   LiberaFila( ); 
}

3 - Algoritmo de Dijkstra

Algoritmo: Seja G(V,A) um grafo orientado e s um v�rtice de G:
Atribua valor zero � estimativa do custo m�nimo do v�rtice s (a raiz da busca) e infinito �s demais estimativas;
Atribua um valor qualquer ao vetor pai;
Enquanto houver v�rtice aberto:
    seja k um v�rtice ainda aberto cuja estimativa seja a menor dentre todos os v�rtices abertos;
    feche o v�rtice k (torna esta estimativa a dist�ncia definitiva)
    Para todo v�rtice j ainda aberto que seja vizinho de k fa�a:     
     some a estimativa do v�rtice k com o custo do arco que une k a j;     
     caso esta soma seja melhor que a estimativa anterior para o v�rtice j, substitua-a e anote k como pai de      j

C�digo em C

#define INFINITO custoMax
void dijkstra(Digraph G, int s, int pai[ ], double cst[ ])
{ 
	int v, w;
	for (v = 0; v < G->V; v++) {
		cst[v] = INFINITO; 
		pai[v] = -1;
     	}
	CriarFilaP(G->V);
	cst[s] = 0;
	pai[s] = s;
	InserirFilaPt(s);
	while (!FilaPrioridadeVazia()) {
		v = RemoveFilaP();
		for(w=0 ;w<G->V;w++)
	{
	if (cst[w]==INFINITO)
 	{
	  cst[w]=cst[v]+p->cst;
	  pai[w]=v;
	  InserirFilaP(w); 
	}
	Else
	{
		if(cst[w]>cst[v]+adj[v][w])
		{
			cst[w]=cst[v]+adj[v][w];
			pai[w] = v;
			InserirFilaP(w);

		} 
		LiberaFilaP();
   	}
}
}


