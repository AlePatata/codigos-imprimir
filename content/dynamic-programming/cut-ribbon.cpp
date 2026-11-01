/*
 *Descripción:* Dado un lazo de largo $n$, y tres posibles largos de cortes $a$, $b$ y $c$,\
 encuentra la máxima cantidad de piezas en las que se puede cortar el lazo, de forma recursiva con memoización.
*/
int dp(int i) {
  if (i == 0) return 0;
  if (memo[i] != -INF-1) return memo[i];
  int dpa = -INF, dpb = -INF, dpc = -INF;
  if (i-a >= 0)
    dpa = dp(i-a);
  if (i-b >= 0)
    dpb = dp(i-b);
  if (i-c >= 0)
    dpc = dp(i-c);
  return memo[i] = 1 + max(dpa, max(dpb, dpc));
}

cout << dp(n) << '\n';

