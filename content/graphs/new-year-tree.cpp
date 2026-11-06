/*
 New Year Tree (CF 620E): Cantidad de colores distintos en el subárbol de un nodo.
 Aplana el árbol a un arreglo con DFS (Euler Tour / tin y tout):
 - El subárbol de v se convierte en el rango continuo [tin[v], tout[v]].
 - Como hay <= 60 colores, cada color c se representa como bitmask: (1LL << c).
 - ST Lazy con asignación en rango (pintar subárbol) y merge = OR bit a bit (a | b).
 - La query cuenta colores distintos en el subárbol con __builtin_popcountll(query).
 Complejidad: O(n) tour, O((n + q) log n) por updates y queries.
*/

vector<vector<ll>> gr;
vector<bool> vis;
// [entra, sale, color]
vector<pii> plano;
vector<int> col;
int alo = 0;
vector<ll> colores_final;

// template de st lazy
// aplanar un grafo
void dfs(int nodo){
  vis[nodo] = true;
  plano[nodo][0] = alo;
  colores_final[alo] = (1LL)<<col[nodo];
  alo++;
  for (int vecino:gr[nodo]){
    if (!vis[vecino]) {
      vis[vecino] = true;
      dfs(vecino);
    }
  }
  plano[nodo][1] = alo - 1;
}

// no importa inicio, fin, solo el or para col dif
ll merge(ll a,ll b) {
  return a|b;
}

// a es padre, b es child
void pushUpd(ll& a, ll& b, int pl, int pr, int cl, int cr){
  b = a;
}

void applyUpd(ll& a, ll& b, int l, int r) {
  b = a;
}

void solve() {
  int n,q; cin>>n>>q;
  col.resize(n);
  for (auto &x:col) cin>>x;
  gr.resize(n);
  vis.assign(n,false);
  plano.resize(n);
  colores_final.resize(n);
  for (int i=1;i<n;i++){
    int u,v; cin>>u>>v; u--; v--;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  dfs(0);
  segment_tree_lazy<ll,ll,merge,pushUpd,applyUpd> st(colores_final);
  while(q--) {
    int t,v; cin>>t>>v; v--;
    if (t==1) {
      int c; cin>>c;
      ll aaa = (1LL << c);
      st.update(plano[v][0], plano[v][1], aaa);
    } else {
      cout << __builtin_popcountll(st.query(plano[v][0], plano[v][1])) << '\n';
    }
  }
}