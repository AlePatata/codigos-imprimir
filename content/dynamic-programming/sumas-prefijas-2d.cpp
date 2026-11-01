/*
 *Descripción:* Suma de cualquier submatriz (área) en $O(1)$ tras precálculo $O(n m)$.
 - `p[i][j]` = suma del rectángulo desde `(0, 0)` hasta `(i-1, j-1)`, 1-indexado con fila/columna 0 en cero
 - `query(r1, c1, r2, c2)` suma de filas `[r1, r2]` y columnas `[c1, c2]`, inclusivo y 0-indexado
*/
template <class T> struct prefix_sum_2d {
  vector<vector<T>> p;
  prefix_sum_2d(const vector<vector<T>> &a) {
    int n = sz(a), m = sz(a[0]);
    p.assign(n + 1, vector<T>(m + 1, 0));
    // arriba + izquierda - esquina (contada dos veces) + celda
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        p[i + 1][j + 1] = p[i][j + 1] + p[i + 1][j] - p[i][j] + a[i][j];
  }
  T query(int r1, int c1, int r2, int c2) {
    // total - arriba - izquierda + esquina (restada dos veces)
    return p[r2 + 1][c2 + 1] - p[r1][c2 + 1] - p[r2 + 1][c1] + p[r1][c1];
  }
};
