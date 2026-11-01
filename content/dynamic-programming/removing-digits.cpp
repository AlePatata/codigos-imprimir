/*
 *Descripción:* Dado un número $n$, si cada operación le restas uno de sus dígitos, cuál es la minima cantidad de operaciones para reducirlo a 0.
*/
vector<int> dp(n+1, INF);
dp[0] = 0;
for (int i = 1; i <= n; ++i) {
  string digitos = to_string(i);
  int m = INF;
  for (int j = 0; j < sz(digitos); ++j) {
    int dj = digitos[j] - '0';
    m = min(m, dp[i - dj]);
  } dp[i] = 1+m;
} cout << dp[n] << '\n';
