/*
 *Descripción:* DFS sin recursión usando un stack explícito, evita stack overflow en grafos muy profundos.
 *Complejidad:* $O(V + E)$
*/
vector<vector<int>> gr;
vector<bool> vis;

void dfs(int s) {
  stack<pii> st;
  vis[s] = true;
  st.push({s, 0}); // {nodo, índice del próximo vecino}
  while (!st.empty()) {
    auto &[v, i] = st.top();
    if (i < sz(gr[v])) {
      int u = gr[v][i++];
      if (vis[u]) continue;
      vis[u] = true;
      st.push({u, 0});
    } else st.pop();
  }
}
