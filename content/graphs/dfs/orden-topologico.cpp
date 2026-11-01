/*
 *Descripción:* Ordena los nodos de un DAG (grafo dirigido acíclico) tal que toda arista `u -> v` deja a `u` antes que `v`.
 - Idea: en el dfs, un nodo *termina* (post-orden) solo después de que terminan todos los nodos alcanzables desde él
 - Entonces si `u -> v`, `v` termina antes que `u`. Agregando cada nodo a `order` al terminar, queda el orden al revés
 - Por eso al final se invierte `order`
 - Ej: `0 -> 1 -> 2` y `0 -> 2`: terminan `2, 1, 0`, invertido queda `0, 1, 2`
 - Si el grafo tiene ciclos el resultado no tiene sentido (detectarlos con colores: llegar a un nodo "en proceso" es un ciclo)
 *Complejidad:* $O(V + E)$
*/
int n;
vector<vector<int>> gr;
vector<bool> vis;
vector<int> order;

void dfs(int s) {
  vis[s] = true;
  for (int u : gr[s])
    if (!vis[u]) dfs(u);
  order.push_back(s); // post-orden: s termina después de todo lo que depende de él
}

vector<int> toposort() {
  vis.assign(n, false);
  order.clear();
  for (int i=0; i<n; i++)
    if (!vis[i]) dfs(i);
  reverse(order.begin(), order.end());
  return order;
}
