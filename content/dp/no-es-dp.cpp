/**
 * Just Add ABC / Exact Letter Occurrences (Bitmask Brute Force):
 * Seleccionar un subconjunto de cadenas para maximizar los caracteres que aparecen exactamente k veces en total.
 * - Con n pequeño (n <= 15-20), se prueban los 2^n subconjuntos posibles con una máscara binaria i.
 * - Si el bit j está encendido ((i >> j) & 1), se acumulan las frecuencias de los caracteres del string a[j].
 * - Al terminar cada subconjunto, se cuentan cuántas letras del abecedario alcanzaron frecuencia exactamente k.
 * - La respuesta final es el máximo conteo obtenido entre todas las máscaras.
 * Complejidad: O(2^n * (n * |S| + 26)), ideal para n <= 18.
 */
 
void solve() {
  int n,k; cin>>n>>k;
  vector<string> a(n);
  for (auto &x:a) cin>>x;
  int ansfinal = 0;
  for (int i=0; i<(1<<n); i++){
    vector<int> sum(26);
    for (int j=0;j<n;j++){
      if ((i>>j)&1) {
        for (auto x:a[j]) {
          sum[x-'a']++;
        }
      }
    }
    int ans = 0;
    for (auto x:sum) {
      if (x==k) ans++;
    }
    ansfinal = max(ansfinal,ans);
  }
  cout << ansfinal << '\n';
}