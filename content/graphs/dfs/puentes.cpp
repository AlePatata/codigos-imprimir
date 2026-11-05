/*
 *Descripción:* Encuentra los puentes de un grafo no dirigido: aristas que al sacarlas aumentan la cantidad de componentes conexas.
 - `tin[u]` = momento en que el dfs entra a `u`. `low[u]` = menor `tin` alcanzable desde el subárbol de `u` usando a lo más una arista de retroceso
 - La arista del árbol `u - v` (`v` hijo) es puente $<==>$ `low[v] > tin[u]`: nada del subárbol de `v` vuelve a `u` o más arriba
 - Se guarda el id de cada arista y se ignora solo la arista por la que se llegó (no el padre), así funciona con aristas repetidas
 - Al leer la arista `i` entre `u` y `v`: `gr[u].push_back({v, i})` y `gr[v].push_back({u, i})`
 - Componentes 2-arista-conexas: sacar los puentes y ver las componentes que quedan; al comprimirlas se obtiene un árbol (bosque)
 *Complejidad:* $O(V + E)$
*/
vector<vector<pii>> gr; // {vecino, id de la arista}
vector<int> tin, low;
vector<pii> bridges; // {u, v}
int timer;

void dfs(int u, int pe = -1) { // pe = id de la arista con la que se llegó
  tin[u] = low[u] = timer++;
  for (auto [v, id] : gr[u]) {
    if (id == pe) continue;
    if (tin[v] != -1) low[u] = min(low[u], tin[v]); // arista de retroceso
    else {
      dfs(v, id);
      low[u] = min(low[u], low[v]);
      if (low[v] > tin[u]) bridges.push_back({u, v});
    }
  }
}

void find_bridges() {
  int n = sz(gr);
  timer = 0;
  tin.assign(n, -1);
  low.assign(n, -1);
  bridges.clear();
  for (int i = 0; i < n; i++)
    if (tin[i] == -1) dfs(i);
}
