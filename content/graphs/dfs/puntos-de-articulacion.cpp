/*
 *Descripción:* Encuentra los puntos de articulación (vértices de corte) de un grafo no dirigido: nodos que al sacarlos aumentan la cantidad de componentes conexas.
 - `tin` y `low` igual que en puentes
 - Un nodo `u` que no es raíz es de articulación $<==>$ tiene un hijo `v` con `low[v] >= tin[u]`: el subárbol de `v` no sube más arriba de `u`
 - La raíz del dfs es de articulación $<==>$ tiene más de un hijo en el árbol del dfs
 - Diferencia con puentes: acá es `>=` (en puentes es `>`). Aristas repetidas no cambian los puntos de articulación, por eso basta ignorar al padre
 - `cut[u]` dice si `u` es de articulación (un nodo puede cumplir la condición con varios hijos, por eso se marca en vez de agregar a una lista)
 *Complejidad:* $O(V + E)$
*/
vector<vector<int>> gr;
vector<int> tin, low;
vector<bool> cut;
int timer;

void dfs(int u, int p = -1) {
  tin[u] = low[u] = timer++;
  int hijos = 0;
  for (int v : gr[u]) {
    if (v == p) continue;
    if (tin[v] != -1) low[u] = min(low[u], tin[v]); // arista de retroceso
    else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= tin[u] && p != -1) cut[u] = true;
      hijos++;
    }
  }
  if (p == -1 && hijos > 1) cut[u] = true;
}

void find_cutpoints() {
  int n = sz(gr);
  timer = 0;
  tin.assign(n, -1);
  low.assign(n, -1);
  cut.assign(n, false);
  for (int i = 0; i < n; i++)
    if (tin[i] == -1) dfs(i);
}
