/**
 * There and Back Again: Ida y vuelta entre 1 y n usando dos caminos que difieran en al menos una arista.
 * Se busca el camino más corto de ida y el segundo camino más corto (o que no comparta todas las aristas):
 * - Hallas el camino más corto de 1 a n con Dijkstra y guardas sus aristas (árbol de padres p1/p2).
 * - Calculas distancias desde el origen d1n (Dijkstra desde 0) y hacia el destino dn1 (Dijkstra desde n-1).
 * - Para cada arista (u, v, w) que NO pertenezca al camino óptimo original, evalúas el costo de usarla como desvío:
 *   costo = min(d1n[u] + w + dn1[v], d1n[v] + w + dn1[u]).
 * - La respuesta total es el camino óptimo de ida + el mejor desvío encontrado de vuelta.
 * Complejidad: O(m log n) por los dos Dijkstra y recorrido lineal de aristas.
 */
 
const ll INF = 1e17;
vector<vector<pii>> gr;
vector<int> p1;
int n,m;

vector<ll> dijkstra(int inicio) {
  vector<ll> dist(n,-1);
  priority_queue<pii,vector<pii>,greater<pii>> pq;
  pq.push({0,inicio});
  dist[inicio] = 0;
  while(!pq.empty()){
    auto [nodo_d,nodo] = pq.top();
    pq.pop();
    if (nodo_d>dist[nodo]) continue;
    for (auto [vecino_d,vecino]: gr[nodo]){
      if (dist[vecino]==-1 ||
          dist[vecino]>nodo_d+vecino_d){
        dist[vecino] = nodo_d+vecino_d;
        p1[vecino] = nodo;
        pq.push({dist[vecino],vecino});
      }
    }
  }
  return dist;
}

void solve(){
  cin>>n>>m;
  gr.resize(n);
  p1.resize(n,-1);
  vector<p3i> aristas(m);
  for (int i=0;i<m;i++){
    int u,v,w; cin>>u>>v>>w; u--;v--;
    gr[u].push_back({w,v});
    gr[v].push_back({w,u});
    aristas[i] = {u,v,w};
  }
  vector<ll> dn1 = dijkstra(n-1);
  p1.assign(n,-1);
  vector<ll> d1n = dijkstra(0);
  vector<int> p2(n,-1);
  int k = n-1;
  while(p1[k]!=-1 and k!=0){
    p2[k] = p1[k];
    k = p1[k];
  }
  ll ans = INF;
  for (auto [u,v,w]: aristas){
    if (p2[u]!=v and p2[v]!=u) {
      if (d1n[u]!=-1 and d1n[v]!=-1) {
        ans = min(ans,min(d1n[u]+(ll)w+dn1[v],d1n[v]+(ll)w+dn1[u]));
      }
    }
  }
  if (ans==INF or d1n[n-1]==-1) cout << -1 << '\n';
  else cout << ans + d1n[n-1] << '\n';
}