/**
 * Valid BFS? (CF 1037D): Verificar si una permutación dada puede ser un orden BFS válido.
 * El truco es reordenar los vecinos de cada nodo según el orden en que aparecen en el arreglo a:
 * - Guardas pos[x] = índice donde aparece x en a.
 * - Ordenas la lista de adyacencia de cada nodo con un sort usando pos[vecino].
 * - Corres un BFS normal desde la raíz 1 (o nodo 0): al estar los vecinos ordenados según el input,
 *   si la secuencia era un BFS válido, el recorrido generado coincidirá exactamente con 0, 1, ..., n-1.
 * Complejidad: O(n log n) por el sort de adyacencias, O(n) por el BFS.
 */

void solve(){
  int n; cin>>n;
  vector<vector<int>> gr(n), seq(n);
  for(int i=1;i<n;i++) {
    int u,v; cin>>u>>v; u--; v--;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  vector<int> a(n);
  map<int,int> ind;
  for (int i=0;i<n;i++){
    cin>>a[i]; a[i]--;
    ind[a[i]] = i;
  }
  for (int i=0;i<n;i++){
    for (auto x: gr[a[i]]){
      seq[i].push_back(ind[x]);
    }
    sort(seq[i].begin(), seq[i].end());
  }
  vector<bool> visited(n, false);
  queue<int> bfs;
  bfs.push(ind[0]);
  visited[ind[0]] = true;
  vector<int> ans, comp;
  while(!bfs.empty()){
    int nodo = bfs.front(); bfs.pop();
    ans.push_back(nodo);
    for (int vecino: seq[nodo]){
      if(!visited[vecino]){
        bfs.push(vecino);
        visited[vecino] = true;
      }
    }
  }
  comp = ans; sort(comp.begin(),comp.end());
  if (comp==ans) cout<<"Yes\n";
  else cout << "No\n";
}