/**
 * Roads not only in Berland (CF 25D): Reconfigurar n-1 aristas para transformar el grafo en un árbol.
 * Un grafo con n nodos y n-1 aristas es un árbol si y solo si es conexo (sin ciclos):
 * - Se procesan las aristas con dsu: si una arista une nodos ya conectados, forma un ciclo y sobra -> se guarda en 'romper'.
 * - Luego, se buscan los representantes de las componentes conexas disjuntas que quedaron.
 * - Por cada componente desconectada, se toma una arista sobrante de 'romper' y se reasigna para unirla (por ejemplo, conectando el nodo i con i+1 si están en conjuntos distintos).
 * - La cantidad de aristas a mover es exactamente (número de componentes - 1).
 * Complejidad: O(n * alpha(n)).
 */
 
struct union_find {
  vector<int> e;
  union_find(int n) {e.assign(n,-1);}
  int findSet(int x){
    return (e[x]<0 ? x : e[x] = findSet(e[x]));
  }
  bool sameSet(int x,int y) {return findSet(x)==findSet(y);}
  int size(int x) {return -e[findSet(x)];}
  bool unionSet(int x, int y){
    x = findSet(x), y=findSet(y);
    if (x==y) return 0;
    if (e[x]>e[y]) swap(x,y);
    e[x]+=e[y], e[y] = x;
    return 1;
  }
};

void solve(){
  int n; cin>>n;
  union_find dsu(n);
  vector<pii> romper, construir;
  for (int i=0;i<n-1;i++){
    int u,v; cin>>u>>v; u--;v--;
    if (dsu.sameSet(u,v)) {
      romper.push_back({u+1,v+1});
    } else {
      dsu.unionSet(u,v);
    }
  }
  if (dsu.size(0) == n) {
    cout << 0 << '\n';
    return;
  }
  for (int i=0;i+1<n;i++){
    if (!dsu.sameSet(i,i+1)) {
      construir.push_back({i+1,i+2});
      dsu.unionSet(i,i+1);
    }
  }
  cout << sz(construir) << '\n';
  for (int i=0;i<sz(construir);i++){
    cout << romper[i][0] << ' ' << romper[i][1] << ' ' << construir[i][0] << ' ' << construir[i][1] << '\n';
  }
}