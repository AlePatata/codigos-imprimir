/*
 *Descripción:* Matching rápido de bipartitos. $g$ es la lista de vecinos de la partición izq y $r$ es un vector inicializado en -1 de la partición der. Retorna el tamaño del maatching; $r[i]$ guarda el nodo izq asignado al der $i$ (-1 si libre).
 *Complejidad:* $O(sqrt{V} E)$
 *Uso:* vector<int> r(m,-1); hopcroftKarp(g,r)
 Devuelve un vector r con sus parejas (se pasa por ref) :D
 */

int hopcroftKarp(vec<vi>& g, vi& r) {
	int n = sz(g), res = 0;
	vi l(n, -1), q(n), d(n);
	auto dfs = [&](auto f, int u) -> bool {
		int t = exchange(d[u], 0) + 1;
		for (int v : g[u])
			if (r[v] == -1 || (d[r[v]] == t && f(f, r[v])))
				return l[u] = v, r[v] = u, 1;
		return 0;
	};
	for (int t = 0, f = 0;; t = f = 0, d.assign(n, 0)) {
		rep(i,0,n) if (l[i] == -1) q[t++] = i, d[i] = 1;
		rep(i,0,t) for (int v : g[q[i]]) {
			if (r[v] == -1) f = 1;
			else if (!d[r[v]]) d[r[v]] = d[q[i]] + 1, q[t++] = r[v];
		}
		if (!f) return res;
		rep(i,0,n) if (l[i] == -1) res += dfs(dfs, i);
	}
}