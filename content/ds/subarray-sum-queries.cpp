/*
 SEGMENT TREE
 CSES Subarray Sum Queries: Máximo subsegmento contiguo (Kadane) con updates puntuales.
 Cada nodo del Segment Tree guarda [sum, pref_max, suf_max, ans_max]:
 - sum: suma total del rango (a[0] + b[0]).
 - pref_max: max(izq.pref, izq.sum + der.pref).
 - suf_max: max(der.suf, der.sum + izq.suf).
 - ans_max: max(izq.ans, der.ans, izq.suf + der.pref) (permite subarray vacío -> max(0, x)).
 Complejidad: O(n) build, O(log n) por update y query global.
*/

pii merge(pii a, pii b){
  pii ans = {0,0,0,0};
  ans[0] = a[0] + b[0];
  ans[1] = max(a[1], a[0] + b[1]);
  ans[2] = max(b[2], b[0] + a[2]);
  ans[3] = max(b[3], max(a[3], a[2]+b[1]));
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,q; cin>>n>>q;
  vector<pii> a(n);
  for (int i=0;i<n;i++) {
    ll x; cin>>x;
    a[i] = {x, max(0LL,x), max(0LL,x), max(0LL,x)};
  }
  segment_tree<pii, merge> st(a);
  while(q--){
    int k; ll x; cin>>k>>x;
    st.update(k-1,{x, max(0LL, x), max(0LL, x), max(0LL, x)});
    cout << st.query(0,n-1)[3] << '\n';
  }
  return 0;
  cout << "life update: we are so back\n";
}
