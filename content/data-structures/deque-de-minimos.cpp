/*
 *Descripción:* Obtiene el mínimo de la deque en $O(1)$ amortizado por operación. Se puede modificar para obtener el máximo cambiando la función
*/
template<typename T>
struct min_deque {
  min_stack<T> l, r, t;
  void rebalance() {
    bool f = false;
    if (r.empty()) {f = true; l.swap(r);}
    int k = sz(r) / 2;
    while (k--) {t.push(r.top()); r.pop();}
    while (!r.empty()) {l.push(r.top()); r.pop();}
    while (!t.empty()) {r.push(t.top()); t.pop();}
    if (f) l.swap(r);
  }
  T getMin() {
    if (l.empty()) return r.getMin();
    if (r.empty()) return l.getMin();
    return min(l.getMin(), r.getMin());
  }
  bool empty() {return l.empty() and r.empty();}
  int size() {return l.size() + r.size();}
  void push_front(T x) {l.push(x);}
  void push_back(T x) {r.push(x);}
  void pop_front() {if (l.empty()) rebalance(); l.pop();}
  void pop_back() {if (r.empty()) rebalance(); r.pop();}
  T front() {if (l.empty()) rebalance(); return l.top();}
  T back() {if (r.empty()) rebalance(); return r.top();}
  void swap(min_deque &x) {l.swap(x.l); r.swap(x.r);}
};
