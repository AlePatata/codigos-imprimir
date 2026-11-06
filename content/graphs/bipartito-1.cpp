/**
 * Bipartite Check (2-Coloring): Determinar si un grafo es bipartito (sin ciclos impares).
 * Coloreado en 2 colores ({0, 1}) mediante BFS componente por componente:
 * - Se inicializan todos los nodos con color -1 (no visitado).
 * - Para cada componente conexa no visitada, se asigna color 0 a la raíz y se expande en anchura.
 * - Cada vecino v de u debe tener el color opuesto: color[v] = color[u] ^ 1.
 * - Si un vecino ya fue visitado y comparte el mismo color (color[v] == color[u]),
 *   existe un ciclo de longitud impar y el grafo NO es bipartito.
 * Complejidad: O(V + E) tiempo y O(V) memoria.
 */
 
bool isBipartite(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n, -1);

    for (int s = 0; s < n; s++) {
        if (color[s] != -1) continue;

        queue<int> q;
        color[s] = 0;
        q.push(s);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}