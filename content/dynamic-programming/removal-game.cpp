/*
 *Descripción:* Dado un conjunto de n números, dos jugadores juegan alternadamente para eliminar un número\
 del inicio o del final del conjunto. Cada jugador intenta maximizar la suma de los números que elimina.\
 Encuentra la suma máxima que el primer jugador puede obtener si ambos juegan de manera óptima.
*/
vector<ll> a(n), p(n+1, 0); // original y prefixsum
vector<vector<ll>> dp(n, vector<ll>(n));
for (int i = 0; i < n; ++i) dp[i][i] = a[i];
for (int l = 1; l <= n; ++l)
  for (int i = 0; i < n; ++i) {
    int j = i + l - 1;
    if (i == j) continue;
    if (j >= n) break;
    ll m = LLONG_MIN;
    if (i+1 < n) m = max(m, a[i] + p[j+1] - p[i+1] - dp[i+1][j]);
    if (0 <= j-1) m = max(m, a[j] + p[j] - p[i] - dp[i][j-1]);
    dp[i][j] = m;
  }
cout << dp[0][n-1] << '\n';
