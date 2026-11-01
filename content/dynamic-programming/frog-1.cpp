/*
 *Descripción:* Dado un arreglo de alturas, encuentra el costo minimo\
 para llegar del primer al último índice, donde el costo de saltar\
 de $i$ a $j$ es $|h_i-h_j|$ y solo se puede saltar a $i+1$ o $i+2$.
*/

vector<int> dp(n);
dp[0] = 0;
dp[1] = abs(h[1]-h[0]);
for (int i = 2; i < n; ++i)
  dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]),
              dp[i-2] + abs(h[i] - h[i-2]));
cout << dp[n-1] << '\n';
