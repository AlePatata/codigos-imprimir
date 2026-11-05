/*
 *Descripción:* Propiedades típicas del grafo condensado (DAG de SCC). Cada bloque es independiente, copiar solo el que se necesite
 - `k = kosaraju()`. Las SCC están en orden topológico: las aristas entre SCC van de menor a mayor
 - Por eso la SCC `0` siempre es fuente y la SCC `k-1` siempre es sumidero
 *Requiere:* `kosaraju`
*/

// Tamaño de cada SCC
vector<int> tam(k);
for (int u = 0; u < sz(gr); u++) tam[scc[u]]++;

// Tiene ciclo <=> k < n, o hay algún self-loop u -> u

// Grafo condensado: cond[c] = SCC a las que llega c (puede tener aristas repetidas)
vector<vector<int>> cond(k);
for (int u = 0; u < sz(gr); u++)
  for (int v : gr[u])
    if (scc[u] != scc[v]) cond[scc[u]].push_back(scc[v]);

// Fuentes y sumideros: fuente = SCC sin aristas que le lleguen desde otra SCC (!entra[c])
// sumidero = SCC sin aristas que salgan hacia otra SCC (!sale[c])
vector<bool> entra(k), sale(k);
for (int u = 0; u < sz(gr); u++)
  for (int v : gr[u])
    if (scc[u] != scc[v]) sale[scc[u]] = entra[scc[v]] = true;
int fuentes = 0, sumideros = 0;
for (int c = 0; c < k; c++) fuentes += !entra[c], sumideros += !sale[c];

// Mínimo de aristas a agregar para que todo sea 1 SCC (requiere fuentes y sumideros)
int faltan = k == 1 ? 0 : max(fuentes, sumideros);

// Nodo desde el que se llega a todos: existe <=> fuentes == 1, y sirve cualquier nodo con scc[u] == 0
// Nodo al que llegan todos: existe <=> sumideros == 1, y sirve cualquier nodo con scc[u] == k-1

// Par (a, b) tal que de a NO se llega a b (si k > 1): a en la SCC k-1, b en la SCC 0

// DP en el DAG: máxima suma de val[u] en un camino, pudiendo pasar por cada nodo de una SCC (ej: Coin Collector)
// Requiere cond. Se recorre de k-1 a 0 porque los sucesores de c tienen número mayor
vector<ll> w(k), dp(k);
for (int u = 0; u < sz(gr); u++) w[scc[u]] += val[u];
for (int c = k - 1; c >= 0; c--) {
  dp[c] = w[c];
  for (int d : cond[c]) dp[c] = max(dp[c], w[c] + dp[d]);
}
ll best = *max_element(dp.begin(), dp.end());
