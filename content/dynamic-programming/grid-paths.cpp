/*
 *Descripción:* Cantidad de caminos en una grilla $n times n$ desde la esquina superior izquierda a la esquina inferior derecha,\
 moviéndose solo hacia abajo o hacia la derecha, evitando obstáculos.
*/
vector<vector<int>> dp(n, vector<int>(n, 0));
dp[0][0] = (A[0][0] != '*');
for (int i = 0; i < n; ++i)
  for (int j = 0; j < n; ++j)
    if (A[i][j] != '*') {
      if (i) dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
      if (j) dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
    }
cout << dp[n-1][n-1] << '\n';
