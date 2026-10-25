/*
 *Descripción:* Cola donde cada push/pop crea una nueva versión sin modificar las anteriores. Los elementos forman un árbol (cada push cuelga un nodo del último de la versión) y el front se busca subiendo con jump pointers. push y pop $O(1)$, front $O(log n)$, memoria $O(1)$ por operación. La versión 0 es la cola vacía
*/
template <typename T>
struct persistent_queue {
  vector<T> val{T()};
  vector<int> par{0}, jmp{0}, dep{0};
  vector<int> tail{0}, fd{1}; // versión: último nodo y profundidad del front
  int new_version(int t, int f) {
    tail.push_back(t); fd.push_back(f);
    return sz(tail) - 1;
  }
  int push(int v, T x) {
    int p = tail[v], j = jmp[p];
    val.push_back(x); par.push_back(p); dep.push_back(dep[p] + 1);
    jmp.push_back(dep[p] - dep[j] == dep[j] - dep[jmp[j]] ? jmp[j] : p);
    return new_version(sz(val) - 1, fd[v]);
  }
  int pop(int v) { return new_version(tail[v], fd[v] + 1); }
  int size(int v) { return dep[tail[v]] - fd[v] + 1; }
  bool empty(int v) { return size(v) == 0; }
  T front(int v) {
    int u = tail[v], d = fd[v];
    while (dep[u] > d) u = dep[jmp[u]] >= d ? jmp[u] : par[u];
    return val[u];
  }
};
