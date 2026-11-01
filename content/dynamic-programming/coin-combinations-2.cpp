/*
 *Descripción:* Dado un conjunto de monedas y un valor $X$, calcula de cuantas formas distintas se puede formar el valor $X$.\
 Originalmente usaría 2 dimensiones, pero dado que queda `dp[x][i] = dp[x][i-1] + dp[x-c[i]][i]`, solo se necesita la fila anterior y la actual.
 */
vector<ll> dpAnterior(X+1), dpActual(X+1);
dpActual[0] = 1;
for (int i = 0; i < n; ++i) {
  for (int x = 0; x <= X; ++x) {
    if (x==0 && i==0) continue;
    ll dpi = (i>0)
      ? dpAnterior[x]
      : 0;
    ll dpx = (x-c[i] >= 0)
      ? dpActual[x-c[i]]
      : 0;
    dpActual[x] = (dpi + dpx)%mod;
  }
  swap(dpActual, dpAnterior);
} cout << dpAnterior[X] << '\n';
