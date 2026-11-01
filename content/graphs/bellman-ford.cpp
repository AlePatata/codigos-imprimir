/*
 *Descripción:* Calcula los caminos más cortos desde $s$ en un grafo que puede tener aristas con peso negativo. `getCycle` encuentra un ciclo negativo si existe. $O(V E)$
*/
struct BellmanFord {
  struct Edge { int u, v; ll w; };
  int n, last_updated = -1;
  vector<int> p; vector<ll> dist;
  BellmanFord(int n, vector<Edge> &edges, int s) : n(n) {
    dist.assign(n, LLONG_MAX); p.assign(n, -1); dist[s] = 0;
    for (int i = 1; i <= n; i++) {
      last_updated = -1;
      for (Edge &e : edges)
        if (dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v]) {
          dist[e.v] = dist[e.u] + e.w;
          p[e.v] = e.u; last_updated = e.v;
        }
    }
  }
  bool getCycle(vector<int> &cycle) {
    if (last_updated == -1) return false;
    for (int i = 0; i < n-1; i++)
      last_updated = p[last_updated];
    for (int x = last_updated ;; x=p[x]) {
      cycle.push_back(x);
      if (x == last_updated and sz(cycle) > 1) break;
    }
    reverse(cycle.begin(), cycle.end());
    return true;
  }
};
