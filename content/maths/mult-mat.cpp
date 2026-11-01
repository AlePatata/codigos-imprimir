/*
 *Descripción:* Multiplica dos matrices de $n*m$ y $m*k$.
 *Complejidad:* $O(n*k*m)$ (peor caso cúbico)
 */

template<class T>
using matrix = vector<vector<T>>;

template<class T>
matrix<T> multmat( matrix<T>& a,
                 matrix<T>& b, T mod) {
    int n = a.size(), k = b.size();
    int m = b[0].size();

    matrix<T> c(n, vector<T>(m, 0));

    for (int i = 0; i < n; i++)
        for (int t = 0; t < k; t++)
            for (int j = 0; j < m; j++)
                c[i][j] = (c[i][j] +
                    (T)a[i][t] * b[t][j]) % mod;

    return c;
}