/*
 *Descripción:* Dado un conjunto de $n$ objetos con peso $w_i$ y valor $v_i$, y una capacidad $W$,\
 calcula el valor máximo que se puede obtener sin superar la capacidad $W$.
*/
vector<vector<ll>> dp(n+1, vector<ll>(W+1,0));
for (int i = 0; i < n; ++i)
  for (int j = 1; j <= W; ++j) {
    ll imax;
    if (j-w[i] >= 0)
      imax = max( v[i] + dp[i][j-w[i]] , dp[i][j] );
    else
      imax = dp[i][j];
    dp[i+1][j] = imax;
  }
cout << dp[n][W] << '\n';
