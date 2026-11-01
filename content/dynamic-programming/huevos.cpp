/*
 *Descripción:* Problema de los huevos: con $k$ huevos y un edificio de $n$ pisos, mínima cantidad de lanzamientos para encontrar en el peor caso el piso más alto desde el que un huevo no se rompe.
 $"dp"[m][j]$ = máximo de pisos que se pueden resolver con $m$ lanzamientos y $j$ huevos. Si se lanza un huevo y se rompe, quedan $"dp"[m-1][j-1]$ pisos abajo; si no se rompe, quedan $"dp"[m-1][j]$ pisos arriba.
 *Complejidad:* $O(k dot "ans")$, con $"ans" <= n$ (y $"ans" = O(log n)$ si $k >= log_2 n$).
*/
int huevos(int k, ll n) {
  vector<ll> dp(k+1, 0); // dp[j] con m lanzamientos
  int m = 0;
  while (dp[k] < n) {
    m++;
    for (int j = k; j >= 1; --j)
      dp[j] = dp[j] + dp[j-1] + 1;
  }
  return m;
}
