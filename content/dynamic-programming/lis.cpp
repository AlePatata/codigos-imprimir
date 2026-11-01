/*
 *Descripción:* Subsecuencia creciente más larga en $O(n log n)$, permite recuperar la secuencia (retorna sus índices)
*/
template <class I> vector<int> LIS(const vector<I> &S) {
  if (S.empty()) return {};
  vector<int> prev(sz(S));
  vector<pair<I, int>> res;
  for (int i = 0; i < sz(S); i++) {
    auto it = lower_bound(res.begin(), res.end(), pair<I, int>{S[i], i});
    if (it == res.end()) res.emplace_back(), it = res.end() - 1;
    *it = {S[i], i};
    prev[i] = (it == res.begin() ? 0 : (it - 1)->second);
  }
  int L = sz(res), cur = res.back().second;
  vector<int> ans(L);
  while (L--) ans[L] = cur, cur = prev[cur];
  /* Recuperar la secuencia (valores)
  for (int i = 0; i+1 < sz(ans); i++)
    ans[i] = S[ans[i]];
  */
  return ans;
}
