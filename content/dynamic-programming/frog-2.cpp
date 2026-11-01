/*
 *Descripción:* Dado un arreglo de alturas, encuentra el costo minimo\
 para llegar del primer al último índice, donde el costo de saltar\
 de $i$ a $j$ es $|h_i-h_j|$ y solo se puede saltar a $i+1, i+2, ..., i+k$.
*/
vector<ll> dp(n);
for (int i = 0; i < n; ++i)
  cin >> h[i];
dp[0] = 0;
for (int i = 1; i < n; ++i) {
  ll best = INF;
  for (int j = max(i-k,0); j < i; ++j) {
    best = min(best, dp[j] + abs(h[j]-h[i]));
  }
  dp[i] = best;
}
cout << dp[n-1] << '\n';
