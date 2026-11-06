/**
 * Waif Until Dark (Kattis / ICPC): Asignar juguetes a niños respetando topes por categoría.
 * Reducción a Flujo Máximo / Bipartite Matching con cuotas de categorías:
 * - Nodos: Source (0) -> Niños (1..n) -> Juguetes (n+1..n+m) -> Categorías -> Sink.
 * - Source a cada niño con cap 1 (cada niño juega con a lo sumo un juguete).
 * - Niño a sus juguetes preferidos con cap 1.
 * - Juguete a su categoría con cap 1 (o directo al Sink con cap 1 si no pertenece a ninguna).
 * - Cada categoría al Sink con capacidad r_i (límite máximo de juguetes utilizables de esa categoría).
 * Complejidad: O(Dinic sobre red unitaria) ≈ O(V * E).
 */

// insertar dinic
void solve() {
  int n,m,p; cin>>n>>m>>p;
  Dinic d(n+m+p+2);
  for (int i=1;i<=n;i++){
    d.addEdge(0,i,1);
    int k; cin>>k;
    while(k--){
      int x; cin>>x;
      d.addEdge(i,n+x,1);
    }
  }
  vector<int> juguetes(m+1,0);
  for (int i=1;i<=p;i++){
    int c; cin>>c;
    while(c--){
      int x;cin>>x;
      juguetes[x] = i+n+m;
    }
    int r; cin>>r;
    d.addEdge(i+n+m,n+m+p+1,r);
  }
  for (int i=1;i<m+1;i++){
    if (juguetes[i]){
      d.addEdge(i+n,juguetes[i],1);
    } else {
      d.addEdge(i+n,n+m+p+1,1);
    }
  }
  cout << d.calc(0,n+m+p+1) << '\n';
}