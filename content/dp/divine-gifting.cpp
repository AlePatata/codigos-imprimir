/*
  *Descripción:* DP ij es el minimo costo de haber entregado los primeros j regalose en i días distintos
*/

long long costo(int regalo, int entrega) {
    long long x = a[entrega] - a[regalo];
    return x * x;
}

int main() {
    int n, k; cin >> n >> k;
    vector<pair<int,int>> v(n);
    for (int t=0; t<n; t++) {
        cin >> v[t].first;
        v[t].second = t;
    }
    sort(v.begin(), v.end());

    a.assign(n, 0);
    for (int t=0; t<n; t++) a[t] = v[t].first;

    vector<vector<long long>> dp(k+1, vector<long long> (n, INF));
    vector<vector<int>> from(k+1, vector<int> (n, -1));

    for (int i=1; i<=k; i++) {
        for (int j=0; j<n; j++) {
            long long c = 0;
            for (int r=j-1; r>=0; r--) {
                c += costo(r+1, j);
                if (dp[i-1][r] + c < dp[i][j]) {
                    dp[i][j] = dp[i-1][r] + c;
                    from[i][j] = r;
                }
            }
            c += costo(0, j);
            if (i == 1) dp[i][j] = c;
        }
    }

    vector<int> ans(n);
    int i = min(k, n), j = n-1;
    while (j >= 0) {
        int r = from[i][j];
        for (int t=r+1; t<=j; t++) ans[v[t].second] = a[j];
        j = r;
        i--;
    }

    for (int t=0; t<n; t++) cout << ans[t] << " ";
    cout << "\n";
}
