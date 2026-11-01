/*
 *Descripción:* Exponenciación binaria de matrices.
 *Complejidad:* $O(n^2*log(b))$
 *Necesario:* mult-mat :D
 */

template<class T>
matrix<T> binpowmat(matrix<T> a,
                 long long b, T mod) {
    int n = a.size();

    matrix<T> ans(n, vector<T>(n, 0));

    // Matriz identidad
    for (int i = 0; i < n; i++)
        ans[i][i] = 1 % mod;

    // Normalizar entradas
    for (auto &fila : a)
        for (T &x : fila) {
            x %= mod;
            if (x < 0) x += mod;
        }

    while (b > 0) {
        if (b & 1)
            ans = multmat(ans, a, mod);

        a = multmat(a, a, mod);
        b >>= 1;
    }

    return ans;
}