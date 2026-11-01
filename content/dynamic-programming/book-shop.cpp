/*
 *Descripción:* Encuentra la cantidad máxima de páginas leídas teniendo un presupuesto $x$ dado $n$ libros,\
 cada uno con un costo $h_i$ y $s_i$ páginas.
*/
vector<vector<int>> dp(2, vector<int>(x+1, 0)); int ans = 0;
for (int i = 1; i < n+1; ++i)
  for (int j = 1; j < x+1; ++j) {
    int iprev = (i-1)%2, iact = i%2;
    dp[iact][j] = dp[iprev][j];
    if (j - h[i-1] >= 0)
      dp[iact][j] = max(dp[iact][j], s[i-1] + dp[iprev][j - h[i-1]]);
    if (i == n) ans = max(ans, dp[iact][j]);
  }
cout << ans << '\n';
