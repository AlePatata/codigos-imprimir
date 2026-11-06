/**
 * Graph Composition (CF 1594D / 1528C-style DSU): Mínimas operaciones para que F tenga las mismas componentes conexas que G.
 * Operaciones válidas: borrar aristas de F o agregar aristas a F:
 * - Construyes primero el DSU de G (el grafo objetivo) para saber qué componentes deben existir.
 * - En f: si una arista (u, v) une nodos que en G están en componentes distintas, es ilegal y DEBE borrarse (ans++).
 * - Las aristas de F que sí son válidas se unen en un segundo DSU (gf), reduciendo la cantidad de componentes actuales en F.
 * - Al final, para que F tenga tantas componentes como G (cng), agregas aristas faltantes: (comp_F - comp_G).
 * Complejidad: O((n + m1 + m2) * alpha(n)).
 */
 
struct union_find{
  vector<int> e;
  union_find(int n) { e.assign(n,-1); }
  int findSet(int x) {
    return (e[x]<0 ? x : e[x] = findSet(e[x]));
  }
  bool sameSet(int x, int y) {return findSet(x) == findSet(y); }
  int size(int x) {return -e[findSet(x)];}
  bool unionSet(int x, int y) {
    x = findSet(x), y=findSet(y);
    if (x==y) return 0;
    if (e[x]>e[y]) swap(x,y);
    e[x]+=e[y],e[y]=x;
    return 1;
  }
};

void solve(){
  int n,m1,m2; cin>>n>>m1>>m2;
  vector<pii> gr(m1);
  for (int i=0;i<m1;i++) {
    int u,v; cin>>u>>v; u--; v--;
    gr[i] = {u,v};
  } 
  union_find gg(n);
  int cng = n;
  for (int i=0;i<m2;i++){
    int u,v; cin>>u>>v; u--; v--;
    //veo cant de comp en g
    if (gg.unionSet(u,v)) cng--;
  }
  union_find gf(n);
  int ans = 0;
  for (auto [u,v]: gr){
    //tengo que borrar una arista en f
    //pke conecta dos comp no conexas en g
    if (!gg.sameSet(u,v)) ans++;
    else 
      //conecto bien :D -> tengo menos
      //comp en f
      if (gf.unionSet(u,v)) n--;
  }
  //cant que borrar + cant añadir :3
  cout << ans + (n - cng) << '\n';
}