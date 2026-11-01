/*
 *Descripción:* Mínimo número de monedas para formar un monto $x$ con monedas de valores $c_1, c_2, ..., c_n$.\
 Forma recursiva con memoización.
*/
int f(int monto) {
  if (!monto) return 0;
  int ans = INF;
  if (memo[monto] <= INF) return memo[monto];
  for (int i = 0; i < n; ++i)
    if (monto >= c[i])
      ans = min(ans, 1 + f(monto - c[i]));
  memo[monto] = ans;
  return ans;
}
memo.resize(x+1, INF+1);
int ans = f(x); if (ans == INF) ans = -1;
cout << ans << '\n';
