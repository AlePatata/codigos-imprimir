/*
 *Descripción:* Mínima cantidad de operaciones para transformar un string $s$ en otro string $t$.
*/
int n = sz(s), m = sz(t);
vector<vector<int>> dp(n+1, vector<int>(m+1, INF));
for (int i = 1; i < n+1; ++i) dp[i][0] = i;
for (int i = 1; i < m+1; ++i) dp[0][i] = i;
dp[0][0] = 0;
for (int i = 1; i < n+1; ++i)
  for (int j = 1; j < m+1; ++j) {
    if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
    dp[i][j] = min (1 + dp[i][j-1],
                 min (1 + dp[i-1][j],
                   min (1 + dp[i-1][j-1], dp[i][j])));
  }
cout << dp[n][m] << '\n';
