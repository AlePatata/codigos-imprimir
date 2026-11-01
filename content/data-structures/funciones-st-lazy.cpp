/* 
Distintas funciones de merge, pushUpd, applyUpd para stl
*/

// Suma con actualizaciones en rango
ll merge(ll a, ll b) {
  return a+b;
}

void pushUpd(ll& a, ll& b, int pl, int pr, int cl, int cr){
  b+=a;
}

void applyUpd(ll& a, ll& b, int l, int r) {
  b+=(r-l+1)*a; // debe aumentar a*tamaño-segmento
}

// Suma con asignaciones en el rango
ll merge(ll a, ll b) {
  return a+b;
}

void pushUpd(ll& a, ll& b, int pl, int pr, int cl, int cr){
  b=a;
}

void applyUpd(ll& a, ll& b, int l, int r) {
  b=a*(r-l+1);
}

// Mínimo con actualizaciones de suma en rango
ll merge(ll a, ll b) {
  return min(a,b);
}

void pushUpd(ll& a, ll& b, int pl, int pr, int cl, int cr){
  b+=a;
}

void applyUpd(ll& a, ll& b, int l, int r) {
  b+=a; // el mínimo aumenta en a simplemente
}
