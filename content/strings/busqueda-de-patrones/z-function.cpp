/*
*Descripción:* Calcula un arreglo z donde z[i] es la longitud del prefijo más largo de s que coincide con la substring que comienza en i. Útil para encontrar patrones, períodos, repeticiones y coincidencias de prefijos.

*Complejidad*: (O(n)) en tiempo y (O(n)) en memoria, donde (n) es el largo de la string.


*/

vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n);

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i < r)
            z[i] = min(r - i, z[i - l]);

        while (i + z[i] < n &&
               s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] > r)
            l = i, r = i + z[i];
    }
    return z;
}
