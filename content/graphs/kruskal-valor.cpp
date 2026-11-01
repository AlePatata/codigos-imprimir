/*
 *Descripción:* Valor del MST en $O(E log E)$
 - `gr[u]` contiene pares `{v, w}`: arista `u - v` con peso `w`
 *Requiere:* `union_find`
*/
ll kruskal_value(vector<vector<pii>> &gr) {
  int n = sz(gr);
  vector<array<int, 3>> edges; // {w, u, v}
  for (int u = 0; u < n; u++)
    for (auto [v, w] : gr[u])
      edges.push_back({w, u, v});
  sort(edges.begin(), edges.end());
  union_find uf(n);
  ll cost = 0;
  for (auto [w, u, v] : edges)
    if (uf.unionSet(u, v)) cost += w; // la arista u - v queda en el MST
  return cost;
}
