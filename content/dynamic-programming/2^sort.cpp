/*
 *Descripción:* Encuentra la cantidad de subarreglos de largo $k+1$\
 (continuos) donde cada elemento es al menos el doble del anterior.
*/

int n, k; cin >> n >> k;
vector<ll> a(n);
vector<int> p(n, 0), dp(n+1, 0); // largos max. p/c posicion
for (int i = 0; i < n; ++i) {
  cin >> a[i];
  if (i) p[i] = (a[i-1] < a[i]*2);
} int c = 0;
for (int i = n-1; i > 0; --i)
  if (p[i]) dp[i-1] = 1 + dp[i];
for (int i = 0; i < n; ++i)
  if (dp[i] >= k) c++;
cout << c << '\n';
