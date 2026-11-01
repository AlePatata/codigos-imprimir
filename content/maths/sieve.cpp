/*
 *Descripción:* Calcula el factor primo más pequeño de cada entero entre 2 y \(n\).
 *Complejidad:* \(O(n\log\log n)\) de construcción y \(O(n)\) memoria.
 Calcula el factor primo más pequeño de cada entero entre 2 y \(n\).
 */

template<class T>
vector<T> sieve_spf(T n) {
    vector<T> spf(n + 1);
    // for normal de 0,1,2,3...
    iota(spf.begin(), spf.end(), 0);

    for (T i = 2; i <= n / i; i++) {
        if (spf[i] == i) {
            for (T j = i*i; j <= n; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
    return spf;
} 