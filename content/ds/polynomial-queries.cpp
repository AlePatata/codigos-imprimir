/*
 STL
 Suma pogresión aritmética en rangos
 Se descompone en la posición i como a_i = b+i*m
 - lazy guarda {b,m} offset global y endiente para combinar con la suma directa
 - update se añade de esa forma para que en i = 1 empiece en 1
 - applyUpd suma todo en el rango con la fórmula de la PA.
*/

ll merge(ll a, ll b) {
  return a+b;
}
 
void pushUpd(pii &a, pii &b, int pl, int pr, int cl, int cr){
  b[0] += a[0];
  b[1] += a[1];
}
 
void applyUpd(pii &a, ll &v, int l, int r){
  ll len = (r-l+1);
  v+= (a[0]+(ll)l*a[1])*len + a[1]*(len*(len-1))/2;
}
 
void solve() {
  int n, q; cin>>n>>q;
  vector<ll> a(n);
  for (auto &x:a) cin>>x;
  segment_tree_lazy<ll, pii, merge, pushUpd, applyUpd> st(a);
  while(q--){
    int t, l, r; cin>>t>>l>>r; l--; r--;
    if (t==1) {
      st.update(l,r, {1-(ll)l,1});
    } else {
      cout << st.query(l,r) << '\n';
    }
  }
}