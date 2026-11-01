/*
 *Descripción:* Dado un conjunto de monedas y un valor $x$, calcula de cuantas formas se puede formar el valor $x$ usando las monedas dadas (con repeticion).
*/
vector<int> dp(x+1, 0);
dp[0] = 1;
for (int i = 1; i < x+1; ++i)
  for (int k = 0; k < n; ++k)
    if (i-a[k] >= 0)
      dp[i] = (dp[i] + dp[i-a[k]])%mod;
cout << dp[x] << '\n';
