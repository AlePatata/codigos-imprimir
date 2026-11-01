/*
 *Descripción:* Resuelve sistemas de ecuaciones lineales reales mediante Gauss-Jordan con pivoteo parcial.
 *Requiere:* T = double o long double.
 *Complejidad:* \(O(nm\min(n,m))\); para matrices cuadradas, \(O(n^3)\).
 *Retorna*:
 -1: no existe solución.
 0: existen infinitas soluciones.
 1: existe solución única.
 El vector x guarda la solución única o una solución particular, fijando las variables libres en cero.
 */

template<class T>
int gauss(vector<vector<T>> a, vector<T>& x,
          T EPS = (T)1e-10) {

    int n = a.size(), m = a[0].size() - 1;
    vector<int> where(m, -1);
    int row = 0;

    for (int col = 0; col < m && row < n; col++) {
        // Buscar pivote
        int sel = row;
        for (int i = row + 1; i < n; i++)
            if (abs(a[i][col]) > abs(a[sel][col]))
                sel = i;

        if (abs(a[sel][col]) <= EPS) continue;

        swap(a[sel], a[row]);
        where[col] = row;

        // Normalizar pivote
        T pivot = a[row][col];
        for (int j = col; j <= m; j++)
            a[row][j] /= pivot;

        // Eliminar en las otras filas
        for (int i = 0; i < n; i++) {
            if (i == row) continue;
            T factor = a[i][col];

            for (int j = col; j <= m; j++)
                a[i][j] -= factor * a[row][j];
        }
        row++;
    }

    // Comprobar contradicciones
    for (int i = row; i < n; i++)
        if (abs(a[i][m]) > EPS)
            return -1;

    // Recuperar solucion
    x.assign(m, 0);
    for (int col = 0; col < m; col++)
        if (where[col] != -1)
            x[col] = a[where[col]][m];

    return row == m ? 1 : 0;
}