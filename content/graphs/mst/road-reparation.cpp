/**
 * CSES Road Reparation: Minimum Spanning Tree (MST) clásico con Kruskal y DSU.
 * Conectar todas las ciudades reparando caminos con el mínimo costo total posible:
 * - Se ordenan todas las aristas por peso de menor a mayor.
 * - Kruskal selecciona aristas greedy usando DSU si unen componentes desconectadas.
 * - Se valida conexidad al final (que el MST resultante visite todos los nodos con BFS/DSU); 
 *   si queda algún nodo aislado imprime "IMPOSSIBLE", si no, imprime la suma de los pesos del MST.
 * Complejidad: O(m log m) por el sort de aristas.
 */
 
//insertar uf
vector<vector<ii>> kruskal(vector<vector<ii>> &gr){
  int n = sz(gr);
  vector<vector<ii>> ans(n);
  vector<iii> edges;
  for (int i=0;i<n;i++){
    for (int j=0;j<sz(gr[i]); j++){
      edges.emplace_back(gr[i][j].second,ii{i,gr[i][j].first});
    }
  }
  sort(edges.begin(),edges.end());
  union_find uf(n);
  for (int i=0;i<sz(edges);i++){
    ll repa = uf.findSet(edges[i].second.first), repb = uf.findSet(edges[i].second.second);
    if (repa!=repb){
      ans[edges[i].second.first].emplace_back(edges[i].second.second, edges[i].first);
      ans[edges[i].second.second].emplace_back(edges[i].second.first, edges[i].first);
      uf.unionSet(repa,repb);
    }
  }
  return ans;
}

void solve(){
  int n,m; cin>>n>>m;
  vector<vector<ii>> gr(n);
  for (int i=0;i<m;i++){
    int u,v,w; cin>>u>>v>>w; u--;v--;
    gr[u].push_back({v,w});
    gr[v].push_back({u,w});
  }
  vector<vector<ii>> mst = kruskal(gr);
  ll ans = 0;
  vector<bool> vis(n,false);
  queue<ii> bfs;
  bfs.push({0,0});
  vis[0] = true;
  while(!bfs.empty()){
    auto [u,w] = bfs.front(); bfs.pop();
    ans+=w;
    for (auto [v,vw]: mst[u]){
      if (!vis[v]){
        bfs.push({v,vw});
        vis[v] = true;
      }
    }
  }
  for (auto x:vis) {
    if (!x) {
      cout << "IMPOSSIBLE\n";
      return;
    }
  }
  cout << ans << '\n';
}