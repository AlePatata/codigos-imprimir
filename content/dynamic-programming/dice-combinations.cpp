/*
 *Descripción:* Cantidad de formas de arrojar un dado para obtener una suma $n$ tirándolo 1 o más veces.
*/
vector<ll> dp(n+1);
dp[0]=1;
for (int i = 1; i<=n; ++i)
  for(int k = 1; k <= 6; ++k)
    if (i-k >= 0)
      dp[i] = (dp[i] + dp[i-k])%mod;
cout << dp[n] << '\n';
