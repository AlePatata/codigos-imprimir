/**
 * Roads Scholar (ICPC WF / Regional): Ciudades alcanzables usando una carretera específica en su camino óptimo.
 * Dados puntos de interés (ciudades) y consultas sobre un cartel puesto a distancia p en la arista (u -> v):
 * - Todos los pares con Dijkstra desde cada nodo: dist[x][y] guarda caminos mínimos entre intersecciones.
 * - Una ciudad 'pos' usa la arista directa (u, v) en algún camino óptimo desde u si y solo si:
 *   dist[u][pos] == costo[u][v] + dist[v][pos] (con margen EPS por ser doubles).
 * - Para cada ciudad válida, la distancia restante en el cartel es round(dist[u][pos] - p).
 * - Se ordenan por distancia restante ascendente y se imprime nombre y distancia.
 * Complejidad: O(n * m log n) para distancias + O(q * k log k) para responder y ordenar las ciudades.
 */
 
const double ERROR = 1e-6;

void solve(){
  int n,m,k; cin>>n>>m>>k;
  vector<vector<pdi>> gr(n);
  vector<vector<double>>costo(n,vector<double>(n,-1.0));
  for (int i=0;i<m;i++){
    int u,v; double w; cin>>u>>v>>w;
    gr[u].push_back({w,v});
    gr[v].push_back({w,u});
    costo[u][v] = w;
    costo[v][u] = w;
  }
  vector<vector<double>> dist(n,vector<double>(n));
  //vemos todos los caminos posibles
  for (int i=0;i<n;i++){
    vector<double> d1(n,-1);
    d1[i] = 0;
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
    pq.push({0, i});
    while(!pq.empty()){
      auto [w,u] = pq.top();pq.pop();
      if (w>d1[u]) continue;
      for (auto [vw, v]: gr[u]){
        if (d1[v]==-1 or 
            d1[v] > w+vw){
          d1[v] = w+vw;
          pq.push({d1[v],v});
        }
      }
    }
    dist[i] = d1;
  }
  vector<pii> ciudades(k);
  for (int i=0;i<k;i++){
    int nodo; string name;
    cin>>nodo>>name;
    ciudades[i] = {nodo,name};
  }
  int q; cin>>q;
  while(q--){
    int u,v; double p; cin>>u>>v>>p;
    vector<pair<int,string>> ans;
    for (auto [pos,name]: ciudades){
      //misma ciudad
      if (pos==u) continue;
      //verificar que la arista se use
      if (abs((dist[u][pos]-costo[u][v])-dist[v][pos]) < ERROR) {
        double otro = dist[u][pos]-p;
        ans.push_back({(int)round(otro),name});
      }
    }
    sort(ans.begin(),ans.end());
    for (auto [d,name]:ans){
      cout << name << ' ' << d << '\n';
    }
    cout << '\n';
  }
}