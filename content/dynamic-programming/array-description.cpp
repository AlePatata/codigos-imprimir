/*
 *Descripción:* Dado un arreglo (de $n$ elementos con valores entre 1 y $m$) con ciertos elementos borrados (representados con 0),\
 encuentra la cantidad de arreglos que se pueden formar cumpliendo que la diferencia entre elementos consecutivos debe ser a lo mas 1.
*/
vector<vector<int>> dp(n, vector<int>(m+1, 0));
if (x[0] == 0)
  for (int j = 1; j < m+1; ++j)
    dp[0][j] = 1;
else dp[0][x[0]] = 1;

for (int i = 1; i < n; ++i)
  for (int j = 1; j < m+1; ++j) // por posibles valores
    if (x[i] == 0 || j == x[i]) {
      ll d1 = (0 <= j-1)
        ? dp[i-1][j-1]
        : 0,
         d2 = (j+1 <= m)
        ? dp[i-1][j+1]
        : 0;
      dp[i][j] = ((dp[i-1][j] + d1)%mod + d2)%mod;
    }
ll sol = 0;
for (int j = 1; j < m+1; ++j)
  sol = (sol + dp[n-1][j])%mod;
cout << sol << '\n';
