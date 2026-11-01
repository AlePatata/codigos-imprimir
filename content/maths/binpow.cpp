/*
 *Descripción:* Calcula $a^b mod m$
 *Complejidad:* $O(log b)$
 */
template<class T>
T binpow(T a, int b, T m) {
  T ans = 1;
  a %= m;
  while (b > 0) {
    if (b & 1) ans = (ans * 1LL * a) % m;
    a = (a * 1LL * a) % m;
    b >>= 1;
  }
  return ans;
}
