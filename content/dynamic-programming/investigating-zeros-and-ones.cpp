/*
 *Descripción:* Dado un arreglo binario, cuenta la cantidad de subarreglos que contienen cantidad impar de unos.
*/
vector<ll> dp1(n), dp0(n,0);
dp1[0] = a[0];
dp0[0] = 1-a[0];
for (int i = 1; i < n; ++i) {
  if (a[i]) {
    dp0[i] = dp1[i-1];
    dp1[i] = 1 + dp0[i-1];
  } else {
    dp0[i] = 1 + dp0[i-1];
    dp1[i] = dp1[i-1];
  }
} ll ans = 0;
for (int i = 0; i < n; ++i)
  ans += dp1[i];
cout << ans << '\n';
