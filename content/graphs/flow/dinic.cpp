/*
 *Descripción:* Flujo máximo de `s` a `t` en un grafo dirigido con capacidades (usa `ll`)
 - `Dinic d(n)`; `d.addEdge(a, b, c)` agrega la arista `a -> b` con capacidad `c`. Para una arista no dirigida: `d.addEdge(a, b, c, c)`
 - `d.calc(s, t)` retorna el flujo máximo. Después, `e.flow()` es el flujo que pasa por la arista `e` (recorriendo `d.g[u]`)
 - Idea: un BFS arma niveles por distancia desde `s`, y el DFS empuja flujo solo por aristas que avanzan un nivel; se repite hasta que `t` no es alcanzable
 - `ptr[v]` recuerda la primera arista de `v` que no está agotada, para no revisarla de nuevo en la misma fase
 - Escalamiento: en la fase `L` solo se usan aristas con capacidad residual $>= 2^(30-L)$
 - Corte mínimo: después de `calc`, `leftOfMinCut(u)` dice si `u` queda del lado de `s`. Las aristas que cruzan de ese lado al otro forman el corte, y su capacidad total es igual al flujo máximo
 - Matching bipartito: `s -> izquierda`, `izquierda -> derecha` y `derecha -> t`, todas con capacidad 1; el flujo máximo es el tamaño del matching
 *Complejidad:* $O(V E log U)$ con $U$ la capacidad máxima; $O(E sqrt(V))$ si todas las capacidades son 1 (matching)
*/
struct Dinic {
  struct Edge {
    int to, rev;
    ll c, oc;
    ll flow() {return max(oc-c, ll(0));}
  };
  vector<int> lvl, ptr, q; 
  vector<vector<Edge>> g;
  Dinic(int n): lvl(n), ptr(n), q(n), g(n) {}
  void addEdge(int a, int b, ll c, ll rcap=0) {
    g[a].push_back({b,sz(g[b]),c,c});
    g[b].push_back({a,sz(g[a])-1,rcap,rcap});
  }
  ll dfs(int v, int t, ll f){
    if (v==t || !f) return f;
    for (int &i=ptr[v]; i<sz(g[v]); i++){
      Edge& e = g[v][i];
      if (lvl[e.to] == lvl[v]+1)
        if (ll p = dfs(e.to, t, min(f,e.c))){
          e.c-=p, g[e.to][e.rev].c +=p;
          return p;
        }
    }
    return 0;
  }
  ll calc(int s, int t){
    ll flow = 0; q[0] = s;
    for(int L=0;L<31; ++L) do {
      lvl = ptr = vector<int>(sz(q));
      int qi = 0, qe = lvl[s] = 1;
      while(qi<qe && !lvl[t]){
        int v = q[qi++];
        for (Edge e:g[v])
          if (!lvl[e.to] && e.c>>(30-L))
            q[qe++] = e.to, lvl[e.to] = lvl[v]+1;
      }
      while(ll p=dfs(s,t,LLONG_MAX)) flow+=p;
    } while(lvl[t]);
    return flow;
  }
  bool leftOfMinCut(int a) { return lvl[a]!=0; }
};
