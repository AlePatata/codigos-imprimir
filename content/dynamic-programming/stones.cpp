/*
 *Descripción:* Dado un conjunto con inicialmente $n$ piedras y $k$ valores, dos jugadores juegan alternadamente para\
 elegir un valor $A_i$ tal que $A_i <=$ piedras actuales y quitar $A_i$ piedras. El juego termina cuando no hay piedras\
 restantes, y el jugador que no puede hacer un movimiento pierde. Encuentra la cantidad máxima de piedras que el\
 primer jugador puede obtener si ambos juegan de manera óptima.
*/
vector<ll> dp(n+1);
dp[0] = 0;
for (int i = 0; i < k; ++i) cin >> a[i];
for (int x = 1; x < n+1; ++x) {
  ll m = 0;
  for (int j = 0; j < k; ++j) {
    if (x-a[j] == 0) {m = a[j];}
    else {
      ll rest = x-a[j];
      if (rest >= 0) m = max (m, a[j] + (rest - dp[rest]) );
    }
  } dp[x] = m;
} cout << dp[n] << '\n';
