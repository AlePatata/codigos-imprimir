/**
 * Lost in Translation (Kattis / ICPC): Traducir a todos los idiomas minimizando pasos y costo.
 * Prioridad 1: mínima cantidad de traducciones intermedias (distancia no ponderada desde "English").
 * Prioridad 2: costo monetario mínimo de los traductores elegidos:
 * - BFS desde English (0) calcula la distancia mínima en pasos d[u] para cada idioma.
 * - Subgrafo DAG / bfs: solo consideramos aristas u -> v donde d[v] == d[u] + 1.
 * - Cada idioma v (con d[v] > 0) debe conectarse a algún predecesor u; para minimizar costo,
 *   se elige la arista entrante de menor peso w entre todos sus posibles padres en el nivel anterior.
 * - Si algún idioma queda inalcanzable (dist == -1) -> "Impossible"; si no, se suma el costo mínimo por nodo.
 * Complejidad: O(n + m log n) o O(n + m) con BFS y selección greedy de arista mínima por nodo.
 */

map<string,int> pal;

void solve(){
  int n,m; cin>>n>>m;
  // maping palabras; english = 0
  pal["English"] = 0;
  for (int i=1;i<=n;i++) {
    string x; cin>>x;
    pal[x] = i;
  }
  vector<vector<pii>> gr(n+1);
  // construir conexiones
  for (int i=0;i<m;i++){
    string a,b; ll w;
    cin>>a>>b>>w;
    gr[pal[a]].push_back({w,pal[b]});
    gr[pal[b]].push_back({w,pal[a]});
  }
  //new idea: hacer un nuevo grafo de distancias
  //y aplicar dijkstra sobre este :3
  //1. unir todos los nodos en un nuevo grafo a
  //distancia menor o igual a la que está
  //lo podemos hacer con un bfs
  //2. aplicar dijkstra sobre este
  vector<vector<pii>> ngr(n+1);
  queue<pii> bfs; bfs.push({0,0});
  vector<int> dist_min(n+1,-1); dist_min[0] = 0;
  while(!bfs.empty()){
    auto [nodo_d, nodo] = bfs.front(); bfs.pop();
    for (auto [vecino_d, vecino]:gr[nodo]){
      if (dist_min[vecino]==-1){
        dist_min[vecino] = dist_min[nodo]+1;
        ngr[nodo].push_back({vecino_d,vecino});
        bfs.push({vecino_d,vecino});
      } else if (dist_min[vecino]==dist_min[nodo]+1){
        ngr[nodo].push_back({vecino_d,vecino});
      }
    }
  }

  // dijkstra
  vector<ll> dist(n+1,-1);
  priority_queue<pii,vector<pii>,greater<pii>> pq;
  pq.push({0,0});
  dist[0] = 0;
  while(!pq.empty()){
    auto [nodo_d,nodo] = pq.top(); pq.pop();
    if (nodo_d > dist[nodo]) continue;
    for (auto [vecino_d, vecino]: ngr[nodo]){
      if(dist[vecino]==-1 || dist[vecino]>vecino_d){
        dist[vecino] = vecino_d;
        pq.push({dist[vecino], vecino});
      }
    }
  }
  ll ans = 0;
  for (auto x:dist) {
    if (x==-1) {
      cout << "Impossible\n";
      return;
    }
    ans+=x;
  }
  cout << ans << '\n';
}