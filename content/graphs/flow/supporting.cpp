/**
 * Supporting Everyone: elegir si colores o pines.
 * Maximum Bipartite Matching estándar modelado con Flujo Máximo:
 * - Source (0) -> Colores (1..m) con capacidad 1 (cada color se usa a lo sumo una vez).
 * - Colores -> Países (m+1..m+n) con capacidad INF (o 1) si el país acepta ese color.
 * - Países -> Sink (t = n+m+1) con capacidad 1 (cada país recibe exactamente una bufanda).
 * - El flujo máximo representa la mayor cantidad de países que puedes apoyar simultáneamente.
 * Complejidad: O(Dinic sobre red bipartita unitaria) = O(E * sqrt(V)).
 */

// dinic
void solve() {
  int n,m; cin>>n>>m;
  // s: 0
  // colores: 1,m
  // paises: m+1, n+m
  // t: n+m+1
  int t = n+m+1;
  Dinic d(t+1);

  for (int c=1;c<=m;c++)
    d.addEdge(0,c,1);
  for (int i=1;i<n+1;i++){ // cantidad de países
    int x; cin>>x;
    for (int j=0;j<x;j++){
      int c; cin>>c;
      d.addEdge(c,m+i,INF);
    }
    d.addEdge(m+i,t,1);
  }
  cout << d.calc(0,t) << '\n';
}