/*
  *Descripción:* Encuentra los palíndromos centrados en $i$ en $O(n)$
*/
template<class T>
struct manacher {
  vector<int> odd, even;
  T s; int n;
  manacher(T &s): s(s), n(sz(s)) {
    odd.resize(n);
    even.resize(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
      int k = (i > r) ? 1 : min(odd[l+r-i], r-i+1);
      while (0 <= i-k and i+k < n and s[i-k] == s[i+k]) k++;
      odd[i] = k--;
      if (i+k > r) l = i-k, r = i+k;
    }
    for (int i = 0, l = 0, r = -1; i < n; i++) {
      int k = (i > r) ? 0 : min(even[l + r - i + 1], r - i + 1);
      while (0 <= i - k - 1 and i + k < n && s[i - k - 1] == s[i + k]) k++;
      even[i] = k--;
      if (i + k > r) l = i - k - 1, r = i + k;
    }
  }
  // Retorna el palíndromo más largo centrado en i
  pii get(int i) {
    int o = 2 * odd[i] - 1;   // Centrado normal (largo impar)
    int e = 2 * even[i];      // Centrado a la derecha (largo par)
    if (o >= e)
      return {i - odd[i] + 1, i + odd[i] - 1};
    return {i - even[i], i + even[i] - 1};
  }
};
