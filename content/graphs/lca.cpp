/*
 *Descripción:* Calcula el ancestro común más bajo (LCA), precálculo $O(V log V)$, $O(log V)$ por consulta, usa binary lifting y funciona para grafos dirigidos y no dirigidos.
*/
struct LCA {
  int LOGN;
  vector<vector<int>> gr, parent;
  vector<int> depth, vis;
  // Si da WA, ¿logn más grande?
  LCA(vector<vector<int>> &gr, int logn = 20): LOGN(logn), gr(gr), vis(sz(gr)) {
    parent.assign(sz(gr)+1, vector<int>(LOGN, 0));
    depth.assign(sz(gr)+1, 0);
    // Si es un bosque
    //for (int u = 0; u < sz(gr); u++)
    //  if (!vis[u]) dfs(u);
  }
  void dfs(int u = 0, int p = -1) {
    vis[u] = true;
    for (int v : gr[u]) {
      if (p != v) {
        depth[v] = depth[u] + 1;
        parent[v][0] = u;
        for (int j = 1; j < LOGN; j++)
          parent[v][j] = parent[parent[v][j-1]][j-1];
        dfs(v, u);
      }
    }
  }
  int query(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int k = depth[u]-depth[v];
    for (int j = LOGN - 1; j >= 0; j--)
      if (k & (1 << j))
        u = parent[u][j];
    if (u == v)
      return u;
    for (int j = LOGN - 1; j >= 0; j--) {
      if (parent[u][j] != parent[v][j]) {
        u = parent[u][j];
        v = parent[v][j];
      }
    }
    return parent[u][0];
  }
};
