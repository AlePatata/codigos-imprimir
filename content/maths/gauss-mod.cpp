/*
 *Descripción:* Resuelve sistemas de ecuaciones lineales módulo un número primo \(p\), utilizando Gauss-Jordan e inversos modulares.
 *Requiere:* binpow con multiplicaciones modulares seguras. T debe ser un tipo entero.
 *Complejidad:* \(O(n^3+n\log p)\) para una matriz cuadrada de \(n\) incógnitas.
 */

 template<class T>
int gaussmod(vector<vector<T>> a, vector<T>& x, T p) {
    int n = a.size(), m = a[0].size() - 1;
    vector<int> where(m, -1);
    int row = 0;

    // Normalizar modulo p
    for (auto &v : a)
        for (T &z : v) {
            z %= p;
            if (z < 0) z += p;
        }

    for (int col = 0; col < m && row < n; col++) {
        // Buscar pivote no nulo
        int sel = row;
        while (sel < n && a[sel][col] == 0)
            sel++;

        if (sel == n) continue;

        swap(a[sel], a[row]);
        where[col] = row;

        // Normalizar pivote con inverso modular
        T inv = binpow(a[row][col], (long long)p - 2, p);

        for (int j = col; j <= m; j++)
            a[row][j] = (__int128)a[row][j] * inv % p;

        // Eliminar en las otras filas
        for (int i = 0; i < n; i++) {
            if (i == row) continue;
            T factor = a[i][col];

            for (int j = col; j <= m; j++) {
                __int128 z = ((__int128)a[i][j]
                    - (__int128)factor * a[row][j]) % p;

                if (z < 0) z += p;
                a[i][j] = (T)z;
            }
        }
        row++;
    }

    // Comprobar contradicciones
    for (int i = row; i < n; i++)
        if (a[i][m] != 0) return -1;

    // Recuperar solucion
    x.assign(m, 0);
    for (int col = 0; col < m; col++)
        if (where[col] != -1)
            x[col] = a[where[col]][m];

    return (row == m ? 1 : 0);
}
