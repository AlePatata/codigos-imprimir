/**
 * Road to Savings (Kattis): Suma de pesos de las aristas que se pueden eliminar sin alterar la distancia mínima entre a y b.
 * Una arista (u, v) debe conservarse si y solo si forma parte de ALGÚN camino más corto entre a y b:
 * - Dijkstra desde a guardando todos los padres óptimos: si dist[v] == dist[u] + w, u es padre válido de v.
 * - BFS/DFS hacia atrás desde b siguiendo la lista de padres para marcar todas las aristas que pertenecen al DAG de caminos mínimos.
 * - Se suman los pesos de todas las aristas del grafo que NO quedaron marcadas en ningún camino óptimo (dividido entre 2 por ser no dirigido).
 * Complejidad: O(m log n) por Dijkstra + O(n + m) para reconstruir y sumar.
 */

vector<vector<pii>> gr;
vector<vector<int>> path;
vector<ll> dist;
int n,m, a, b;

//dijkstra que me devuelve un booleano
//con todas las aristas que forman
//un camino mínimo {a,b}
//uf no funciona t-t pke no los da
//especifico
vector<vector<bool>> dijkstra(){
  dist.assign(n,-1);
  vector<vector<int>> padres(n);
  priority_queue<pii,vector<pii>,greater<pii>> pq;
  pq.push({0,a});
  dist[a] = 0;
  while(!pq.empty()){
    auto [nodo_d,nodo] = pq.top(); pq.pop();
    if (nodo_d>dist[nodo]) continue;
    for (auto [vw,v]:gr[nodo]){
      if (dist[v]==-1 || (vw+nodo_d)<dist[v]) {
        dist[v] = vw+nodo_d;
        padres[v] = {nodo};
        pq.push({vw+nodo_d,v});
      } else if ((vw+nodo_d)==dist[v]){
        padres[v].push_back(nodo);
      }
    }
  }
  //reconstruir
  vector<vector<bool>> edges(n,vector<bool>(n));
  vector<bool> vis(n,false);
  queue<int> bfs;
  bfs.push(b); vis[b] = true;
  while(!bfs.empty()){
    int nodo = bfs.front(); bfs.pop();
    for (int vecino:padres[nodo]){
      edges[nodo][vecino] = true;
      edges[vecino][nodo] = true;
      if(!vis[vecino]){
        vis[vecino]=true;
        bfs.push(vecino);
      }
    }
  }
  return edges;
}

void solve(){
  cin>>n>>m>>a>>b; a--; b--;
  gr.resize(n);
  for (int i=0;i<m;i++){
    int u,v,w; cin>>u>>v>>w;u--;v--;
    gr[u].push_back({w,v});
    gr[v].push_back({w,u});
  }
  vector<vector<bool>> edges = dijkstra();
  int ans = 0;
  for (int i=0;i<n;i++){
    for (auto [w,x]:gr[i]){
      if(!edges[i][x]){
        ans+=w;
      }
    }
  }
  //reviso las aristas dos veces pke
  //no es dag XD
  cout << ans/2 << '\n';
}