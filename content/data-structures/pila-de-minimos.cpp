/*
 *Descripción:* Obtiene el mínimo de la pila en $O(1)$ amortizado por operación. Se puede modificar para obtener el máximo cambiando la función
*/
template <typename T>
struct min_stack {
  stack<pair<T, T>> S;
  void push(T x) {
    T new_min = S.empty() ? x : min(x, S.top().second);
    S.push({x, new_min});
  }
  bool empty() { return S.empty(); }
  int size() { return S.size(); }
  void pop() { S.pop(); }
  T top() { return S.top().first; }
  T getMin() { return S.top().second; }
  void swap(min_stack &o) { S.swap(o.S); }
};