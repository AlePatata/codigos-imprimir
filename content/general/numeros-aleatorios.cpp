/*
  *Descripción:* RNG con C++, preferir sobre RNG de C, predecible e inseguro.\
  Retorna en $[l, r]$. Reemplazar `_int_` por `_real_` para punto flotante en $[l, r)$.
*/
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rnd(ll l, ll r) {
  return uniform_int_distribution<ll>(l, r)(rng);
}

