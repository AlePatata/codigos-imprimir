/*
 *Descripción:* Encuentra las componentes fuertemente conexas (SCC) de un grafo dirigido: conjuntos maximales donde todo nodo llega a todo otro.
 - `gr` es el grafo y `grt` el transpuesto: al leer `u -> v` hacer `gr[u].push_back(v)` y `grt[v].push_back(u)`
 - Paso 1: `dfs1` en `gr` guarda los nodos en post-orden en `order` (como en el orden topológico)
 - Paso 2: recorrer `order` desde atrás como un stack (el último en terminar primero) y hacer `dfs2` en `grt`; cada `dfs2` marca exactamente una SCC
 - Idea: el nodo que termina último está en una SCC "fuente"; en `grt` esa SCC no tiene salida hacia otras no visitadas
 - `scc[u]` es la SCC de `u`, numeradas en orden topológico: si hay arista `u -> v` con `scc[u] != scc[v]` entonces `scc[u] < scc[v]`
 - Grafo condensado (DAG de SCC): por cada arista `u -> v` con `scc[u] != scc[v]` agregar `scc[u] -> scc[v]`
 - Mínimo de aristas a agregar para que todo sea 1 SCC: 0 si `k == 1`, si no `max(fuentes, sumideros)` del grafo condensado (SCC sin aristas de entrada / de salida desde otra SCC)
 *Complejidad:* $O(V + E)$
*/
vector<vector<int>> gr, grt;
vector<bool> vis;
vector<int> order, scc;

void dfs1(int s) {
  vis[s] = true;
  for (int u : gr[s])
    if (!vis[u]) dfs1(u);
  order.push_back(s);
}

void dfs2(int s, int k) {
  scc[s] = k;
  for (int u : grt[s])
    if (scc[u] == -1) dfs2(u, k);
}

int kosaraju() { // retorna la cantidad de SCC
  int n = sz(gr), k = 0;
  vis.assign(n, false);
  scc.assign(n, -1);
  order.clear();
  for (int i = 0; i < n; i++)
    if (!vis[i]) dfs1(i);
  for (int i = n - 1; i >= 0; i--)
    if (scc[order[i]] == -1) dfs2(order[i], k++);
  return k;
}
