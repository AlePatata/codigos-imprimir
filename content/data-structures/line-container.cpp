/*
 *Descripción:* Contenedor de rectas para la optimización convex hull trick en DP
*/
// inserta dinámicamente rectas `a*x + b` y consulta el máximo
// en cualquier x, todas las operaciones son O(log N)
struct Line {
  mutable ll a, b, c;
  bool operator<(Line r) const { return a < r.a; }
  bool operator<(ll x) const { return c < x; }
};
struct LineContainer : multiset<Line, less<>> {
  ll div(ll a, ll b) {
    return a / b - ((a ^ b) < 0 && a % b);
  }
  bool isect(iterator x, iterator y) {
    if (y == end()) return x->c = LLONG_MAX, 0;
    if (x->a == y->a) x->c = x->b > y->b ? LLONG_MAX : -LLONG_MAX;
    else x->c = div(y->b - x->b, x->a - y->a);
    return x->c >= y->c;
  }
  void add(ll a, ll b) {
    // a *= -1, b *= -1 // para mínimo
    auto z = insert({a, b, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->c >= y->c) isect(x, erase(y));
  }
  ll query(ll x) {
    if (empty()) return -LLONG_MAX; // LLONG_MAX para mínimo
    auto l = *lower_bound(x);
    return l.a * x + l.b;
    // return -l.a * x - l.b; // para mínimo
  }
};
