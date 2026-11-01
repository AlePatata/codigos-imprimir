/*
 *Descripción:* Computa las distancias mínimas desde un nodo inicial a todos los demás en un grafo ponderado, con pesos no negativos, usando el algoritmo de Dijkstra.
 - `gr[u]` contiene pares `{v, w}`: arista `u -> v` con peso `w`
 *Complejidad:* $O(V log V + E)$
*/
vector<ll> dist(n, LLONG_MAX);
dist[s] = 0;
// esto o insertar pesos negativos
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
q.push({0, s});
while (!q.empty()) {
  auto [d, u] = q.top(); q.pop();
  if (vis[u]) continue;
  vis[u] = true;
  for (auto [v, w] : gr[u]) {
    if (dist[v] > dist[u] + w) {
      dist[v] = dist[u] + w;
      q.push({dist[v], v});
    }
  }
}
