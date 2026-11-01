/*
 *Descripción:* Dado un conjunto de $n$ monedas, encuentra todas las sumas de dinero distintas que se pueden formar con dichas monedas.
*/
vector<vector<int>> dp(maxsum, vector<int>(n, 0));
for (int i = 0; i < n; ++i) dp[0][i] = 1;
for (int x = 1; x<maxsum; ++x)
  for (int i = 0; i < n; ++i) {
    if (i) {
        int dpai = 0, dpi = 0;
        if (x - a[i] >= 0) dpai = dp[x-a[i]][i-1];
        dpi = dp[x][i-1];
        dp[x][i] = dpi + dpai;
    } else dp[x][i] = (a[i] == x)? 1 : 0;
  }
set<int> sums;
for (int x = 1; x < maxsum; ++x)
  if (dp[x][n-1] != 0) sums.insert(x);
for (int s : sums) cout << s << ' ';
cout << '\n';
