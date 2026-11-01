/*
 *Descripción:* Retorna la construcción de un MST
 - `gr[u]` contiene pares `{v, w}`: arista `u - v` con peso `w`
 *Requiere:* `union_find`
*/
vector<vector<pii>> kruskal(vector<vector<pii>> &gr) {
  int n = sz(gr);
  vector<vector<pii>> ans(n);
  vector<array<int, 3>> edges; // {w, u, v}
  for (int u = 0; u < n; u++)
    for (auto [v, w] : gr[u])
      edges.push_back({w, u, v});
  sort(edges.begin(), edges.end());
  union_find uf(n);
  for (auto [w, u, v] : edges) {
    if (uf.unionSet(u, v)) {
      ans[u].push_back({v, w});
      ans[v].push_back({u, w});
    }
  }
  return ans;
}
