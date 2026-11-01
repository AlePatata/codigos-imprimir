Todas reciben un rango `[first, last)`, normalmente `v.begin(), v.end()`. Abajo se abrevia como `all(v)` usando `#define all(v) v.begin(), v.end()`.

#text(size: 8pt)[*Permutaciones*]
- `next_permutation(all(v))` reordena `v` a la siguiente permutación lexicográfica; retorna `false` si ya era la última (y la deja en la primera). `prev_permutation` hace lo inverso.
- Para recorrer *todas* las permutaciones hay que partir con `v` ordenado. Maneja repetidos (no repite permutaciones). Costo $O(n dot n!)$, sirve hasta $n approx 10$.
```cpp
sort(all(v));
do {
  // usar v
} while (next_permutation(all(v)));
```

#text(size: 8pt)[*Ordenar y reordenar*]
- `sort(all(v), greater<>())` orden descendente; `stable_sort` mantiene el orden de los iguales.
- `reverse(all(v))`, `rotate(v.begin(), v.begin() + k, v.end())` rota a la izquierda en `k`.
- `nth_element(v.begin(), v.begin() + k, v.end())` deja en `v[k]` el elemento que estaría ahí si estuviera ordenado, menores a la izquierda y mayores a la derecha, en $O(n)$.
- `is_sorted(all(v))`, `shuffle(all(v), rng)`.

#text(size: 8pt)[*Eliminar repetidos (compresión de coordenadas)*]
```cpp
sort(all(v));
v.erase(unique(all(v)), v.end());
// índice comprimido de x:
int id = lower_bound(all(v), x) - v.begin();
```

#text(size: 8pt)[*Buscar y contar*]
- `*min_element(all(v))`, `*max_element(all(v))`; posición: `max_element(all(v)) - v.begin()`.
- `auto [mn, mx] = minmax_element(all(v));` (son iteradores).
- `count(all(v), x)`, `find(all(v), x)` (retorna `v.end()` si no está).
- En rangos ordenados: `binary_search(all(v), x)` retorna `bool`; `equal_range(all(v), x)` retorna el par `(lower_bound, upper_bound)`.
- `all_of`, `any_of`, `none_of(all(v), [](int x) { return x > 0; })`.

#text(size: 8pt)[*Numéricas* (`<numeric>`)]
- `accumulate(all(v), 0LL)` suma; *ojo*: el tipo del resultado es el del valor inicial, con `0` se desborda en `int`.
- `iota(all(v), 0)` llena con `0, 1, 2, ...` (útil para ordenar índices).
- `partial_sum(all(v), p.begin())` sumas prefijas; `__gcd(a, b)`, `gcd(a, b)`, `lcm(a, b)`.
```cpp
vector<int> idx(n);
iota(all(idx), 0);
sort(all(idx), [&](int i, int j) { return a[i] < a[j]; });
```

#text(size: 8pt)[*Vectores*]
- `vector<vector<int>> m(n, vector<int>(k, -1))` matriz $n times k$ inicializada en `-1`.
- `v.assign(n, x)` reinicia con `n` copias de `x`; `fill(all(v), x)` sin cambiar el tamaño.
- `v.resize(n)`, `v.clear()`, `v.back()`, `v.pop_back()`, `v.emplace_back(a, b)`.
- `v.insert(v.begin() + i, x)`, `v.erase(v.begin() + i)`: son $O(n)$.
- `v.insert(v.end(), all(w))` concatena `w` al final de `v`.
- Los vectores se comparan lexicográficamente con `<`, `==`, etc., así que sirven como llaves de `map`/`set`.

#text(size: 8pt)[*Strings*]
- Número a string: `to_string(x)` (sirve para `int`, `ll`, `double`).
- String a número: `stoi(s)`, `stoll(s)`, `stod(s)`. En otra base: `stoll(s, nullptr, 2)` lee `s` en binario.
- A binario con largo fijo: `bitset<32>(x).to_string()`.
- Dígito a número y al revés: `c - '0'`, `char('0' + d)`; letra a índice: `c - 'a'`, `char('a' + i)`.
- `isdigit(c)`, `isalpha(c)`, `islower(c)`, `isupper(c)`, `tolower(c)`, `toupper(c)`.
- `string(n, c)` string con `n` copias de `c`; `s += c` o `s.push_back(c)` agregan un char.
- `s.substr(i, len)` desde `i` con largo `len` (sin `len` hasta el final), es $O("len")$.
- `s.find(t)` posición de la primera aparición de `t`, o `string::npos` si no está; `s.find(t, i)` busca desde `i`.
- `reverse(all(s))`, `sort(all(s))` y el resto de funciones de arriba también sirven con strings.
```cpp
// sumar los dígitos de un número
string s = to_string(n);
int suma = 0;
for (char c : s) suma += c - '0';
// pasar a mayúsculas
for (char &c : s) c = toupper(c);
```
