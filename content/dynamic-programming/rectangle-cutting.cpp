/*
 *Descripción:* Dado un rectángulo de tamaño $a times b$, encuentra el número mínimo de cortes necesarios para dividirlo en cuadrados.
*/
vector<vector<int>> dp(a+1, vector<int>(b+1));
for (int i = 0; i <= min(a,b); ++i) dp[i][i] = 0;
for (int i = 1; i <= a; ++i)
  for (int j = 1; j <= b; ++j) {
    if (i==j) continue;
    int m = INF;
    for (int k = 1; k < i; ++k)
      m = min(m, dp[i-k][j] + dp[k][j]);
    for (int k = 1; k < j; ++k)
      m = min(m, dp[i][j-k] + dp[i][k]);
    dp[i][j] = 1 + m;
  }
cout << dp[a][b] << '\n';
