/*
 *Descripción:* Recorre un grafo no ponderado desde un nodo inicial, calculando la distancia mínima a cada nodo.
 *Complejidad:* $O(V + E)$
*/
vis[s] = true;
dist[s] = 0;
q.push(s);
while (!q.empty()) {
  int u = q.front(); q.pop();
  // procesar nodo u
  for (auto v : gr[u]) {
    if (vis[v]) continue;
    vis[v] = true;
    dist[v] = dist[u]+1;
    q.push(v);
  }
}
