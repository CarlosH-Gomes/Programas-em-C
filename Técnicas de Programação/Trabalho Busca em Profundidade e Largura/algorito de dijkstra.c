1 - Função de Floresta de Busca em largura

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

2 -  Função que encontra os caminhos mínimos de um vértice de origem a todos os outros vértices alcançáveis

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
         if (dist[w] == -1) && (G->adj[v][w]!=0) {//w é adjacente a v e ainda não foi visitado
                 pa[w] = v;
 dist[w] = dist[v] + 1;
            InserirFila( w); 
         }
   }
   LiberaFila( ); 
}

3 - Algoritmo de Dijkstra

Algoritmo: Seja G(V,A) um grafo orientado e s um vértice de G:
Atribua valor zero à estimativa do custo mínimo do vértice s (a raiz da busca) e infinito às demais estimativas;
Atribua um valor qualquer ao vetor pai;
Enquanto houver vértice aberto:
    seja k um vértice ainda aberto cuja estimativa seja a menor dentre todos os vértices abertos;
    feche o vértice k (torna esta estimativa a distância definitiva)
    Para todo vértice j ainda aberto que seja vizinho de k faça:     
     some a estimativa do vértice k com o custo do arco que une k a j;     
     caso esta soma seja melhor que a estimativa anterior para o vértice j, substitua-a e anote k como pai de      j

Código em C

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


