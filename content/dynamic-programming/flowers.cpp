/*
 *Descripción:* Cantidad de formas de comer entre $l$ y $r$ flores\\
 dado que solo come flores W (de tipo W) en grupos de $k$
*/
vector<ll> dp(r+1);
dp[0] = 1;
for (int i = 1; i <= r; ++i) {
  dp[i] = dp[i-1];
  if (i-k >= 0) dp[i] = (dp[i] + dp[i-k])%mod;
}
for (int i = 1; i <= r; ++i)
  dp[i] = (dp[i] + dp[i-1])%mod;
cout << (dp[r] - dp[l-1] + mod) % mod << '\n';
