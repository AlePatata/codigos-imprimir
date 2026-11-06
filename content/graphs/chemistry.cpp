/**
 * DZY Loves Chemistry (CF 445B): Máximo peligro al mezclar reactivos (duplica por cada reacción).
 * En cada componente conexa de tamaño k, siempre puedes ordenar las sustancias para que la 1ra
 * entre sola y las siguientes k-1 reaccionen con alguna ya presente, duplicando el peligro k-1 veces:
 * - Se hallan las componentes conexas con DSU (o DFS/BFS).
 * - Cada componente de tamaño sz aporta un factor de 2^(sz - 1).
 * - La respuesta total es el producto de todas las componentes: 2^(n - cant_componentes).
 * Complejidad: O((n + m) * alpha(n)).
 */

struct union_find {
  vector<int> e;
  union_find(int n) { e.assign(n, -1); }
  int findSet (int x) {
    return (e[x] < 0 ? x : e[x] = findSet(e[x]));
  }
  bool sameSet (int x, int y) { return findSet(x) == findSet(y); }
  ll size (int x) { return -e[findSet(x)]; }
  bool unionSet (int x, int y) {
    x = findSet(x), y = findSet(y);
    if (x == y) return 0;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y], e[y] = x;
    return 1;
  }
};

void solve(){
  int n,m; cin>>n>>m;
  union_find gr(n);
  for (int i=0;i<m;i++){
    int u,v; cin>>u>>v; u--;v--;
    gr.unionSet(u,v);
  }
  vector<ll> tam;
  for (int i=0;i<n;i++){
    if (gr.findSet(i)==i) tam.push_back(gr.size(i)-1);
  }
  ll ans = 1;
  for (auto x:tam){
    while(x--){
      ans*=2;
    }
  }
  cout << ans << '\n';
}