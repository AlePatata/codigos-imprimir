/*
 *Descripción:* Obtiene la descomposición prima de un número $n$.
*/
vector<pair<ll, int>> desc; // {primo, potencia}
ll m = n;
for (ll i = 2; i*i <= m; ++i) {
  int potencia = 0;
  while (m%i == 0) {
    potencia++;
    m /= i;
  }
  if (potencia > 0) desc.push_back({i, potencia});
}
if (m != 1) desc.push_back({m, 1});
